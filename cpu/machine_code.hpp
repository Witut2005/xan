
#pragma once

#include <stdint.h>

struct MachineCode
{
    
    union
    {
        uint8_t byte0;
        struct
        {
            uint8_t w : 1;
            uint8_t d : 1;
            uint8_t opcode : 6;
        };
    };
    
    
    union
    {
        uint8_t byte1;
        struct
        {
            uint8_t rm : 3;
            uint8_t reg : 3;
            uint8_t mod : 2;
        }__attribute__((packed));
    };

    union
    {

        uint16_t disp16;

        struct
        {
            uint8_t disp_low;
            uint8_t disp_high;
        };

        uint16_t data16;
        struct 
        {
            uint8_t data_low;
            uint8_t data_high;
        };

        struct
        {
            uint8_t byte2;
            uint8_t byte3;   
        };

    };


    union
    {
        uint16_t data16_1;
        struct 
        {
            uint8_t data_low1;
            uint8_t data_high1;
        };

        struct 
        {
            uint8_t byte4;
        };
    };

}__attribute__((packed));

inline MachineCode* machine_code;
 
