#include "decoder.hpp"

DecodedInstr decode(uint32_t inst)
{
    DecodedInstr d{};
    d.opcode = inst & 0x7F;
    d.rd = (inst >> 7) & 0x1F;
    d.funct3 = (inst >> 12) & 0x7;
    d.rs1 = (inst >> 15) & 0x1F;
    d.rs2 = (inst >> 20) & 0x1F;
    d.funct7 = (inst >> 25) & 0x7F;

    switch (d.opcode)
    {
    case OP_OP_IMM:
        d.imm = (int32_t)inst >> 20;
        break;
    case OP_LOAD:
        d.imm = (int32_t)inst >> 20;
        break;
    case OP_STORE:
    {
        int32_t imm11_5 = (inst >> 25) & 0x7F;
        int32_t imm4_0 = (inst >> 7) & 0x1F;
        d.imm = (imm11_5 << 5) | imm4_0;
        break;
    }
    case OP_BRANCH:
    {
        int32_t imm12 = (inst >> 31) & 0x1;
        int32_t imm10_5 = (inst >> 25) & 0x3F;
        int32_t imm4_1 = (inst >> 8) & 0xF;
        int32_t imm11 = (inst >> 7) & 0x1;
        d.imm = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1);
        if (imm12)
            d.imm |= 0xFFFFE000;
        break;
    }
    default:
        d.imm = 0;
    }
    return d;
}
