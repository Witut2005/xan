
#include <cpu/cpu.hpp>
#include <cpu/cpu_instructions.hpp>
#include <iostream>



CentralProcessingUnit::CentralProcessingUnit()
{

    ram = new uint8_t [31944];
    ip = 0x7c00;
    machine_code = (MachineCode*)&ram[0x7c00];
}

void CentralProcessingUnit::execute()
{
    operand_get();
    machine_code = (MachineCode*)&ram[ip];
    printf("machine_code->byte0: 0x%x\n",machine_code->byte0);
    instruction_set[machine_code->byte0]();
}

void CentralProcessingUnit::registers_print(void)
{
    std::cout << "ax: 0x" << std::hex << cpu->ax << std::endl;
    std::cout << "cx: 0x" << std::hex << cpu->cx << std::endl;
    std::cout << "dx: 0x" << std::hex << cpu->dx << std::endl;
    std::cout << "bx: 0x" << std::hex << cpu->bx << std::endl;
    std::cout << "sp: 0x" << std::hex << cpu->sp << std::endl;
    std::cout << "bp: 0x" << std::hex << cpu->bp << std::endl;
    std::cout << "si: 0x" << std::hex << cpu->si << std::endl;
    std::cout << "di: 0x" << std::hex << cpu->di << std::endl;

    std::cout << "cs: 0x" << std::hex << cpu->cs << std::endl;
    std::cout << "ds: 0x" << std::hex << cpu->ds << std::endl;
    std::cout << "es: 0x" << std::hex << cpu->es << std::endl;
    std::cout << "ss: 0x" << std::hex << cpu->ss << std::endl;
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