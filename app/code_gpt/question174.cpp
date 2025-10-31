/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    double total = 7.0;

    if (N > 10) {
        if (N <= 30) {
            total += (N - 10) * 2.0;
        } else if (N <= 100) {
            total += 40.0 + (N - 30) * 5.0;
        } else {
            total += 40.0 + 350.0 + (N - 100) * 6.0;
        }
    }

    cout << total << endl;
    return 0;
}
