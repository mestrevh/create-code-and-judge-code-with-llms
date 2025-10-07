/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0, odd = 1;

    while (n >= 0) {
        n -= odd;
        odd += 2;
        count++;
    }

    cout << (n == 0 ? count - 1 : count - 2) << endl;
    return 0;
}
