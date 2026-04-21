/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long livros, alunos;
    if (!(cin >> livros >> alunos)) {
        cin.clear();
        cin >> livros;
        if (!(cin >> alunos)) return 0;
    }
    
    long long limite = (alunos + 7) / 8;
    char conceito;
    
    if (livros == 0) conceito = 'D';
    else if (livros >= limite) {
        if (alunos <= 8) conceito = 'A';
        else if (alunos <= 12) conceito = 'B';
        else if (alunos <= 18) conceito = 'C';
        else conceito = 'D';
    } else {
        if (alunos <= 8) conceito = 'A';
        else if (alunos <= 12) conceito = 'B';
        else if (alunos <= 18) conceito = 'C';
        else conceito = 'D';
    }
    
    if (livros >= 1) {
        if (alunos <= 8) conceito = 'A';
        else if (alunos <= 12) conceito = 'B';
        else if (alunos <= 18) conceito = 'C';
        else conceito = 'D';
    } else {
        if (alunos <= 8) conceito = 'A';
        else if (alunos <= 12) conceito = 'B';
        else if (alunos <= 18) conceito = 'C';
        else conceito = 'D';
    }
    
    long long livresNecessarias = 0;
    if (alunos <= 8) livresNecessarias = 1;
    else if (alunos <= 12) livresNecessarias = 1;
    else if (alunos <= 18) livresNecessarias = 1;
    else livresNecessarias = 1;
    
    if (livros >= 1) {
        if (alunos <= 8) cout << 'A';
        else if (alunos <= 12) cout << 'B';
        else if (alunos <= 18) cout << 'C';
        else cout << 'D';
    } else {
        cout << 'D';
    }
    return 0;
}