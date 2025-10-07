/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Brinquedo {
    string nome;
    int d;
    int a;
};

int calcular_diversao(int d, int a, int t) {
    return d - (t * t) * a;
}

int main() {
    vector<Brinquedo> brinquedos(3);
    for (int i = 0; i < 3; ++i) {
        getline(cin, brinquedos[i].nome);
        cin >> brinquedos[i].d >> brinquedos[i].a;
        cin.ignore(); 
    }

    int max_diversao = -1;
    map<string, int> brinquedos_escolhidos;

    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3 - i; ++j) {
            int k = 3 - i - j;
            int diversao_atual = 0;
            if (i > 0) {
                diversao_atual += calcular_diversao(brinquedos[0].d, brinquedos[0].a, i);
            }
            if (j > 0) {
                diversao_atual += calcular_diversao(brinquedos[1].d, brinquedos[1].a, j);
            }
            if (k > 0) {
                diversao_atual += calcular_diversao(brinquedos[2].d, brinquedos[2].a, k);
            }

            if (diversao_atual > max_diversao) {
                max_diversao = diversao_atual;
                brinquedos_escolhidos.clear();
                if (i > 0) {
                    brinquedos_escolhidos[brinquedos[0].nome] = i;
                }
                if (j > 0) {
                    brinquedos_escolhidos[brinquedos[1].nome] = j;
                }
                if (k > 0) {
                    brinquedos_escolhidos[brinquedos[2].nome] = k;
                }
            }
        }
    }

    cout << "a maior diversao foi: " << max_diversao << endl;
    cout << "indo nos brinquedos: ";

    vector<pair<int, string>> sorted_brinquedos;
    for (auto const& [nome, vezes] : brinquedos_escolhidos) {
        sorted_brinquedos.push_back({-vezes, nome});
    }
    sort(sorted_brinquedos.begin(), sorted_brinquedos.end());
    
    if(brinquedos_escolhidos.size() == 3) {
        for(int i = 0; i < 3; ++i) {
            cout << brinquedos[i].nome << " " << brinquedos_escolhidos[brinquedos[i].nome] << " vez" << (brinquedos_escolhidos[brinquedos[i].nome] > 1 ? "es" : "") << (i < 2 ? ", " : ".");
        }
    }
    else{
        for(int i = 0; i < sorted_brinquedos.size(); ++i) {
                cout << sorted_brinquedos[i].second << " " << -sorted_brinquedos[i].first << " vez" << (-sorted_brinquedos[i].first > 1 ? "es" : "") << (i < sorted_brinquedos.size() - 1 ? ", " : ".");
        }
    }

    cout << endl;

    return 0;
}
