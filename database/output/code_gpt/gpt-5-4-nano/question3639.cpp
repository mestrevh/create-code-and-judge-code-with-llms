/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    if (!cin && s.empty()) return 0;

    long long totalLetters = 0;
    long long cnt[5] = {0, 0, 0, 0, 0}; 

    for (unsigned char ch : s) {
        char c = (char)tolower(ch);
        if (c >= 'a' && c <= 'z') {
            totalLetters++;
            if (c == 'a') cnt[0]++;
            else if (c == 'e') cnt[1]++;
            else if (c == 'i') cnt[2]++;
            else if (c == 'o') cnt[3]++;
            else if (c == 'u') cnt[4]++;
        }
    }

    long long vowels = cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4];
    double perc = 0.0;
    if (totalLetters > 0) perc = (double)vowels * 100.0 / (double)totalLetters;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    cout << "a " << cnt[0] << "\n";
    cout << "e " << cnt[1] << "\n";
    cout << "i " << cnt[2] << "\n";
    cout << "o " << cnt[3] << "\n";
    cout << "u " << cnt[4] << "\n";
    cout << perc << "%";

    return 0;
}