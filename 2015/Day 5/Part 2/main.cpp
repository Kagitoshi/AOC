#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main()
{
    //enter File name and location here.
    std::ifstream fileName("../NaughtyOrNiceList.txt");

    //Setting Variable for the string being checked during the iteration.
    std::string stringBeingChecked{};

    //Setting variable for how many nice strings were found.
    int niceStringCount{0};

    //  to true until proven else wise
    bool niceString{false};

    //Initializing the pairsFound variable to false.
    bool pairsFound{false};
    bool foundCharRepeatSeperated{false};

    //Setting some pointers to check chars in string
    int leftPointer{0};
    int middlePointer{1};
    int rightPointer{2};

    //Infinite loop till end of file which is checked for at the end off each loop.
    while(true)
    {
        pairsFound = false;
        foundCharRepeatSeperated = false;

        leftPointer = 0;
        middlePointer = 1;
        rightPointer = 2;

        std::unordered_map<std::string, int> pairTracker;

        //Getting the lines from the file, each loop it automatically goes to the next line.
        //It grabs the line from the variable fileName and places it in the stringBeingChecked variable.
        std::getline(fileName,stringBeingChecked);

        while(rightPointer < stringBeingChecked.size() || (!foundCharRepeatSeperated && !pairsFound))
        {
            if(!foundCharRepeatSeperated)
            {
                if(stringBeingChecked[leftPointer] == stringBeingChecked[rightPointer])
                {
                    foundCharRepeatSeperated = true;
                }
            }

            if(!pairsFound)
            {
                if(pairTracker[stringBeingChecked.substr(middlePointer, 2)] == 1)
                {
                    pairsFound = true;
                }
                else
                {
                    pairTracker.insert({stringBeingChecked.substr(middlePointer, 2), 0});
                }
            }

            std::string subString{stringBeingChecked.substr(leftPointer, 2)};
            pairTracker[subString] = 1;


            ++leftPointer;
            ++middlePointer;
            ++rightPointer;

            if(rightPointer >= stringBeingChecked.size())
            {
                break;
            }
        }


        //If the string was nice then it increments the niceStringCount variable by 1.
        if (foundCharRepeatSeperated && pairsFound)
        {
            niceStringCount++;
        }

        //If it is the end of the file, it will break the while loop.
        if( fileName.eof() )
        {
            break;
        }
    }

//Prints how many nice strings were found.
std::cout << "There has been " << niceStringCount << " nice strings found.\n \n";

    return 0;
}