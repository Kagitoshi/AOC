#include <iostream>
#include <string>
#include <set>
#include <fstream>

int main()
{
    //Location of file with directions
    std::ifstream fileName("../directions.txt");

    //Human Santa's Coordinate variables
    int hX{0};
    int hY{0};

    //Robot Santa's Coordinate variables
    int rX{0};
    int rY{0};

    //Set coordinate variables as an initializer for Human and Robot Santa.
    std::set <std::pair<int, int>> houseCoordinates;


    //Adding Human and Robot Santa's first house
    houseCoordinates.insert(std::make_pair(hX, hY));

    //Creating char variable to track direction read from the file.
    std::string direction{};

    //Placing the file contents into a string.
    fileName >> direction;

    for (int i{0}; i < direction.size(); ++i )
    {

            //Human Santa's orders
            //Plus one to the Y coordinate for North direction.
            if(direction[i] == '^')
            {
                hY = ++hY;
            }
            //Minus one to the Y coordinate for South direction.
            if(direction[i] == 'v')
            {
                hY = --hY;
            }

            //Plus one to the X coordinate for East direction.
            if(direction[i] == '>')
            {
                hX = ++hX;
            }

            //Minus one to the X coordinate for West direction.
            if(direction[i] == '<')
            {
                hX = --hX;
            }

            //Adding new coordinates to the set.
            houseCoordinates.insert(std::make_pair(hX, hY));

            ++i;

            // Robot Santa's Orders
            //Plus one to the Y coordinate for North direction.
        if(direction[i] == '^')
        {
            rY = ++rY;
        }
        //Minus one to the Y coordinate for South direction.
        if(direction[i] == 'v')
        {
            rY = --rY;
        }

        //Plus one to the X coordinate for East direction.
        if(direction[i] == '>')
        {
            rX = ++rX;
        }

        //Minus one to the X coordinate for West direction.
        if(direction[i] == '<')
        {
            rX = --rX;
        }

        //Adding new coordinates to the set.
        houseCoordinates.insert(std::make_pair(rX, rY));

    }


// Below is to test if coordinates are printing correctly/
//    for (const auto& i : houseCoordinates)
//    {
//        std::cout << '(' << i.first << ',' << i.second << ") \n \n";
//    }

    //Displaying the amount of houses Santa visited.
    std::cout << "Human Santa and Robot Santa dropped off " << houseCoordinates.size()  << " presents, each to different houses.";

    return 0;
}