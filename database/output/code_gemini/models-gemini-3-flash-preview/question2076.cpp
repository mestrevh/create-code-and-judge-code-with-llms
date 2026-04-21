/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    if (a > b) swap(a, b);

    long long best_num = a;
    int max_divs = -1;

    for (long long i = a; i <= b; ++i) {
        if (i == 0) {
            if (0 >= max_divs) {
                max_divs = 0;
                best_num = 0;
            }
            continue;
        }
        int current_divs = 0;
        long long j = 1;
        for (; j * j < i; ++j) {
            if (i % j == 0) {
                current_divs += 2;
            }
        }
        if (j * j == i) {
            current_divs++;
        }
        
        if (current_divs >= max_divs) {
            max_divs = current_divs;
            best_num = i;
        }
    }

    cout << best_num << " " << max_divs << "\n";

    return 0;
}