/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char x;
    if (!(cin >> x)) return 0;

    char c = (char)tolower((unsigned char)x);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "A letra " << x << " eh uma vogal\n";
    } else if (isalpha((unsigned char)x)) {
        cout << "A letra " << x << " eh uma consoante\n";
    } else {
        cout << "O caractere " << x << " nao eh nem consoante nem vogal\n";
    }
    return 0;
}