/****************************************
* Contestant number 04-0207-0001
****************************************/

#include <cstdlib>
#include <iostream>

#include "Input.h"

using namespace std;

int main(int argc, char *argv[])
{
    int isExit;    // If program should exit
    
    // While the program should continue
    do
    {
             // Process user input and return if program should continue or not
             isExit = getInput();
    }
    while(isExit == 1);
    
    // Exits successfully
    return EXIT_SUCCESS;
}
