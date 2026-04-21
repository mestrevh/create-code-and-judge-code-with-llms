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

    long long cnt[5] = {0, 0, 0, 0, 0};

    for (unsigned char ch : s) {
        char c = (char)ch;
        switch (c) {
            case 'a': case 'A': cnt[0]++; break;
            case 'e': case 'E': cnt[1]++; break;
            case 'i': case 'I': cnt[2]++; break;
            case 'o': case 'O': cnt[3]++; break;
            case 'u': case 'U': cnt[4]++; break;
        }
    }

    cout << "a " << cnt[0] << "\n";
    cout << "e " << cnt[1] << "\n";
    cout << "i " << cnt[2] << "\n";
    cout << "o " << cnt[3] << "\n";
    cout << "u " << cnt[4] << "\n";
    return 0;
}