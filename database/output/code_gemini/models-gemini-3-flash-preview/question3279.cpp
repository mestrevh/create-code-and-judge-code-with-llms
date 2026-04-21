/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Otimização de I/O para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double peso, altura;

    // Leitura dos dados de entrada (peso e altura)
    // O uso de while(cin >> ...) garante a leitura correta em casos de múltiplos testes
    while (cin >> peso >> altura) {
        // Cálculo do IMC: peso dividido pelo quadrado da altura
        double imc = peso / (altura * altura);

        // Exibe o IMC formatado com duas casas decimais
        // O uso de fixed e setprecision(2) garante a precisão exigida
        cout << fixed << setprecision(2) << imc << "\n";

        // Classificação do IMC conforme as regras:
        // IMC < 18 ou IMC > 25 ==> atencao
        // IMC entre 18 e 25 ==> normal (intervalo inclusivo [18, 25])
        if (imc < 18.0 || imc > 25.0) {
            cout << "atencao\n";
        } else {
            cout << "normal\n";
        }
    }

    return 0;
}