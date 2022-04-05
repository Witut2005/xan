
#include <stdint.h>

struct GeneralPurposeRegister
{
    struct 
    {
        uint16_t bit16;
        union
        {
            uint8_t l,h;
        };
    };
};

struct SegmentRegister
{
    uint16_t bit16;
};

class CentralProcessingUnit
{


    public:
        GeneralPurposeRegister registers[8];
        SegmentRegister segment_registers[4];
    

};


#define ax registers[0]
#define cx registers[1]
#define dx registers[2]
#define bx registers[3]
#define sp registers[4]
#define bp registers[5]
#define si registers[6]
#define di registers[7]

