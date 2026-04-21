/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

size_t tamstr(char* p) {
    char* q = p;
    while (*p != '\0') p++;
    return (size_t)(p - q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s == "FIM") break;
        char arr[10 + 1];
        size_t n = min<size_t>(s.size(), 10);
        for (size_t i = 0; i < n; i++) arr[i] = s[i];
        arr[n] = '\0';
        cout << tamstr(arr) << "\n";
    }
    return 0;
}