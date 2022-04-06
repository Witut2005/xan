
#include "./cpu.hpp"
#include "./cpu_instructions.cpp"


CentralProcessingUnit::CentralProcessingUnit()
{
    ram = new uint8_t [512];
}

void CentralProcessingUnit::execute()
{
    machine_code = (MachineCode*)&ram[ip];
}