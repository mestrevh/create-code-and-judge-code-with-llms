/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string norm(const string& s) {
    string t = s;
    for (char &c : t) c = (char)tolower((unsigned char)c);
    return t;
}

static int score(int k, int v) {
    if (k == v) return 0;
    if ((k == 0 && v == 2) || (k == 1 && v == 0) || (k == 2 && v == 1)) return 1;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int ky = 0, vi = 0;

    auto val = [&](const string& s) -> int {
        string t = norm(s);
        if (t == "pedra") return 0;
        if (t == "papel") return 1;
        if (t == "tesoura") return 2;
        return -1;
    };

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        int ka = val(a), vb = val(b);
        if (ka == -1 || vb == -1) continue;
        int r = score(ka, vb);
        if (r == 1) ky++;
        else if (r == -1) vi++;
    }

    if (vi > ky) cout << "VINICIUS VAI LAVAR A LOUÇA!";
    else if (ky > vi) cout << "KYARA VAI LAVAR A LOUÇA!";
    else cout << "OS DOIS VÃO LAVAR A LOUÇA JUNTOS!";
    return 0;
}