
#pragma once

#include <cpu/cpu.hpp>
#include <cpu/cpu_instructions.hpp>


void Operand::operator = (Operand source)
{
    if(cpu->machine_code->w)
        *bit16 = *source.bit16;
    else
        *bit8 = *source.bit8;

}

/*
void Operand::operator + (Operand source)
{
    if(cpu->machine_code->w)
        *bit16 += *source.bit16;
    else
        *bit8 += *source.bit8;
}
*/

void Operand::operator += (Operand source)
{
    if(cpu->machine_code->w)
        *bit16 += *source.bit16;
    else
        *bit8 += *source.bit8;
}


/*
void Operand::operator -= (Operand source)
{
    if(cpu->machine_code->w)
        *bit16 += *source.bit16;
    else
        *bit8 += *source.bit8;
}
*/


void Operand::operator - (Operand source)
{
    if(cpu->machine_code->w)
        *bit16 -= *source.bit16;
    else
        *bit8 -= *source.bit8;
}

CentralProcessingUnit::CentralProcessingUnit()
{
    ram = new uint8_t [31944];
    ip = 0x7c00;
}

void CentralProcessingUnit::execute()
{
    machine_code = (MachineCode*)&ram[ip];

    printf("machine_code->byte0: 0x%x\n",machine_code->byte0);

    processor_instruction[machine_code->byte0]();

}

void CentralProcessingUnit::registers_print(void)
{
    std::cout << "ax: " << cpu->ax << std::endl;
    std::cout << "cx: " << cpu->cx << std::endl;
    std::cout << "dx: " << cpu->dx << std::endl;
    std::cout << "bx: " << cpu->bx << std::endl;
    std::cout << "sp: " << cpu->sp << std::endl;
    std::cout << "bp: " << cpu->bp << std::endl;
    std::cout << "si: " << cpu->si << std::endl;
    std::cout << "di: " << cpu->di << std::endl;

    std::cout << "cs: " << cpu->cs << std::endl;
    std::cout << "ds: " << cpu->ds << std::endl;
    std::cout << "es: " << cpu->es << std::endl;
    std::cout << "ss: " << cpu->ss << std::endl;
}

uint16_t CentralProcessingUnit::operand_address_get(void)
{
    switch (machine_code->mod)
    {
        case 0:
        {
            switch (machine_code->rm)
            {
                case 0: return cpu->bx + cpu->si;
                case 1: return cpu->bx + cpu->di;
                case 2: return cpu->bp + cpu->si;
                case 3: return cpu->bp + cpu->di;
                case 4: return cpu->si;
                case 5: return cpu->di;
                //case 6:
                case 7: return cpu->bx;
            }
        }

        case 1:
        {
            switch (machine_code->rm)
            {
                case 0: return cpu->bx + cpu->si + machine_code->disp_low;
                case 1: return cpu->bx + cpu->di + machine_code->disp_low;
                case 2: return cpu->bp + cpu->si + machine_code->disp_low;
                case 3: return cpu->bp + cpu->di + machine_code->disp_low;
                case 4: return cpu->si + machine_code->disp_low;
                case 5: return cpu->di + machine_code->disp_low;
                case 6: return cpu->bp + machine_code->disp_low;
                case 7: return cpu->bx;
            }
        }

        case 2:
        {
            switch (machine_code->rm)
            {
                case 0: return cpu->bx + cpu->si + machine_code->disp_low;
                case 1: return cpu->bx + cpu->di + machine_code->disp_low;
                case 2: return cpu->bp + cpu->si + machine_code->disp_low;
                case 3: return cpu->bp + cpu->di + machine_code->disp_low;
                case 4: return cpu->si + machine_code->disp_low;
                case 5: return cpu->di + machine_code->disp_low;
                case 6: return cpu->bp + machine_code->disp_low;
                case 7: return cpu->bx;
            }
        }

    }

    return 0;

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
    }

    else
        operand_address_get();
        
}