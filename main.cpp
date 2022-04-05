

#include <iostream>
#include <stdio.h>
#include "./cpu/machine_code.hpp"
#include "./cpu/cpu.hpp"

int main(void)
{
    MachineCode* code;

    uint64_t* test = new uint64_t;
    code = (MachineCode*)test;

    *test = 0x123456789abcdef1;

    printf("test: 0x%lx\n", *test);

    printf("Machine code test:\n");
    printf("opcode: 0x%x\n", code->opcode);
    printf("d: 0x%x\n", code->d);
    printf("w: 0x%x\n", code->w);

    printf("mod: 0x%x\n", code->mod);
    printf("reg: 0x%x\n", code->reg);
    printf("rm: 0x%x\n", code->rm);
    

    printf("disp_low: 0x%x\n", code->disp_low);
    printf("disp_high: 0x%x\n", code->disp_high);

    printf("data_low2: 0x%x\n", code->data_low2);
    printf("data_high2: 0x%x\n", code->data_high2);
    
}







