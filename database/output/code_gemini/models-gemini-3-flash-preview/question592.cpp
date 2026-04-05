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

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    string s;
    if (!(cin >> s)) return 0;

    long long total = 0;
    long long curr = a % b;

    for (char c : s) {
        if (c == '1') {
            total = (total + curr) % b;
        }
        curr = (curr * curr) % b;
    }

    cout << total << "\n";

    return 0;
}