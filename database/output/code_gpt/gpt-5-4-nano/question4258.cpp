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
    cout << "Digite uma String de números: ";
    if (!getline(cin, s)) return 0;

    vector<string> nums;
    string cur;
    for (size_t i = 0; i <= s.size(); ++i) {
        char c = (i < s.size() ? s[i] : ' ');
        if (c == '-' || isdigit(static_cast<unsigned char>(c))) {
            cur.push_back(c);
        } else {
            if (!cur.empty()) {
                nums.push_back(cur);
                cur.clear();
            }
        }
    }

    cout << "O inverso dos números digitados é: ";
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
        if (i != (int)nums.size() - 1) cout << ", ";
        cout << nums[i];
    }
    if (nums.empty()) cout << "";
    cout << ".";
    return 0;
}