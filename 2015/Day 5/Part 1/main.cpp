#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int main()
{
    //enter File name and location here.
    std::ifstream fileName("../NaughtyOrNiceList.txt");

    //Setting Variable for the string being checked during the iteration.
    std::string stringBeingChecked{};

    //Setting variable for how many nice strings were found.
    int niceStringCount{0};

    //Infinite loop till end of file which is checked for at the end off each loop.
while(true)
{
    //Setting niceString variable each loop to true.
    bool niceString{true};

    //Setting the vowels found counter to 0 each loop.
    int vowelsFound{0};

    //Getting the lines from the file, each loop it automatically goes to the next line.
    //It grabs the line from the variable fileName and places it in the stringBeingChecked variable.
    std::getline(fileName,stringBeingChecked);

    //Placing each character from the stringBeingChecked variable and
    // placing it in a vector called checkEachLetter.
    std::vector<char> checkEachLetter(stringBeingChecked.begin(), stringBeingChecked.end());

    //This For loops checks each letter to see if it is a vowel or not
    for (auto i: checkEachLetter) {

//        For debugging purposes, prints off the element in the vector it is checking.
//        std::cout << i << '\n';

        //If it is a vowel it will increase the vowelsFound variable by 1.
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            ++vowelsFound;

//            For debugging purposes, prints how many vowels were found each times it finds one.
//            std::cout << "Vowels found: " << vowelsFound << '\n';
        }

        //If it finds 3 vowels it will break the if loop since we only need to find at least 3 vowels.
        if (vowelsFound >= 3) {
            break;
        }
    }

    //If it did not find 3 vowels above, it sets the niceString variable to false.
    if (vowelsFound < 3)
    {
        niceString = false;
    }

    //Setting the doubleFound variable to false. To check if two adjacent elements are the same.
    bool doubleFound{false};

    //If niceString is true, This if statement will run to see if the element(letter) being checked
    //is the same as the adjacent element(letter)
    //If a double is found, it will set the doubleFound bool to true.
    if (niceString) {
        doubleFound = std::adjacent_find(checkEachLetter.begin(), checkEachLetter.end()) != checkEachLetter.end();

//        For debugging purposes, checks if a double was found.
//        std::cout << "A double was found? : " << doubleFound << '\n';
    }

    //If a double was not found in the above if loop, it will set the niceString variable to false.
    if (!doubleFound) {
        niceString = false;
    }

    //This for loop checks if the adjacent character to the character being checked for
    //a set of certain 2 character strings. If any pair matches then the loops breaks and sets
    //the niceString variable to false.
    for (int i{}; i < (checkEachLetter.size() - 1) && niceString; i++) {

        //Placing the character being checked into string variable
        std::string elementBeingChecked{checkEachLetter[i]};

        //Placing the character next to the one being checked into a string variable
        std::string adjacentElement{checkEachLetter[i + 1]};

//        For debugging purposes, prints the two elements being compared.
//        std::cout << str + str2 << '\n';

        //This if statement sets the niceString variable to false if any of the
        // two characters being compared matches any of the 4 pairs below.
        if
        ((elementBeingChecked + adjacentElement)== "ab" ||
        (elementBeingChecked + adjacentElement) == "cd" ||
        (elementBeingChecked + adjacentElement) == "pq" ||
        (elementBeingChecked + adjacentElement) == "xy")
        {
            niceString = false;
            break;
        }
    }

//    For debugging purposes, checks what string was checked and if it is naughty or nice.
//    if (niceString)
//    {
//        std::cout << "The string " << stringBeingChecked << " is a nice string.\n \n";
//    }
//    else {
//        std::cout << "The string " << stringBeingChecked << " is a naughty string.\n \n";
//    }


//If the string was nice then it increments the niceStringCount variable by 1.
if (niceString)
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