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

    int i = (int)s.size() - 1;
    while (i >= 0 && isspace((unsigned char)s[i])) i--;
    int end = i;
    while (i >= 0 && !isspace((unsigned char)s[i])) i--;
    int start = i + 1;

    if (start <= end) cout << s.substr(start, end - start + 1);
    return 0;
}