
#pragma once

#include <stdint.h>
#include <cpu/machine_code.hpp>
#include <cpu/opcode_operand.hpp>
#include <string>



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

struct FlagsRegister
{
    uint8_t cf : 1;
    uint8_t resv0  : 1;
    uint8_t pf : 1;
    uint8_t resv1 : 1;
    uint8_t af : 1;
    uint8_t resv2 : 1;
    uint8_t zf : 1;
    uint8_t sf : 1;
    uint8_t tf : 1;
    uint8_t _if : 1;
    uint8_t df : 2;
    uint8_t of : 1;
    uint8_t iopl : 1;
    uint8_t nt : 1;
    uint8_t resv3 : 1;
};


class CentralProcessingUnit
{


    public:
        
        Operand dest;
        Operand src;
        uint8_t* ram;
        uint16_t ip;
        FlagsRegister flags;
        uint8_t direct_address;

        GeneralPurposeRegister registers[8];
        SegmentRegister segment_registers[4];
        CentralProcessingUnit();
        void execute();
        void registers_print(void);
        void flags_print(void);
        void operand_get(void);
        void ram_print(std::string addr_str);
        uint16_t operand_address_get(void);
   

};


inline CentralProcessingUnit* cpu;

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