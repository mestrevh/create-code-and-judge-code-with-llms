/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int start, end;
    cin >> start >> end;
    bool found = false;
    
    for (int year = start; year <= end; year++) {
        if (isLeapYear(year)) {
            cout << year << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "-1" << endl;
    }

    return 0;
}
