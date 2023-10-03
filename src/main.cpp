#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"

int main()
{
    CPU teste = CPU();
    Add add = Add("2");
    Multiply m = Multiply("1");
    Divide d = Divide("0");
    Module modu = Module("4");
    Subtract sub = Subtract("3");

    teste.addInstruction(&add);
    teste.addInstruction(&sub);
    teste.addInstruction(&m);
    teste.addInstruction(&d);
    teste.addInstruction(&modu);


    teste.executeProgram();

    return 0;
}