/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if ((A == 0 && B == 1 && C == 1)) cout << "A\n";
    else if ((A == 1 && B == 0 && C == 1)) cout << "B\n";
    else if ((A == 1 && B == 1 && C == 0)) cout << "C\n";
    else cout << "*\n";

    return 0;
}
