
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cpu/cpu.cpp>
#include <cpu/machine_code.hpp>


int main(int argc, char* argv[])
{

    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " file" << std::endl;
        exit(1);
    }

    std::fstream file;

    file.open(argv[1], std::ios::in | std::ios::binary);


    file.read((char*)&ram[0x7c00], 512);

    printf("test: 0x%x\n", ram[0x7c00]);

    cpu.ax = 10;
    cpu.dx = 20;

    cpu.machine_code->reg = 0;
    cpu.machine_code->rm = 1;
    cpu.machine_code->d = 1;
    cpu.machine_code->w = 1;

    cpu.operand_get();

    cpu.dest = cpu.src;

    std::cout << "cpu.dest: " << *cpu.dest.bit16 << std::endl;

}






