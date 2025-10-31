/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 10 == 0) {
        cout << "NAO" << endl;
    } else {
        int removed_digit = n / 10;
        if (n % removed_digit == 0) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }

    return 0;
}
