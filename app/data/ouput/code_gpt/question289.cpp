/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int F, I;
    cin >> F >> I;
    int count = 0;

    if (F >= 150 && I >= 12) count++;
    if (F >= 140 && I >= 14) count++;
    if (F >= 170 || I >= 16) count++;

    cout << count << endl;
    return 0;
}
