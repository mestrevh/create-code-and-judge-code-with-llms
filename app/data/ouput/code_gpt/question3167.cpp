/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int maior(int a, int b) {
    return a * ((a - b) > 0) + b * ((b - a) > 0);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << maior(a, b) << endl;
    return 0;
}
