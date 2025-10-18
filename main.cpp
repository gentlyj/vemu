#include "vemu/cpu.hpp"
#include <stdio.h>

int main()
{
    printf("===vemu start===\n");
    CPU cpu;
    cpu.load_program("../test/fib.hex");
    cpu.run();
    return 0;
}
