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

    vector<unsigned long long> a;
    a.reserve(N - 1);
    for (int i = 0; i < N - 1; i++) {
        unsigned long long x;
        cin >> x;
        a.push_back(x);
    }

    auto fib = [](int k) -> unsigned long long {
        if (k <= 2) return 1ULL;
        unsigned long long f1 = 1ULL, f2 = 1ULL;
        for (int i = 3; i <= k; i++) {
            unsigned long long f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    };

    unsigned long long missingVal = 0;
    int missingPos = 1;

    int pos = 0;
    for (int i = 1; i <= N; i++) {
        unsigned long long expected = fib(i);
        if (pos < (int)a.size() && a[pos] == expected) {
            pos++;
        } else {
            missingVal = expected;
            missingPos = i;
            break;
        }
    }

    cout << "Sherliro achou o termo " << missingVal << " que deveria estar na posicao " << missingPos;
    return 0;
}