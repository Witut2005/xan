
#include <stdint.h>

struct MachineCode
{
    union
    {
        uint8_t opcode;
        struct
        {
            uint8_t w : 1;
            uint8_t d : 1;
        };
    };
    
    
    union
    {
        uint8_t byte2;
        struct
        {
            uint8_t rm : 3;
            uint8_t reg : 3;
            uint8_t mod : 2;
        };
    };

    struct 
    {
        uint8_t byte3;
        union
        {
            uint8_t disp_low;
            uint8_t disp_high;
            
            uint8_t data_low1;
            uint8_t data_high1;
        };
    };

    struct 
    {
        uint8_t data_low2;
        uint8_t data_high2;
    };

}__attribute__((packed));
 
