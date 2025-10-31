/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

void adjustTime(int &hh, int &mm, int minutes) {
    mm += minutes;
    while (mm >= 60) {
        mm -= 60;
        hh++;
    }
    while (hh >= 24) {
        hh -= 24;
    }
}

void adjustTimeNegative(int &hh, int &mm, int minutes) {
    mm -= minutes;
    while (mm < 0) {
        mm += 60;
        hh--;
    }
    while (hh < 0) {
        hh += 24;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int hh, mm, x;
        char colon;
        cin >> hh >> colon >> mm >> x;

        int hh1 = hh, mm1 = mm; // for addition
        int hh2 = hh, mm2 = mm; // for subtraction

        adjustTime(hh1, mm1, x);
        adjustTimeNegative(hh2, mm2, x);

        cout << setw(2) << setfill('0') << hh2 << ":"
             << setw(2) << setfill('0') << mm2 << " "
             << setw(2) << setfill('0') << hh1 << ":"
             << setw(2) << setfill('0') << mm1 << endl;
    }

    return 0;
}
