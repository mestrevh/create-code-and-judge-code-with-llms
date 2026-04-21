/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FilaChar {
    char *v;
    int head, tail, cap;
    int sz;
    FilaChar(int c) : cap(c), head(0), tail(0), sz(0) {
        v = new char[cap];
    }
    ~FilaChar() { delete[] v; }
    bool vazia() const { return sz == 0; }
    void enfileira(char x) {
        v[tail] = x;
        tail = (tail + 1) % cap;
        sz++;
    }
    char desenfileira() {
        char x = v[head];
        head = (head + 1) % cap;
        sz--;
        return x;
    }
};

void removeRepetidosSeguidos(char s[]) {
    int n = (int)strlen(s);
    if (n == 0) return;

    FilaChar q(n + 1);
    char prev = '\0';

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (i == 0 || c != prev) {
            q.enfileira(c);
            prev = c;
        }
    }

    int i = 0;
    while (!q.vazia()) {
        s[i++] = q.desenfileira();
    }
    s[i] = '\0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    if (!getline(cin, str)) return 0;

    if (!str.empty() && str.back() == '\r') str.pop_back();

    int n = (int)str.size();
    char *s = new char[n + 1];
    for (int i = 0; i < n; i++) s[i] = str[i];
    s[n] = '\0';

    removeRepetidosSeguidos(s);

    cout << s << "\n";
    delete[] s;
    return 0;
}