/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int calcularTiros(int n) {
    if (n == 0) return 0;
    
    int pessoas;
    string status;
    cin >> pessoas >> status;
    
    int tiros;
    if (status == "Conseguiu") {
        tiros = 6;
    } else {
        tiros = 3;
    }
    
    return tiros + calcularTiros(n - 1);
}

int main() {
    int n;
    cin >> n;

    int totalTiros = calcularTiros(n);
    cout << "Foram disparados: " << totalTiros << " tiros" << endl;

    if (totalTiros > 50) {
        cout << "Meus alunos estao estragando tudo! Preciso intervir!" << endl;
    } else {
        cout << "Esta tudo sobre controle, posso passar mais tempo com Raquel..." << endl;
    }

    return 0;
}
