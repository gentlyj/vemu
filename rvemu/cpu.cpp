#include "cpu.hpp"

CPU::CPU() : pc(0) {
    memset(regs, 0, sizeof(regs));
}

void CPU::load_program(const std::string& hex_path) {
    mem.load_hex(hex_path);
}

void CPU::run() {
    for (int i = 0; i < 50; ++i) {
        uint32_t inst = mem.load_word(pc);
        DecodedInstr d = decode(inst);
        printf("PC=0x%08X INST=0x%08X\n", pc, inst);
        execute(d, inst);
        regs[0] = 0;
    }
}

void CPU::execute(const DecodedInstr& d, uint32_t inst) {
    switch (d.opcode) {
    case OP_OP_IMM:
        if (d.funct3 == 0x0) regs[d.rd] = regs[d.rs1] + d.imm;
        pc += 4;
        break;
    case OP_OP:
        if (d.funct3 == 0x0 && d.funct7 == 0x00)
            regs[d.rd] = regs[d.rs1] + regs[d.rs2];
        pc += 4;
        break;
    case OP_LOAD:
        if (d.funct3 == 0x2)
            regs[d.rd] = mem.load_word(regs[d.rs1] + d.imm);
        pc += 4;
        break;
    case OP_STORE:
        if (d.funct3 == 0x2)
            mem.store_word(regs[d.rs1] + d.imm, regs[d.rs2]);
        pc += 4;
        break;
    case OP_BRANCH:
        if (d.funct3 == 0x0)
            pc += (regs[d.rs1] == regs[d.rs2]) ? d.imm : 4;
        else
            pc += 4;
        break;
    default:
        printf("Unknown opcode 0x%02X at PC=0x%08X\n", d.opcode, pc);
        exit(1);
    }
}
