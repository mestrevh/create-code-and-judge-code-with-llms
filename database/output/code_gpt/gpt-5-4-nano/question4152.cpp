/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    if (!getline(cin, text)) return 0;

    string line;
    if (!getline(cin, line)) return 0;

    char target = 0;
    for (char c : line) {
        if (!isspace((unsigned char)c)) {
            target = c;
            break;
        }
    }

    if (target == 0) {
        cout << 0 << "\n";
        cout << fixed << setprecision(2) << 0.00 << "%";
        return 0;
    }

    int count = 0;
    long long totalLetters = 0;

    for (char c : text) {
        unsigned char uc = (unsigned char)c;
        if (isalpha(uc)) {
            totalLetters++;
            if (tolower(uc) == tolower((unsigned char)target)) count++;
        }
    }

    cout << count << "\n";
    double perc = totalLetters == 0 ? 0.0 : (100.0 * count / totalLetters);
    cout << fixed << setprecision(2) << perc << "%";
    return 0;
}