
#include <stdint.h>

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