#include <iostream>
#include <string>
#include "md5.h"


int main(int argc, char *argv[])
{
    //Entered my Puzzle Answer for the hex variable
    std::string hex{"bgvyzdsv"};

    //Creating a variable to find the answer.
    int number{0};

    //Creating an output variable to find the output that gives use 6 leading zeros.
    std::string output{md5(hex + std::to_string(number))};

    //Running a while loop that increases the number variable by 1 until the output has 6 leading zeros.
    while (output.substr(0,6) != "000000")
    {
        number++;
        output = md5(hex + std::to_string(number));
    }

    //Displaying the answer.
    std::cout << "md5 of " << hex + std::to_string(number) << ": " << md5(hex + std::to_string(number)) << '\n';

    return 0;
}