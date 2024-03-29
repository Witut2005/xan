
#include <cpu/cpu.hpp>
#include <cpu/cpu_instructions.hpp>
#include <iostream>
#include <ncurses.h>
#include <cassert>
#include <sstream>


CentralProcessingUnit::CentralProcessingUnit()
{

    ram = new uint8_t [0xFFFFF + 1];
    ip = 0x7c00;
    machine_code = (MachineCode*)&ram[0x7c00];
}

void CentralProcessingUnit::execute()
{
    this->direct_address = 0x0;

    machine_code = (MachineCode*)&ram[ip];
    printf("machine_code->byte0: 0x%x\n",machine_code->byte0);
    printf("machine_code->rm: 0x%x\n",machine_code->rm);
    printf("machine_code->reg: 0x%x\n",machine_code->reg);
    printf("machine_code->byte1: 0x%x\n", machine_code->byte1);
    instruction_set[machine_code->byte0]();
}

void CentralProcessingUnit::registers_print(void)
{
    // endwin();
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

void CentralProcessingUnit::flags_print(void)
{
    // endwin();
    std::cout << "0x" << std::hex << *(uint16_t*)&cpu->flags << std::endl;
}

void CentralProcessingUnit::ram_print(std::string addr_str)
{
    std::stringstream tmp;
    tmp << std::hex << addr_str;
    int x;
    tmp >> x;
 
    for(int i = 0; i < 0x10; i++)
    {
        printf("%.2x ", this->ram[x + i]);
    }
    printf("\n");
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
                case 6: direct_address = 2; return (uint16_t)(machine_code->byte2 | ((uint16_t)machine_code->byte3 << 8));
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
    
    auto reg8_rm = machine_code->rm;
    auto reg8_reg = machine_code->reg;

    bool reg8_rm_high = false;
    bool reg8_reg_high = false;

    if(reg8_rm >= 4)
    {
        printf("reg8_rm: 0x%x\n", reg8_rm);
        reg8_rm = reg8_rm - 4;
        reg8_rm_high = true;
    }

    if(reg8_reg >= 4)
    {
        reg8_reg = reg8_reg - 4;
        reg8_reg_high = true;
    }
    
    printf("fromini1\n");
    printf("D BIT 0x%x\n", machine_code->d); 

    if(machine_code->mod == 3)
    {
        printf("fromini2\n");

        
        if(machine_code->d)
        {

            this->dest.bit16 = (uint16_t*)&registers[machine_code->reg];
            
            
            if(reg8_reg_high)
                this->dest.bit8 = (uint8_t*)&(registers[reg8_reg].h);
            else 
                this->dest.bit8 = (uint8_t*)&(registers[reg8_reg].l);

            
            ////////////////////////

            this->src.bit16 = (uint16_t*)&registers[machine_code->rm];

            if(reg8_rm_high)
                this->src.bit8 = (uint8_t*)&(registers[reg8_rm].h);
            else 
                this->src.bit8 = (uint8_t*)&(registers[reg8_rm].l);

            printf("fromini4\n");
            
        }

        else 
        {
            this->src.bit16 = (uint16_t*)&(registers[machine_code->reg]);

            if(reg8_reg_high)
                this->src.bit8 = (uint8_t*)&(registers[reg8_reg].h);
            else 
                this->src.bit8 = (uint8_t*)&(registers[reg8_reg].l);

            ///////////////////////////

            this->dest.bit16 = (uint16_t*)&(registers[machine_code->rm]);

            if(reg8_rm_high)
                this->dest.bit8 = (uint8_t*)&(registers[reg8_rm].h);
            else 
                this->dest.bit8 = (uint8_t*)&(registers[reg8_rm].l);

        }

    }

    else
    {
    
        uint32_t address = operand_address_get();
        printf("omg my address: 0x%x\n", address);

        // assert(reg8_reg > 0 && reg8_reg < 4);
        // assert(reg8_rm > 0 && reg8_rm < 4);

        if(machine_code->d)
        {
            this->dest.bit16 = (uint16_t*)&registers[machine_code->reg];
            
            if(reg8_reg_high)
                this->dest.bit8 = (uint8_t*)&(registers[reg8_reg].h);
            else
                this->dest.bit8 = (uint8_t*)&(registers[reg8_reg].l);

            this->src.bit16 = (uint16_t*)&ram[address];
            this->src.bit8  = (uint8_t*)&ram[address];

        }

        else
        {
            this->src.bit16 = (uint16_t*)&registers[machine_code->reg];
            
            if(reg8_reg_high)
            {
                this->src.bit8 = (uint8_t*)&registers[reg8_reg].h;
                printf("HIGH\n");
            }

            else 
            {
                this->src.bit8 = (uint8_t*)&registers[reg8_reg].l;
                printf("LOW\n");
            }

            this->dest.bit16 = (uint16_t*)&ram[address];
            this->dest.bit8  = (uint8_t*)&ram[address];
        }
   

    }
    
    printf("end of getting operands\n");

}
