/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, K;
    int P;
    if (!(cin >> N >> K >> P)) return 0;

    const int MAXX = 100000;
    if (K <= 0) {
        if (0 <= N && N < K) {
            cout << "Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.";
        } else {
            cout << "Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.";
        }
        return 0;
    }

    int limit = (int)max({(long long)MAXX, N, K});
    limit = min(limit, MAXX);

    vector<int> spf(limit + 1, 0);
    for (int i = 2; i <= limit; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            if ((long long)i * i <= limit) {
                for (long long j = 1LL * i * i; j <= limit; j += i) {
                    if (spf[(int)j] == 0) spf[(int)j] = i;
                }
            }
        }
    }
    if (limit >= 2) {
        for (int i = 2; i <= limit; i++) if (spf[i] == 0) spf[i] = i;
    }

    auto countOddDistinctPrimeFactors = [&](int x) -> int {
        if (x <= 1) return 0;
        int cnt = 0;
        while (x % 2 == 0) x /= 2;
        while (x > 1) {
            int p = spf[x];
            if (p == 0) p = x;
            cnt++;
            while (x % p == 0) x /= p;
        }
        return cnt;
    };

    int first = -1;
    int Q = 0;

    int start = (int)max<long long>(0, N);
    int end = (int)min<long long>(MAXX + 1LL, K);

    for (int x = start; x < end; x++) {
        if (countOddDistinctPrimeFactors(x) == P) {
            if (first == -1) first = x;
            else Q++;
        }
    }

    if (first != -1) {
        cout << first << " " << Q;
    } else {
        cout << "Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.";
    }

    return 0;
}