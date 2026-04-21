/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long C;
    if (!(cin >> N >> C)) return 0;

    long long free = 0;
    long long hold = -2000000000LL; // Representing negative infinity

    for (int i = 0; i < N; ++i) {
        long long p;
        cin >> p;
        
        long long next_free = max(free, hold + p);
        long long next_hold = max(hold, free - p - C);
        
        free = next_free;
        hold = next_hold;
    }

    cout << free << "\n";

    return 0;
}

