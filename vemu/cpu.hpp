#pragma once
#include "common.hpp"
#include "decoder.hpp"
#include "memory.hpp"

class CPU
{
  public:
    CPU();
    void run();
    void load_program(const std::string &hex_path);

  private:
    void execute(const DecodedInstr &d, uint32_t inst);

    uint32_t regs[32];
    uint32_t pc;
    Memory mem;
};
