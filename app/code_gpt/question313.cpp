/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double M[12][12];
    int L;
    char T;
    double sum = 0.0;
    int count = 0;

    cin >> L >> T;

    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            cin >> M[i][j];

    for (int j = 0; j < 12; ++j) {
        sum += M[L][j];
        count++;
    }

    if (T == 'M') {
        sum /= count;
    }

    cout << fixed << setprecision(1) << sum << endl;
    return 0;
}
