/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    if (!(cin >> X)) return 0;

    long long total = 0;
    for (int i = 0; i < 6; i++) {
        long long V;
        string nome;
        cin >> V >> nome;
        total += V;
    }

    if (total <= X) {
        cout << "Mario gastara um total de R$ " << total << ".";
    } else {
        cout << "Infelizmente nao sera possivel comprar tudo, faltam R$ " << (total - X) << ".";
    }
    return 0;
}