/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int glicose, soma = 0, cont = 0;
    
    while (true) {
        cin >> glicose;
        if (glicose == 0) break;
        soma += glicose;
        cont++;
    }
    
    if (cont == 0) return 0; // se não houver entrada, sair
    
    double media = static_cast<double>(soma) / cont;
    
    if (media < 110) 
        cout << "Glicose Normal" << endl;
    else if (media >= 200) 
        cout << "Glicose Muito Alta" << endl;
    else 
        cout << "Glicose Alterada" << endl;

    return 0;
}
