/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double quantidade[3][4], preco[4];
    
    cout << "Digite a quantidade de ingredientes em cada produto (ovo, farinha, acucar e carne):" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cin >> quantidade[i][j];
    
    cout << "Digite o preco de cada ingrediente (ovo, farinha, acucar e carne):" << endl;
    for (int i = 0; i < 4; i++)
        cin >> preco[i];
    
    double custo[3] = {0, 0, 0};
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            custo[i] += quantidade[i][j] * preco[j];
    
    cout << fixed << setprecision(2);
    cout << "O custo do pastel e R$ " << custo[0] << "." << endl;
    cout << "O custo da empada e R$ " << custo[1] << "." << endl;
    cout << "O custo do kibe e R$ " << custo[2] << "." << endl;

    return 0;
}
