#include "memory.hpp"
#include <fstream>
#include <sstream>

Memory::Memory() {
    mem.resize(MEM_SIZE, 0);
}

uint32_t Memory::load_word(uint32_t addr) {
    if (addr + 3 >= MEM_SIZE) {
        printf("Memory read out of range: 0x%08X\n", addr);
        exit(1);
    }
    return mem[addr] | (mem[addr+1] << 8) | (mem[addr+2] << 16) | (mem[addr+3] << 24);
}

void Memory::store_word(uint32_t addr, uint32_t value) {
    if (addr + 3 >= MEM_SIZE) {
        printf("Memory write out of range: 0x%08X\n", addr);
        exit(1);
    }
    mem[addr]   = value & 0xFF;
    mem[addr+1] = (value >> 8) & 0xFF;
    mem[addr+2] = (value >> 16) & 0xFF;
    mem[addr+3] = (value >> 24) & 0xFF;
}

void Memory::load_hex(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        printf("Failed to open %s\n", path.c_str());
        exit(1);
    }

    std::string line;
    uint32_t addr = 0;
    while (std::getline(file, line)) {
        uint32_t word = std::stoul(line, nullptr, 16);
        store_word(addr, word);
        addr += 4;
    }
}
