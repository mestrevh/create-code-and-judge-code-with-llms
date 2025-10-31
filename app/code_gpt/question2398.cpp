/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    int day, month, year;
    char separator;
    std::istringstream iss(input);
    iss >> day >> separator >> month >> separator >> year;

    std::cout << std::setw(2) << std::setfill('0') << month << '/' 
              << std::setw(2) << std::setfill('0') << day << '/' 
              << std::setw(2) << std::setfill('0') << year << std::endl;

    std::cout << std::setw(2) << std::setfill('0') << year << '/' 
              << std::setw(2) << std::setfill('0') << month << '/' 
              << std::setw(2) << std::setfill('0') << day << std::endl;

    std::cout << std::setw(2) << std::setfill('0') << day << '-' 
              << std::setw(2) << std::setfill('0') << month << '-' 
              << std::setw(2) << std::setfill('0') << year << std::endl;

    return 0;
}
