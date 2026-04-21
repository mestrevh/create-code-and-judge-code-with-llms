/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        long long total_extra = 0;
        int cards[] = {1, 10, 100, 1000, 10000};
        
        for (int i = 0; i < m; ++i) {
            int b, d_card;
            if (!(cin >> b >> d_card)) break;
            
            long long others_sum = 0;
            for (int j = 1; j < n; ++j) {
                int other;
                cin >> other;
                others_sum += other;
            }

            int actual_gain = 0;
            if ((long long)d_card + others_sum <= (long long)b) {
                actual_gain = d_card;
            }

            int best_possible_gain = 0;
            for (int k = 0; k < 5; ++k) {
                if ((long long)cards[k] + others_sum <= (long long)b) {
                    best_possible_gain = cards[k];
                }
            }

            total_extra += (long long)(best_possible_gain - actual_gain);
        }
        cout << total_extra << "\n";
    }

    return 0;
}