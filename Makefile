all:
	g++ ./cpu/cpu.cpp -std=c++17 -I /home/witut/Desktop/xan -c -o ./cpu/cpu.o
	g++ ./cpu/cpu_instructions.cpp -std=c++17 -I /home/witut/Desktop/xan -c -o ./cpu/cpu_instructions.o
	g++ ./cpu/opcode_operand.cpp -std=c++17 -I /home/witut/Desktop/xan -c -o ./cpu/opcode_operand.o
	g++ ./screen/screen.cpp -std=c++17 -I /home/witut/Desktop/xan -c -o ./screen/screen.o

	g++ main.cpp -std=c++17 -I /home/witut/Desktop/xan -lncurses ./cpu/cpu.o ./cpu/cpu_instructions.o ./cpu/opcode_operand.o ./screen/screen.o -o xan

run:
	./xan $(FILE)