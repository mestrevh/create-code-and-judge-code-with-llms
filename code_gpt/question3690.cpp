/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int somarDigitos(int n) {
    int soma = 0;
    while (n) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

int contarDivisores(int n) {
    int cont = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) ++cont;
    }
    return cont;
}

bool primo(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int pontuacaoA = 0, pontuacaoB = 0;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (contarDivisores(a) % 2 == 0) pontuacaoA++;
        if (contarDivisores(b) % 2 == 0) pontuacaoB++;
    }

    int somaA = somarDigitos(pontuacaoA);
    int somaB = somarDigitos(pontuacaoB);
    
    if (primo(somaA) && somaA > 2) pontuacaoA -= 4;
    if (primo(somaA) && somaA == 2) pontuacaoA += 3;

    if (primo(somaB) && somaB > 2) pontuacaoB -= 4;
    if (primo(somaB) && somaB == 2) pontuacaoB += 3;

    if (pontuacaoA == pontuacaoB) pontuacaoA++;

    cout << "Quem ganhou foi aquele time." << endl;
    cout << abs(pontuacaoA - pontuacaoB) << endl;

    return 0;
}
