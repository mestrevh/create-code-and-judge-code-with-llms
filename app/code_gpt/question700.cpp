/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int totalSegundos;
    cin >> totalSegundos;
    
    int horas = totalSegundos / 3600;
    totalSegundos %= 3600;
    
    int minutos = totalSegundos / 60;
    int segundos = totalSegundos % 60;
    
    cout << horas << " h " << minutos << " m " << segundos << " s" << endl;
    
    return 0;
}
