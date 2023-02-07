#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

int areaCalculation(int a, int b)
{
    int area{a * b};
    return area;
}

int areaComparison(int sideOne, int sideTwo, int sideThree)
{
    int temp{(sideOne < sideTwo) ? sideOne : sideTwo};

    temp = (temp < sideThree) ? temp : sideThree;

    return temp;
}

int formulaForWrappingPaper(int length, int width, int height)
{

    //Formula to calculate how much wrapping paper is needed
    int sideOne{areaCalculation(length,width)};
    int sideTwo{areaCalculation(width, height)};
    int sideThree{areaCalculation(height, length)};

    int smallestArea{areaComparison(sideOne,sideTwo, sideThree)};

    // The following was used to make sure each line was being printed correctly.
//    std::cout << "The total amount of wrapping paper needed is " <<
//    (2*sideOne) + (2*sideTwo) + (2*sideThree) + smallestArea << "\n";

    int total{(2*sideOne) + (2*sideTwo) + (2*sideThree) + smallestArea};
    return total;
}

int formulaForRibbon(int length, int width, int height)
{
    //Placing each side into a vector then sorting it to find the lowest sides.
    std::vector<int> sides{length, width, height};

    std::sort(sides.begin(), sides.end());

    int total{((length * width) * height) + ((2 * sides[0]) + (2 * sides[1])) };
    return total;
}

int main()
{

    std::ifstream fileName("../measurements.txt");

    std::string temp;
    int number{};
    std::vector<int> dimensionsOfPaper{};

    //Counting how many lines in the file to set the amount of loops for my while statement.
    int linesInFile{0};
    while(std::getline(fileName, temp))
        ++linesInFile;

    //CLosing file and reopening it so stringstream can start from the beginning of the file.
    fileName.clear();
    fileName.close();
    fileName.open("../measurements.txt");

    std::vector<int> totalAmountOfPaper{};
    std::vector<int> totalAmountOfRibbon{};

    int iteration{0};
    while (iteration < linesInFile)
    {
        //Extracting integers from string
        std::getline(fileName, temp);
        std::stringstream line(temp);
        std::string extractedNum;
        while(std::getline (line, extractedNum, 'x'))
        {
            if(std::stringstream(extractedNum) >> number)
            {
                dimensionsOfPaper.push_back( number );
            }
            if (dimensionsOfPaper.size() == 3)
            {
                totalAmountOfPaper.push_back(formulaForWrappingPaper(dimensionsOfPaper[0], dimensionsOfPaper[1], dimensionsOfPaper[2]));
                totalAmountOfRibbon.push_back(formulaForRibbon(dimensionsOfPaper[0], dimensionsOfPaper[1], dimensionsOfPaper[2]));
                dimensionsOfPaper.clear();
                break;
            }
        }

        ++iteration;
    }

    //Getting the sum total of the totalAmountOfPaper vector variable
    int totalPaperNeeded{0};
    for (int loop: totalAmountOfPaper)
    {
        totalPaperNeeded += loop;
    }

    int totalRibbonNeeded{0};
    for (int loop: totalAmountOfRibbon)
    {
        totalRibbonNeeded += loop;
    }


    std::cout << "The total amount of wrapping paper needed is " << totalPaperNeeded<<
    " and the total amount of ribbon needed is "  << totalRibbonNeeded << '\n';

    return 0;
}