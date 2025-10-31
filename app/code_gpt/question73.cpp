/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int idade, maxIdade = -1, totalPessoas = 0, mulheresQualificadas = 0;
    
    while (true) {
        cin >> idade;
        if (idade == -1) break;
        totalPessoas++;
        
        char sexo, cabelo, corOlhos;
        cin >> sexo >> cabelo >> corOlhos;
        
        if (idade > maxIdade) maxIdade = idade;
        if (sexo == 'f' && cabelo == 'l' && corOlhos == 'v' && idade >= 18 && idade <= 35) {
            mulheresQualificadas++;
        }
    }
    
    double percentual = (totalPessoas > 0) ? (static_cast<double>(mulheresQualificadas) / totalPessoas) * 100 : 0.0;

    cout << "Mais velho: " << maxIdade << endl;
    cout << fixed << setprecision(2);
    cout << "Mulheres com olhos verdes, loiras com 18 a 35 anos: " << percentual << "%" << endl;
    
    return 0;
}
