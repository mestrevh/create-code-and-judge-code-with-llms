/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int total_power = 0;
    for (int i = 0; i < 5; ++i) {
        if (cin >> c) {
            total_power += (c - 'a' + 1);
        }
    }

    cout << total_power << "\n";

    return 0;
}