#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

int main()
{
    //enter File name and location here.
    std::ifstream fileName("../lightMatrix.txt");

    std::string stringBeingParsed;

    int maxLightsPerRow{1000};
    int lightsOn{0};

    //For the outer vector
    int startingRow{0};
    int endingRow{0};

    //For the inner vector
    int startingCol{0};
    int endingCol{0};

    bool firstLoop{true};

    std::string getInstruction;
    std::vector<std::vector<bool>> lightDisplay(maxLightsPerRow, std::vector<bool>(maxLightsPerRow, false));


    std::cout << lightDisplay.size() << '\n';
    while(true)
    {
        //Getting the lines from the file, each loop it automatically goes to the next line.
        //It grabs the line from the variable fileName and places it in the stringBeingParsed variable.
        std::getline(fileName,stringBeingParsed);

        if(stringBeingParsed.substr(0, stringBeingParsed.find(' ')) == "turn")
        {
            stringBeingParsed.erase(0,stringBeingParsed.find(' ') + 1);
            getInstruction = "turn " + stringBeingParsed.substr(0, stringBeingParsed.find(' '));
            stringBeingParsed.erase(0,stringBeingParsed.find(' ') + 1);
        }
        else
        {
            getInstruction = "toggle";
            stringBeingParsed.erase(0,stringBeingParsed.find(' ') + 1);
        }

        startingRow = std::stoi(stringBeingParsed.substr(0, stringBeingParsed.find(',')));
        stringBeingParsed.erase(0,stringBeingParsed.find(',') + 1);
        startingCol = std::stoi(stringBeingParsed.substr(0, stringBeingParsed.find(' ')));
        stringBeingParsed.erase(0,stringBeingParsed.find(' ') + 1);

        // Erase Through
        stringBeingParsed.erase(0,stringBeingParsed.find(' ') + 1);

        endingRow = std::stoi(stringBeingParsed.substr(0, stringBeingParsed.find(',')));
        stringBeingParsed.erase(0,stringBeingParsed.find(',') + 1);
        endingCol = std::stoi(stringBeingParsed.substr(0, stringBeingParsed.find(' ')));
        stringBeingParsed.erase(0,stringBeingParsed.find(' ') + 1);

        if(getInstruction == "turn on")
        {
            for(int i {startingRow}; i <= endingRow; ++i)
            {
                for (int j{startingCol}; j <= endingCol; ++j)
                {
                    if(lightDisplay[i][j])
                    {

                    }
                    else
                    {
                        lightDisplay[i][j] = true;
                        lightsOn++;
                    }
                }
            }
        }
        else if (getInstruction == "turn off")
        {
            for(int i {startingRow}; i <= endingRow; ++i)
            {
                for (int j{startingCol}; j <= endingCol; ++j)
                {
                    if(lightDisplay[i][j])
                    {
                        lightDisplay[i][j] = false;
                        lightsOn--;
                    }
                    else
                    {

                    }
                }
            }
        }
        else if (getInstruction == "toggle")
        {
            for(int i {startingRow}; i <= endingRow; ++i)
            {
                for (int j{startingCol}; j <= endingCol; ++j)
                {
                    if(lightDisplay[i][j])
                    {
                        lightDisplay[i][j] = false;
                        lightsOn--;
                    }
                    else
                    {
                        lightDisplay[i][j] = true;
                        lightsOn++;
                    }
                }
            }
        }
        else
        {

        }

        //If it is the end of the file, it will break the while loop.
        if( fileName.eof() )
        {
            break;
        }
    }


    std::cout << "The total amount of lights on is: " << lightsOn << '\n';

    int iterationCount{0};

    for(auto i : lightDisplay)
    {
        for(int j{0}; j < i.size(); ++j)
        {
            i[j] = false;
        }
    }

    for(auto i : lightDisplay)
    {
        for(auto j : i)
        {
            if(j)
            {
                ++iterationCount;
            }
        }
    }

    std::cout << "The total amount of lights calculated through iteration is: " << iterationCount << '\n';

    return 0;
}
