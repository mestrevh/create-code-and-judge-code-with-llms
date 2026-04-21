/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string gabarito = "ABCDEEDCBA";
    int nota = 0;

    for (int i = 0; i < 10; i++) {
        string resp;
        if (!(cin >> resp)) return 0;
        char c = resp.empty() ? '\0' : resp[0];
        if (c == gabarito[i]) nota++;
    }

    cout << nota;
    return 0;
}