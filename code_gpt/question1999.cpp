/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    string gabarito;
    getline(cin, gabarito);
    vector<string> gabaritoVec;
    stringstream ssGabarito(gabarito);
    
    for (string resposta; ssGabarito >> resposta; )
        gabaritoVec.push_back(resposta);
    
    if (gabaritoVec.size() != n) {
        cout << "Gabarito de tamanho errado. Entre com o novo gabarito:\n";
        while (true) {
            getline(cin, gabarito);
            stringstream ssNewGabarito(gabarito);
            gabaritoVec.clear();
            for (string resposta; ssNewGabarito >> resposta; )
                gabaritoVec.push_back(resposta);
            if (gabaritoVec.size() == n)
                break;
            cout << "Gabarito de tamanho errado. Entre com o novo gabarito:\n";
        }
    }
    
    string resposta;
    while (getline(cin, resposta)) {
        if (resposta == "sair")
            break;
        
        stringstream ssResposta(resposta);
        vector<string> respostaVec;
        
        for (string r; ssResposta >> r; )
            respostaVec.push_back(r);
        
        if (respostaVec.size() != n) {
            cout << "Tamanho da resposta diferente do tamanho do gabarito.\n";
            continue;
        }
        
        int acertos = 0;
        for (int i = 0; i < n; i++) {
            if (respostaVec[i] == gabaritoVec[i])
                acertos++;
        }
        
        double percentual = (static_cast<double>(acertos) / n) * 100.0;
        cout << fixed << setprecision(1) << "Percentual de acertos: " << percentual << "\n";
    }
    
    return 0;
}
