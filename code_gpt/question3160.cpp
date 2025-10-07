/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int maior(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << maior(a, b, c) << endl;
    return 0;
}
