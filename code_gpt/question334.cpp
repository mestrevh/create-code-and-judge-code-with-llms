/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, Z;
    cin >> X;

    while (true) {
        cin >> Z;
        if (Z > X) break;
    }

    int count = 0, sum = 0, current = X;
    while (sum <= Z) {
        sum += current;
        count++;
        current++;
    }

    cout << count << endl;
    return 0;
}
