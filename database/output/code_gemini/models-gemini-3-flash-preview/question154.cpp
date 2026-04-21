/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    string s;
    cin >> s;

    long long total_panels = 0;
    for (int i = 0; i < C; ++i) {
        if (s[i] == 'P') {
            total_panels += 2;
        } else if (s[i] == 'C') {
            total_panels += 2;
        } else if (s[i] == 'A') {
            total_panels += 1;
        } else if (s[i] == 'D') {
            total_panels += 0;
        }
    }

    cout << total_panels << endl;

    return 0;
}