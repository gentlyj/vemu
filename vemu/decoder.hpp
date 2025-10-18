#pragma once
#include "common.hpp"

enum Opcode
{
    OP_OP_IMM = 0x13,
    OP_OP = 0x33,
    OP_BRANCH = 0x63,
    OP_LOAD = 0x03,
    OP_STORE = 0x23,
};

struct DecodedInstr
{
    uint32_t opcode;
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;
    int32_t imm;
    uint32_t funct3;
    uint32_t funct7;
};

DecodedInstr decode(uint32_t inst);
