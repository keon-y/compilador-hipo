#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"

int main()
{
    CPU teste = CPU();
    teste.addToMemory(Integer("+2150"));
    teste.addToMemory(Integer("+2250"));
    teste.addToMemory(Integer("+2350"));
    teste.addToMemory(Integer("+2450"));
    teste.addToMemory(Integer("+2550"));
    /*Add add = Add("2");
    Multiply m = Multiply("1");
    Divide d = Divide("0");
    Module modu = Module("4");
    Subtract sub = Subtract("3");

    teste.addInstruction(&add);
    teste.addInstruction(&sub);
    teste.addInstruction(&m);
    teste.addInstruction(&d);
    teste.addInstruction(&modu);
    */

    teste.executeProgram();

    return 0;
}