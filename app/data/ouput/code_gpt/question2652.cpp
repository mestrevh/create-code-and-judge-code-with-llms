/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    char input;
    while (true) {
        cin >> input;
        if (input == 'F') break;
        for (char c = 'A'; c <= input; c++) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
