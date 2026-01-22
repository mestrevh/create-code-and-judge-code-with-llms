/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int calculateY(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (x == 3) return 4;
    return (x - 1) * (x - 1);
}

int main() {
    int x;
    cin >> x;
    cout << calculateY(x) << endl;
    return 0;
}
