/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int caixas;
    cin >> caixas;
    
    int total_comprimidos = caixas * 35;
    int comprimidos_por_dia = 4;
    
    int dias = total_comprimidos / comprimidos_por_dia;
    int sobrando = total_comprimidos % comprimidos_por_dia;
    
    cout << dias << endl;
    cout << sobrando << endl;
    
    return 0;
}
