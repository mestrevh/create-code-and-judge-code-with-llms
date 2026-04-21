/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Estrutura para representar um número complexo z = a + bi.
 */
struct Complex {
    long long a; // Parte real
    long long b; // Parte imaginária
};

/**
 * Função que imprime um número complexo na forma a+bi.
 * De acordo com os casos de teste, o formato não utiliza espaços extras.
 */
void imprimir(Complex z) {
    cout << z.a << (z.b >= 0 ? "+" : "") << z.b << "i" << "\n";
}

/**
 * Função que calcula a soma de dois números complexos.
 * (a + bi) + (c + di) = (a + c) + (b + d)i
 */
Complex somar(Complex z1, Complex z2) {
    Complex res;
    res.a = z1.a + z2.a;
    res.b = z1.b + z2.b;
    return res;
}

/**
 * Função que calcula a multiplicação de dois números complexos.
 * (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
 */
Complex multiplicar(Complex z1, Complex z2) {
    Complex res;
    res.a = (z1.a * z2.a) - (z1.b * z2.b);
    res.b = (z1.a * z2.b) + (z1.b * z2.a);
    return res;
}

int main() {
    // Otimização de I/O padrão para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Complex z1, z2;

    // Leitura dos dois números complexos
    // Cada número é composto por dois valores: real e imaginário
    if (cin >> z1.a >> z1.b >> z2.a >> z2.b) {
        // Cálculo da soma
        Complex resultadoSoma = somar(z1, z2);
        
        // Cálculo da multiplicação
        Complex resultadoMulti = multiplicar(z1, z2);

        // Saída seguindo estritamente o formato dos casos de teste
        cout << "Soma: ";
        imprimir(resultadoSoma);
        cout << "Multi: ";
        imprimir(resultadoMulti);
    }

    return 0;
}