/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

void printHourglass(int l, int i) {
    int topLevel = l - 1;
    int bottomLevel = l - 1;
    
    cout << "Caso " << i + 1 << ":\n";

    for (int row = 0; row < l; row++) {
        if (row < l - i - 1) {
            cout << string(row, ' ') << "**";
            cout << string(topLevel - row, '*') << string(topLevel - row, ' ') << "**\n";
        } else if (row >= l - i - 1 && row < l) {
            cout << string(row, ' ') << "*";
            cout << string(bottomLevel - row, '.') << string(bottomLevel - row, ' ') << "*\n";
        }
    }
    
    for (int row = l - 1; row >= 0; row--) {
        cout << string(row, ' ') << "**";
        cout << string(topLevel - row, '*') << string(topLevel - row, ' ') << "**\n";
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int l, level;
        cin >> l >> level;
        printHourglass(l, i);
    }

    return 0;
}
