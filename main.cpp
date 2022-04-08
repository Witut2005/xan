
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cpu/cpu.cpp>
#include <cpu/machine_code.hpp>


int main(void)
{


    cpu = new CentralProcessingUnit;





    cpu->machine_code = (MachineCode*)&ram[cpu->ip];

    cpu->machine_code->reg = 0;
    cpu->machine_code->rm = 1;
    cpu->machine_code->mod = 3;

    cpu->machine_code->d = 1;
    cpu->machine_code->w = 1;


    cpu->operand_get();

    cpu->ax = 10;
    cpu->cx = 20;



    cpu->dest += cpu->src;

    std::cout << "REGISTER STATUS:\n";

    cpu->ax++;

    std::cout << cpu->ax << std::endl;
    std::cout << cpu->cx << std::endl;
    std::cout << cpu->dx << std::endl;
    std::cout << cpu->bx << std::endl;
    std::cout << cpu->sp << std::endl;
    std::cout << cpu->bp << std::endl;
    std::cout << cpu->si << std::endl;
    std::cout << cpu->di << std::endl;


}






