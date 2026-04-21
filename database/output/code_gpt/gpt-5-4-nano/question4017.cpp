/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Y;
    if (!(cin >> Y)) return 0;

    int countY = 0;
    long long sum = 0;
    int cnt = 0;

    for (int i = 0; i < 20; i++) {
        long long x;
        if (!(cin >> x)) break;
        if (x == -1) break;

        if (x == Y) countY++;
        if (x < 15 || x > 20) {
            sum += x;
            cnt++;
        }
    }

    cout << "O número " << Y << " apareceu " << countY << " vez(es)\n";
    if (cnt == 0) {
        cout << "Sem valores para calcular a média";
    } else {
        double avg = (double)sum / cnt;
        cout.setf(std::ios::fixed);
        cout << setprecision(2) << "A média dos números foi de: " << avg;
    }

    return 0;
}