#include "vemu/cpu.hpp"

int main() {
    CPU cpu;
    cpu.load_program("../test/fib.hex");
    cpu.run();
    return 0;
}
