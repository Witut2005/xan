
#include <cpu/cpu.hpp>
#include <cpu/cpu_instructions.hpp>
#include <cpu/machine_code.hpp>

#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
    
    // start_color();
    // init_pair(2, COLOR_GREEN, COLOR_RED);
    // attron(COLOR_PAIR(2));
    // printw("ugabuga");

auto window_size_get(void)
{
    winsize WindowSize;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &WindowSize);
    return std::make_pair(WindowSize.ws_row, WindowSize.ws_col);
}


int main(int argc, char *argv[])
{
    std::fstream file;

    if(argc != 2)
    {
        // exit(1);
    }


    cpu = new CentralProcessingUnit;

    file.open(argv[1], std::fstream::in | std::fstream::binary);

    file.read((char*)&cpu->ram[0x7c00], 512);


    for(int i = 0; i < 8; i++)
        cpu->registers[i].bit16 = i;

    std::string option;
    std::string option_buffer;

    // initscr();
    
    // refresh();

    std::cout << "running\n";

    cpu->cx = 0xFFFF;

    while(1)
    {
        switch(getchar())
        {
            case 's':
                cpu->execute();
                break;

            case 'p':
                cpu->registers_print();
                break;
            
            case 'f':
                cpu->flags_print();
                break;
                

        }

    }

    endwin();



}






