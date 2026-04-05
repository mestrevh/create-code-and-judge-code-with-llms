/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double V;
    long long N, M;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> V >> N >> M) {
        if (V == 0 && N == 0 && M == 0) break;

        auto val4 = [](long long x) -> array<int,4> {
            long long t = x % 10000;
            return { (int)(t / 1000), (int)(t / 100 % 10), (int)(t / 10 % 10), (int)(t % 10) };
        };
        auto v4 = val4(N);
        auto m4 = val4(M);

        int prizeMul = 0;
        if (v4[0]==m4[0] && v4[1]==m4[1] && v4[2]==m4[2] && v4[3]==m4[3]) {
            prizeMul = 3000;
        } else if (v4[1]==m4[1] && v4[2]==m4[2] && v4[3]==m4[3]) {
            prizeMul = 500;
        } else if (v4[2]==m4[2] && v4[3]==m4[3]) {
            prizeMul = 50;
        } else {
            auto animalIndex = [](long long x) -> int {
                long long last2 = x % 100;
                int tens = (int)(last2 / 10);
                int ones = (int)(last2 % 10);
                int val = (tens * 10 + ones) % 100;
                int group = val / 4;
                return group;
            };

            long long last2N = N % 100;
            long long last2M = M % 100;

            int groupN = (int)((last2N) / 4);
            int groupM = (int)((last2M) / 4);

            if (groupN == groupM) prizeMul = 16;
        }

        double ans = V * prizeMul;
        cout << ans + 1e-9 << "\n";
    }
    return 0;
}