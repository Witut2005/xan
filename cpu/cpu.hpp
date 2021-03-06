
#pragma once

#include <stdint.h>
#include <cpu/machine_code.hpp>

uint8_t* ram;

class Operand
{

    public:
        uint16_t* bit16;
        uint8_t* bit8;

        void operator = (Operand source);
        void operator + (Operand source);
        void operator += (Operand source);
        void operator -= (Operand source);
        void operator ++ ();
        void operator -- ();
        void operator - (Operand source);

};

union GeneralPurposeRegister
{
    uint16_t bit16;
    struct
    {
        uint8_t l,h;
    };
 
};

struct SegmentRegister
{
    uint16_t bit16;
};

class CentralProcessingUnit
{


    public:
        
        Operand dest;
        Operand src;

        uint16_t ip;
        GeneralPurposeRegister registers[8];
        SegmentRegister segment_registers[4];
        CentralProcessingUnit();
        void execute();
        void registers_print(void);
        const MachineCode* machine_code;
        void operand_get(void);
        uint16_t operand_address_get(void);
   

};


CentralProcessingUnit* cpu;

#define ax registers[0].bit16
#define cx registers[1].bit16
#define dx registers[2].bit16
#define bx registers[3].bit16
#define sp registers[4].bit16
#define bp registers[5].bit16
#define si registers[6].bit16
#define di registers[7].bit16

#define al registers[0].l
#define cl registers[1].l
#define dl registers[2].l
#define bl registers[3].l
#define ah registers[0].h
#define ch registers[1].h
#define dh registers[2].h
#define bh registers[3].h

#define cs segment_registers[0].bit16
#define ds segment_registers[1].bit16
#define es segment_registers[2].bit16
#define ss segment_registers[3].bit16