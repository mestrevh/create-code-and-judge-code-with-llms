/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n < 1) return 0;

    vector<int> lens(n + 1);
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        int temp = i;
        if (temp == 0) {
            count = 1;
        } else {
            while (temp > 0) {
                temp /= 10;
                count++;
            }
        }
        lens[i] = count;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int spaces = lens[j + 1] + 1;
            for (int k = 0; k < spaces; ++k) {
                cout.put(' ');
            }
        }
        for (int j = i; j < n; ++j) {
            cout << (j + 1);
            if (j < n - 1) {
                cout.put(' ');
            }
        }
        cout.put('\n');
    }

    return 0;
}