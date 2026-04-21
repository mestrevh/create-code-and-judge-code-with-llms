/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Sol {
    int a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> out;
    int n;
    bool firstBlock = true;

    while (cin >> n) {
        if (n == 0) break;

        vector<Sol> sols;
        for (int permNum = 0; permNum < 10; permNum++) {
        }

        array<int,10> digits{};
        for (int i = 0; i < 10; i++) digits[i] = i;

        int maxIndex = 1 << 10;

        for (int maskA = 0; maskA < maxIndex; maskA++) {
            if (__builtin_popcount((unsigned)maskA) != 5) continue;
            int maskB = ((1<<10)-1) ^ maskA;

            vector<int> A;
            vector<int> B;
            A.reserve(5);
            B.reserve(5);
            for (int d = 0; d <= 9; d++) {
                if (maskA & (1<<d)) A.push_back(d);
                else B.push_back(d);
            }

            sort(A.begin(), A.end());
            sort(B.begin(), B.end());

            vector<int> usedA = A;
            vector<int> usedB = B;

            sort(usedA.begin(), usedA.end());
            do {
                int a = 0;
                for (int i = 0; i < 5; i++) a = a*10 + usedA[i];

                sort(usedB.begin(), usedB.end());
                do {
                    int b = 0;
                    for (int i = 0; i < 5; i++) b = b*10 + usedB[i];

                    if (b == 0) continue;
                    if (a / b == n && a == n * b) {
                        sols.push_back({a, b});
                    }
                } while (next_permutation(usedB.begin(), usedB.end()));
            } while (next_permutation(usedA.begin(), usedA.end()));
        }

        sort(sols.begin(), sols.end(), [](const Sol& x, const Sol& y){
            if (x.a != y.a) return x.a < y.a;
            return x.b < y.b;
        });

        if (!firstBlock) cout << "\n";
        firstBlock = false;

        if (sols.empty()) {
            cout << "There are no solutions for " << n << ".\n";
        } else {
            for (auto &s : sols) {
                ostringstream na, nb;
                na << setw(5) << setfill('0') << s.a;
                nb << setw(5) << setfill('0') << s.b;
                cout << na.str() << " / " << nb.str() << " = " << n << "\n";
            }
        }
    }

    return 0;
}