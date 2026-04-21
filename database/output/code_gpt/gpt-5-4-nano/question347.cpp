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

    long long nTri = 1LL * N * (N + 1) / 2;
    long long sumTri = 0;
    for (int i = 1; i <= N; i++) sumTri += 1LL * i * (i + 1) / 2;

    bool evenN = (nTri % 2 == 0);
    bool evenS = (sumTri % 2 == 0);

    char c;
    if (evenN && evenS) c = 'P';
    else if (!evenN && !evenS) c = 'I';
    else c = 'N';

    cout << nTri << " " << sumTri << " " << c << "\n";
    return 0;
}