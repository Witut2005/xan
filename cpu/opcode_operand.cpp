
#include <cpu/opcode_operand.hpp>
#include <cpu/machine_code.hpp>

// void Operand::operator = (Operand source)
// {
//     if(machine_code->w)
//         *bit16 = *source.bit16;
//     else
//         *bit8 = *source.bit8;

// }

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
    if(machine_code->w)
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
    if(machine_code->w)
        *bit16 -= *source.bit16;
    else
        *bit8 -= *source.bit8;
}