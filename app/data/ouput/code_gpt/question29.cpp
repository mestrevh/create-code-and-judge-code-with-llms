/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int inverted = 0;

    while (num > 0) {
        inverted = inverted * 10 + num % 10;
        num /= 10;
    }

    cout << inverted << endl;
    return 0;
}
