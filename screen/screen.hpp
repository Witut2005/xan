
#include <stdint.h>
#include <utility>

class ScreenManager 
{
    private:
        uint8_t* vram;
        uint32_t vram_start;
        uint32_t vram_end;

    public:
        ScreenManager(uint8_t* ram_ptr, std::pair<uint32_t, uint32_t> memory_span);

};