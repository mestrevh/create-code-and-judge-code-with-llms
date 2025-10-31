/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int get_group(int d) {
    if (d == 0) {
        return 25;
    }
    return (d + 3) / 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double V;
    int N, M;

    while (cin >> V >> N >> M && (V != 0.0 || N != 0 || M != 0)) {
        double prize = 0.0;

        if (N % 10000 == M % 10000) {
            prize = V * 3000.0;
        } else if (N % 1000 == M % 1000) {
            prize = V * 500.0;
        } else if (N % 100 == M % 100) {
            prize = V * 50.0;
        } else if (get_group(N % 100) == get_group(M % 100)) {
            prize = V * 16.0;
        }

        cout << fixed << setprecision(2) << prize << endl;
    }

    return 0;
}
