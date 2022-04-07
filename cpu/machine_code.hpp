
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
        };
    };

    struct 
    {
        uint8_t byte2;
        union
        {
            uint8_t disp_low;
            uint8_t low_data;
        };

        union
        {
            uint8_t disp_high;
            uint8_t high_data;
        };

    };


    struct 
    {
        uint8_t data_low1;
        uint8_t data_high1;
    };

}__attribute__((packed));
 
