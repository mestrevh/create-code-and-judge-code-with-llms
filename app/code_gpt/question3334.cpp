/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <string>

std::tm stringToDate(const std::string& dateStr) {
    std::tm date = {};
    std::stringstream ss(dateStr);
    ss >> std::get_time(&date, "%d/%m/%Y");
    return date;
}

std::string dateToString(const std::tm& date) {
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", &date);
    return buffer;
}

int main() {
    std::string dateStrA, dateStrB;
    std::getline(std::cin, dateStrA);
    std::getline(std::cin, dateStrB);

    std::tm dateA = stringToDate(dateStrA);
    std::tm dateB = stringToDate(dateStrB);

    std::time_t timeA = std::mktime(&dateA);
    std::time_t timeB = std::mktime(&dateB);

    double secondsBetween = difftime(timeB, timeA);
    std::time_t middleTime = timeA + secondsBetween / 2;

    std::tm middleDate = *std::localtime(&middleTime);
    std::string resultDate = dateToString(middleDate);
    
    if (static_cast<int>(secondsBetween / (60 * 60 * 24)) % 2 == 0) {
        std::cout << resultDate << " 00:00" << std::endl;
    } else {
        std::cout << resultDate << " 12:00" << std::endl;
    }

    return 0;
}
