
#include <stdint.h>


uint8_t* ram;

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
        
        uint16_t ip;

        GeneralPurposeRegister registers[8];
        SegmentRegister segment_registers[4];
        CentralProcessingUnit();
        void execute();
        MachineCode* machine_code;


   

};


#define ax registers[0]
#define cx registers[1]
#define dx registers[2]
#define bx registers[3]
#define sp registers[4]
#define bp registers[5]
#define si registers[6]
#define di registers[7]

#define cs segment_registers[0]
#define ds segment_registers[1]
#define es segment_registers[2]
#define ss segment_registers[3]