/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    double sumA = 0.0, sumB = 0.0, sumC = 0.0;
    long long cntA = 0, cntB = 0, cntC = 0;

    for (int i = 0; i < N; i++) {
        char ch;
        double p;
        cin >> ch >> p;
        if (ch == 'A') { sumA += p; cntA++; }
        else if (ch == 'B') { sumB += p; cntB++; }
        else if (ch == 'C') { sumC += p; cntC++; }
    }

    auto avg = [](double s, long long c) -> double {
        if (c == 0) return -numeric_limits<double>::infinity();
        return s / (double)c;
    };

    double a = avg(sumA, cntA);
    double b = avg(sumB, cntB);
    double c = avg(sumC, cntC);

    char bestChar = 'A';
    double bestAvg = a;

    if (b > bestAvg + 1e-12 || (abs(b - bestAvg) <= 1e-12 && b >= bestAvg && bestChar > 'B')) {
        bestChar = 'B';
        bestAvg = b;
    }
    if (c > bestAvg + 1e-12 || (abs(c - bestAvg) <= 1e-12 && bestChar > 'C')) {
        bestChar = 'C';
        bestAvg = c;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "A equipe escolhida foi a " << bestChar << ", com media de: " << bestAvg << "\n";
    return 0;
}