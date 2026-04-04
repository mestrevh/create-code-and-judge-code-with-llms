/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long total_sum = 0;
    for (long long i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        total_sum += val;
    }

    int best_k = 0;
    long long min_diff = -1;
    long long current_fact = 1;

    for (int k = 0; k <= 20; ++k) {
        if (k > 1) {
            current_fact *= k;
        }
        
        if (k == 1) continue;

        long long diff = (total_sum > current_fact) ? (total_sum - current_fact) : (current_fact - total_sum);
        
        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
            best_k = k;
        }
    }

    cout << "Bia arrecadou " << best_k << "! dinheiros e pode jogar tenis!" << endl;

    return 0;
}