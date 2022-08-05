

#include <screen/screen.hpp>

ScreenManager::ScreenManager(uint8_t* ram_ptr, std::pair<uint32_t, uint32_t>memory_span)
{

    this->vram = ram_ptr;
    this->vram_start = memory_span.first;
    this->vram_end = memory_span.second;

}

