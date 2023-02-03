#include <iostream>

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




int main()
{
    int length{4};
    int width{5};
    int height{6};


    int sideOne{areaCalculation(length,width)};
    int sideTwo{areaCalculation(width, height)};
    int sideThree{areaCalculation(height, length)};

    int smallestArea{areaComparison(sideOne,sideTwo, sideThree)};

    std::cout << "The total amount of wrapping paper needed is " <<
    (2*sideOne) + (2*sideTwo) + (2*sideThree) + smallestArea << "\n\n";


    return 0;
}