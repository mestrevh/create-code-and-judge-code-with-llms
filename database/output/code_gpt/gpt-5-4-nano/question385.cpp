/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string matricula;
    double cre;
    string menorMat;
    bool tem = false;
    double menorCre = 0.0;
    double soma = 0.0;
    long long cont = 0;
    
    while (cin >> matricula) {
        if (matricula == "999") break;
        if (!(cin >> cre)) break;
        
        if (!tem || cre < menorCre) {
            tem = true;
            menorCre = cre;
            menorMat = matricula;
        }
        soma += cre;
        cont++;
    }
    
    if (cont == 0) return 0;
    
    double media = soma / cont;
    cout << menorMat << "\n" << fixed << setprecision(2) << media << "\n";
    return 0;
}