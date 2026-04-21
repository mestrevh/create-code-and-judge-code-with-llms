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

    int n, s;
    if (!(cin >> n >> s)) {
        return 0;
    }

    int current_balance = s;
    int min_balance = s;

    for (int i = 0; i < n; ++i) {
        int movement;
        if (!(cin >> movement)) break;
        current_balance += movement;
        if (current_balance < min_balance) {
            min_balance = current_balance;
        }
    }

    cout << min_balance << "\n";

    return 0;
}