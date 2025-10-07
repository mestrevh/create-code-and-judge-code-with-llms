/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int calcular_nota(const string& resposta_aluno, const string& gabarito) {
    int nota = 0;
    for (int i = 0; i < 5; i++) {
        if (resposta_aluno[i] == gabarito[i]) {
            nota++;
        }
    }
    return nota;
}

int main() {
    map<string, string> respostas;
    string entrada, gabarito;
    
    while (getline(cin, entrada) && entrada != "*") {
        size_t pos = entrada.find(' ');
        string nome = entrada.substr(0, pos);
        string respostas_aluno = entrada.substr(pos + 1);
        respostas[nome] = respostas_aluno;
    }
    
    getline(cin, gabarito);
    
    vector<int> notas;
    for (const auto& par : respostas) {
        notas.push_back(calcular_nota(par.second, gabarito));
    }
    
    int maior = *max_element(notas.begin(), notas.end());
    int menor = *min_element(notas.begin(), notas.end());
    double media = notas.empty() ? 0 : accumulate(notas.begin(), notas.end(), 0.0) / notas.size();
    
    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << fixed << setprecision(2) << media << endl;

    return 0;
}
