/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isValidDate(int d, int m, int y) {
    if (m < 1 || m > 12) return false;
    if (d < 1) return false;
    
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    
    return d <= daysInMonth[m];
}

void nextDay(int &d, int &m, int &y) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    
    d++;
    if (d > daysInMonth[m]) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
}

int main() {
    int d, m, y;
    cin >> d >> m >> y;
    
    if (!isValidDate(d, m, y)) {
        cout << "Data invalida" << endl;
    } else {
        nextDay(d, m, y);
        cout << d << "." << m << "." << y << endl;
    }
    return 0;
}
