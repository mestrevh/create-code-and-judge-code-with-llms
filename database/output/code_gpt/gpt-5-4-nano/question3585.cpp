/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tipo;
    if (!(cin >> tipo)) return 0;
    char t = tipo.empty() ? '\0' : tipo[0];

    auto readDouble = [&]() -> double {
        double x;
        cin >> x;
        return x;
    };

    double media = 0.0;
    bool valido = true;
    bool notasCertas = true;

    if (t == 'a') {
        double n1 = readDouble();
        double n2 = readDouble();
        double n3 = readDouble();
        if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10 || n3 < 1 || n3 > 10) notasCertas = false;
        if (notasCertas) media = (n1 + n2 + n3) / 3.0;
    } else if (t == 'p') {
        double w1 = readDouble();
        double w2 = readDouble();
        double w3 = readDouble();
        double n1 = readDouble();
        double n2 = readDouble();
        double n3 = readDouble();
        if (w1 == 0 && w2 == 0 && w3 == 0) {
            notasCertas = false;
        }
        if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10 || n3 < 1 || n3 > 10) notasCertas = false;
        double sw = w1 + w2 + w3;
        if (notasCertas && sw != 0.0) media = (n1 * w1 + n2 * w2 + n3 * w3) / sw;
        else if (notasCertas && sw == 0.0) notasCertas = false;
    } else if (t == 'h') {
        double n1 = readDouble();
        double n2 = readDouble();
        double n3 = readDouble();
        if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10 || n3 < 1 || n3 > 10) notasCertas = false;
        if (notasCertas) {
            media = 3.0 / (1.0 / n1 + 1.0 / n2 + 1.0 / n3);
        }
    } else {
        cout << "Caractere invalido";
        return 0;
    }

    if (!notasCertas || (!isfinite(media))) {
        cout << "Notas erradas";
        return 0;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << media << "\n";

    string situacao;
    if (media >= 7.0 && media <= 10.0) situacao = "Aprovado";
    else if (media >= 0.0 && media <= 4.0) situacao = "Reprovado";
    else if (media > 4.0 && media < 7.0) situacao = "Prova final";
    else situacao = "Notas erradas";

    cout << situacao;
    return 0;
}