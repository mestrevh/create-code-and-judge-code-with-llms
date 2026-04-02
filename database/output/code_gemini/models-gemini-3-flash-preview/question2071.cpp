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
    while (cin >> n && n != 0) {
        long long max_val = -1;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            long long current_val;
            cin >> current_val;
            if (current_val > max_val) {
                max_val = current_val;
                count = 1;
            } else if (current_val == max_val) {
                count++;
            }
        }
        cout << max_val << " " << count << "\n";
    }

    return 0;
}