
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cpu/cpu.cpp>
#include <screen/screen.hpp>
#include <cpu/machine_code.hpp>


int main(int argc, char *argv[])
{
    std::fstream file;

    if(argc != 2)
    {
        exit(1);
    }


    cpu = new CentralProcessingUnit;

    file.open(argv[1], std::fstream::in | std::fstream::binary);

    file.read((char*)&ram[0x7c00], 512);


    for(int i = 0; i < 8; i++)
        cpu->registers[i].bit16 = i;

    std::string option;
    std::string option_buffer;

    while(1)
    {
        std::cin >> option;

        if(option == "p")
        {   
            cpu->registers_print();
        }

        else if(option == "s")
        {
            cpu->execute();
        }


    }



}






