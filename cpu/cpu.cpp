
#pragma once

#include <cpu/cpu.hpp>
#include <cpu/cpu_instructions.hpp>


void Operand::operator = (Operand source)
{
    if(cpu.machine_code->w)
        *bit16 = *source.bit16;
    else
        *bit8 = *source.bit8;

}

void Operand::operator + (Operand source)
{
    if(cpu.machine_code->w)
        *bit16 += *source.bit16;
    else
        *bit8 += *source.bit8;
}

void Operand::operator - (Operand source)
{
    if(cpu.machine_code->w)
        *bit16 -= *source.bit16;
    else
        *bit8 -= *source.bit8;
}

CentralProcessingUnit::CentralProcessingUnit()
{
    ram = new uint8_t [512 * 100];
    ip = 0x7c00;
}

void CentralProcessingUnit::execute()
{
    machine_code = (MachineCode*)&ram[ip];

    printf("machine_code->byte0: 0x%x\n",machine_code->byte0);

    processor_instruction[machine_code->byte0]();

}

void CentralProcessingUnit::operand_get(void)
{
    if(machine_code->mod == 3)
    {
        if(machine_code->d)
        {
            dest.bit16 = (uint16_t*)&registers[machine_code->reg];
            dest.bit8 = (uint8_t*)&registers[machine_code->reg];

            src.bit16 = (uint16_t*)&registers[machine_code->rm];
            src.bit8 = (uint8_t*)&registers[machine_code->rm];
        }

        else
        {
            dest.bit16 = (uint16_t*)&registers[machine_code->rm];
            dest.bit8 = (uint8_t*)&registers[machine_code->rm];

            src.bit16 = (uint16_t*)&registers[machine_code->reg];
            src.bit8 = (uint8_t*)&registers[machine_code->reg];
        }
    }

    std::cout << "NOT IMPLMENTED" << std::endl;
    exit(1);

}