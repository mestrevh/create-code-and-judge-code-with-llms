/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M;
    cin >> M;
    float RyuLife, KenLife;
    cin >> RyuLife >> KenLife;

    vector<vector<float>> Ryu(M, vector<float>(M));
    vector<vector<float>> Ken(M, vector<float>(M));

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            cin >> Ryu[i][j];

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            cin >> Ken[i][j];

    int N;
    cin >> N;
    float RyuAttack = 0, RyuDefense = 0, KenAttack = 0, KenDefense = 0;

    for (int i = 0; i < M; ++i) {
        RyuAttack += Ryu[i][i];
        RyuDefense += Ryu[i][M - 1 - i];
        KenAttack += Ken[i][i];
        KenDefense += Ken[i][M - 1 - i];
    }

    string action;
    for (int i = 0; i < N; ++i) {
        char R, K;
        cin >> R >> K;

        if (R == 'A' && K == 'A') {
            if (RyuAttack > KenAttack) {
                KenLife -= (RyuAttack - KenAttack);
            } else {
                RyuLife -= (KenAttack - RyuAttack);
            }
        } 
        else if (R == 'A' && K == 'D') {
            if (RyuAttack > KenDefense) {
                KenLife -= (RyuAttack - KenDefense) / 2;
            }
        } 
        else if (R == 'D' && K == 'A') {
            if (KenAttack > RyuDefense) {
                RyuLife -= (KenAttack - RyuDefense) / 2;
            }
        }
    }

    if (RyuLife > KenLife) {
        cout << "Ryu ganhou a batalha." << endl;
    } else if (KenLife > RyuLife) {
        cout << "Ken ganhou a batalha." << endl;
    } else {
        cout << "Houve empate." << endl;
    }

    return 0;
}
