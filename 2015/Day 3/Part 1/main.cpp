#include <iostream>
#include <string>
#include <set>
#include <fstream>

int main()
{
    //Location of file with directions
    std::ifstream fileName("../directions.txt");

    //Coordinate variables
    int x{0};
    int y{0};

    //Set coordinate variables as an initializer.
    std::set <std::pair<int, int>> houseCoordinates;

    //Adding Santa's first house
    houseCoordinates.insert(std::make_pair(x, y));

    //Creating char variable to track direction read from the file.
    char direction{};

    while (fileName.get(direction))
    {
            //Plus one to the Y coordinate for North direction.
            if(direction == '^')
            {
                y = ++y;
            }
            //Minus one to the Y coordinate for South direction.
            if(direction == 'v')
            {
                y = --y;
            }

            //Plus one to the X coordinate for East direction.
            if(direction == '>')
            {
                x = ++x;
            }

            //Minus one to the X coordinate for West direction.
            if(direction == '<')
            {
                x = --x;
            }

            //Adding new coordinates to the set.
            houseCoordinates.insert(std::make_pair(x, y));

    }


// Below is to test if coordinates are printing correctly/
//    for (const auto& i : houseCoordinates)
//    {
//        std::cout << '(' << i.first << ',' << i.second << ") \n \n";
//    }

    //Displaying the amount of houses Santa visited.
    std::cout << "Santa dropped off " << houseCoordinates.size() << " presents, each to different houses.";

    return 0;
}