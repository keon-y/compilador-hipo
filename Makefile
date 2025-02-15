DEPENDS=$(wildcard *.o)
all:
	g++ -c ../src/main.cpp ../src/graphics/Notification.cpp ../src/types/Integer.cpp ../src/instructions/Instruction.cpp ../src/instructions/ArithmeticInstructions.cpp ../src/instructions/IOInstructions.cpp ../src/instructions/CopyInstructions.cpp ../src/instructions/BranchInstructions.cpp ../src/components/CPU.cpp ../src/graphics/Button.cpp ../src/graphics/MemoryBlock.cpp ../src/graphics/Textbox.cpp ../src/states/StateMachine.cpp ../src/states/State.cpp ../src/states/ExecutingState.cpp ../src/states/LoadState.cpp ../src/states/MenuState.cpp -I../include/components -I../include/instructions -I../include/types -I../include/graphics -I../include/states -ISFML/include
	g++ ${DEPENDS} -o sfml-app -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=SFML/lib && ./sfml-app
