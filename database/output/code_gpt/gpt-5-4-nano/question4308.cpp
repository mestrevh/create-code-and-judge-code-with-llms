/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> ok, bad;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if ((int)s.size() != 7) {
            bad.push_back(s);
            continue;
        }
        bool good = true;
        int nums = 0, letras = 0;
        for (int j = 0; j < 7; j++) {
            if (j < 4) { 
                if (!isdigit((unsigned char)s[j])) { good = false; break; }
                nums++;
            } else {
                if (!isalpha((unsigned char)s[j]) || !isupper((unsigned char)s[j])) { good = false; break; }
                letras++;
            }
        }
        if (good && nums == 4 && letras == 3) ok.push_back(s);
        else bad.push_back(s);
    }

    cout << ok.size() << " placas:\n";
    for (auto &p : ok) cout << p << "\n";
    cout << bad.size() << " erros:\n";
    for (auto &p : bad) cout << p << "\n";

    return 0;
}