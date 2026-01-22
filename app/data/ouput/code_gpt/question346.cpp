/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    
    if (C <= 0) {
        cout << "Nao possuem caminhoes para fazer a coleta!" << endl;
        return 0;
    }
    
    int totalLixo = 0;
    
    for (int i = 0; i < N; ++i) {
        int apartamentos;
        cin >> apartamentos;
        if (apartamentos > 0) {
            int vidro, papel, plastico, metal;
            cin >> vidro >> papel >> plastico >> metal;
            totalLixo += (vidro + papel + plastico + metal) * apartamentos;
        }
    }
    
    int volumeCaminhao = 3000; // 3 metros cúbicos em litros
    int viagens = (totalLixo + volumeCaminhao - 1) / volumeCaminhao;
    
    cout << viagens / C + (viagens % C != 0) << endl;
    
    return 0;
}
