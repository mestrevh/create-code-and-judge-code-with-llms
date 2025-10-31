/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int idade;
    cin >> idade;

    if (idade <= 2)
        cout << "O individuo eh um Bebe Jovem Menor de Idade." << endl;
    else if (idade <= 12)
        cout << "O individuo eh uma Crianca Jovem Menor de Idade." << endl;
    else if (idade < 18)
        cout << "O individuo eh um Adolescente Jovem Menor de Idade." << endl;
    else if (idade <= 19)
        cout << "O individuo eh um Jovem Maior de Idade." << endl;
    else if (idade <= 45)
        cout << "O individuo eh um Adulto Maior de Idade." << endl;
    else if (idade < 60)
        cout << "O individuo eh um Adulto de Meia Idade Maior de Idade." << endl;
    else if (idade < 75)
        cout << "O individuo eh um Idoso Maior de Idade." << endl;
    else if (idade <= 90)
        cout << "O individuo eh um Idoso Ansiao Maior de Idade." << endl;
    else
        cout << "O individuo eh um Idoso na Velhice Extrema Maior de Idade." << endl;

    return 0;
}
