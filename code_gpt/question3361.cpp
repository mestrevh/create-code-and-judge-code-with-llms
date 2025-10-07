/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (i % 10 != 0) {
            cout << i << endl;
        }
    }
    return 0;
}
