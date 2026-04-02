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

    string n;
    while (cin >> n && n != "0") {
        long long total = 0;
        int len = n.length();
        for (int i = 0; i < len; ++i) {
            int digit = n[i] - '0';
            int position = len - i;
            int multiplier = (digit % 2 == 0) ? 2 : 3;
            total += (long long)digit * multiplier * position;
        }
        cout << total << "\n";
    }

    return 0;
}