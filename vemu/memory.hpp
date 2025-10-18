#pragma once
#include "common.hpp"

class Memory
{
  public:
    Memory();
    uint32_t load_word(uint32_t addr);
    void store_word(uint32_t addr, uint32_t value);
    void load_hex(const std::string &path);

  private:
    std::vector<uint8_t> mem;
};
