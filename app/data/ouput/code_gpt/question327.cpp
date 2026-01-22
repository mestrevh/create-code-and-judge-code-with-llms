/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            cout << i << " " << (j == 1 ? i * i : i * i + i) << " " << (j == 1 ? i * i * i : (i * i * i) + i) << endl;
        }
    }
    return 0;
}
