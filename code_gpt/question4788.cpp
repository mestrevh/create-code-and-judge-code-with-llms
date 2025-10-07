/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Lutador {
    string nome;
    int grappling, striking, cardio;
};

string resultadoLuta(const Lutador& defensor, const Lutador& desafiante) {
    if (desafiante.grappling > defensor.striking) 
        return desafiante.nome + " ganhou por submissao";
    if (desafiante.striking > defensor.striking) 
        return desafiante.nome + " ganhou por nocaute";
    if (desafiante.striking < defensor.striking) 
        return defensor.nome + " ganhou por nocaute";
    if (defensor.cardio > desafiante.cardio) 
        return defensor.nome + " ganhou por decisao";
    return defensor.nome + " ganhou por decisao";
}

int main() {
    int N;
    cin >> N;
    int melhorEvento = -1, maxNocautes = 0;

    for (int i = 0; i < N; i++) {
        int x, nocautes = 0;
        cin >> x;
        vector<string> resultados;
        
        for (int j = 0; j < x; j++) {
            Lutador defensor, desafiante;
            cin >> defensor.nome >> defensor.grappling >> defensor.striking >> defensor.cardio;
            cin >> desafiante.nome >> desafiante.grappling >> desafiante.striking >> desafiante.cardio;
            string resultado = resultadoLuta(defensor, desafiante);
            resultados.push_back(resultado);
            if (resultado.find("nocaute") != string::npos) nocautes++;
        }

        for (const auto& res : resultados) {
            cout << res << endl;
        }

        if (nocautes > maxNocautes) {
            maxNocautes = nocautes;
            melhorEvento = i + 1;
        }
    }

    cout << "Melhor evento foi " << melhorEvento << endl;

    return 0;
}
