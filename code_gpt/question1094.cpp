/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int totalA = 0, totalB = 0, totalC = 0, brancos = 0, nulos = 0, votantes = 0;
    
    while (true) {
        int a, b, c, branco, nulo;
        cin >> a >> b >> c >> branco >> nulo;
        if (a == 0 && b == 0 && c == 0 && branco == 0 && nulo == 0) break;
        
        totalA += a;
        totalB += b;
        totalC += c;
        brancos += branco;
        nulos += nulo;
        votantes += (a + b + c + branco + nulo);
    }
    
    int validos = votantes - brancos - nulos;
    char vencedor;
    if (totalA > totalB && totalA > totalC) vencedor = 'A';
    else if (totalB > totalA && totalB > totalC) vencedor = 'B';
    else vencedor = 'C';
    
    cout << "Numero de votantes: " << votantes << endl;
    cout << "Total A: " << totalA << endl;
    cout << "Total B: " << totalB << endl;
    cout << "Total C: " << totalC << endl;
    cout << "Brancos: " << brancos << endl;
    cout << "Nulos: " << nulos << endl;
    cout << "Validos: " << validos << endl;
    cout << "Candidato mais votado: " << (validos == 0 ? "" : string(1, vencedor)) << endl;
    cout << "Eleicao valida? " << (brancos + nulos < validos) << endl;
    cout << "Segundo turno? " << (validos == 0 || (vencedor == 'A' ? totalA : (vencedor == 'B' ? totalB : totalC)) <= validos / 2) << endl;

    return 0;
}
