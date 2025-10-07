/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    string input;
    cin >> input;

    int day, month, year;
    char delimiter;
    stringstream ss(input);
    ss >> day >> delimiter >> month >> delimiter >> year;

    day += 30;

    if (day > 30) {
        day -= 30;
        month++;
    }

    if (month > 12) {
        month -= 12;
        year++;
    }

    cout << setw(2) << setfill('0') << day << "/"
         << setw(2) << setfill('0') << month << "/"
         << year << endl;

    return 0;
}
