#include <iostream>
#include <map>
#include <string>
#include <vector>


int main()
{
    std::string directions{"^>v<"};

    std::vector<std::vector<int>> houses{};

    for(int i{0}; i < directions.size(); ++i)
    {
        //Reading the string one character at a time.
        if(directions[i])
        std::cout << directions[i] << '\n';
    }


    return 0;
}