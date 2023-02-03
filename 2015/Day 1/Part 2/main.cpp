#include <iostream>
#include <string>

int main()
{
    std::cout << "Santa is currently on the ground floor(floor 0).\n" <<
    "Give him his instructions using open and close parenthesis.\n" <<
    "Open parenthesis \"(\" means up one floor.\n" <<
    "Close parenthesis \")\" means down one floor.\n";

    std::string directions{};// Input directions here within quotes.

    //Want to make the input below accept long strings
//    std::cin >> directions;

   int floor{0};

   int position{0};

    for(int i{0}; i < directions.size(); ++i)
    {
        if(directions[i] == '(')
        {
            ++floor;
            ++position;
        }

        else if(directions[i] == ')')
        {
            --floor;
            ++position;
            if(floor == -1)
                break;
        }
    }


   std::cout << "\n\nSanta goes into the basement at position " << position << '\n';
   std::cout << "It is dark and scary... Get him out.\n";

    return 0;
}