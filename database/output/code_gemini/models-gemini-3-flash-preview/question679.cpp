/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long K, A, B, C, D;
        if (!(cin >> K >> A >> B >> C >> D)) break;

        long long total_count = 0;
        for (long long x = A; x <= B; ++x) {
            long long y_target = K - x + 1;
            long long y_min = (C > y_target) ? C : y_target;
            
            if (y_min <= D) {
                total_count += (D - y_min + 1);
            }
        }
        cout << total_count << "\n";
    }

    return 0;
}