/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int freq[101] = {0};
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        if (cin >> a) {
            if (a >= 1 && a <= 100) {
                freq[a]++;
                total_sum += a;
            }
        }
    }

    long long current_sum = 0;
    int taken_count = 0;
    for (int i = 100; i >= 1; --i) {
        while (freq[i] > 0) {
            current_sum += i;
            taken_count++;
            freq[i]--;
            if (current_sum * 2 > total_sum) {
                cout << taken_count << "\n";
                return 0;
            }
        }
    }

    return 0;
}