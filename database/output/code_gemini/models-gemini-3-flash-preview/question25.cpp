/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    if (!(cin >> x >> y)) return 0;

    for (int i = x; i <= y; ++i) {
        if (i <= 0) continue;
        
        int last_digit = i % 10;
        int remaining = i / 10;

        if (last_digit != 0) {
            if (remaining > 0 && i % remaining == 0) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}