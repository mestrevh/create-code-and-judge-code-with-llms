/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int idade;
    if (!(cin >> idade)) return 0;

    int idadeMin = 18;
    if (idade >= idadeMin) {
        cout << "Voce ja pode tirar habilitacao!\n";
        cout << "Voce tem direito a habilitacao ha " << (idade - idadeMin) << " ano(s)";
    } else {
        cout << "Voce precisa esperar mais " << (idadeMin - idade) << " ano(s)!";
    }
    return 0;
}