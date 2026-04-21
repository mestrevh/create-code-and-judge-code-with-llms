/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M, L;
    if (!(cin >> M >> L)) return 0;
    int N;
    cin >> N;

    vector<long long> pts = {0,25,18,15,12,10,8,6,4,2,1};

    string nome;
    int pM, pL;
    long long addM = 0, addL = 0;

    vector<string> aheadM, aheadL;

    for (int i = 0; i < N; i++) {
        cin >> nome >> pM >> pL;
        long long sM = (pM >= 1 && pM <= 10) ? pts[pM] : 0;
        long long sL = (pL >= 1 && pL <= 10) ? pts[pL] : 0;

        addM += sM;
        addL += sL;

        if (sM > sL) aheadM.push_back(nome);
        else if (sL > sM) aheadL.push_back(nome);
    }

    long long totalM = M + addM;
    long long totalL = L + addL;

    bool marqWinner = false;

    if (totalM != totalL) {
        marqWinner = totalM > totalL;
    } else {
        marqWinner = aheadM.size() > aheadL.size();
    }

    long long diff = llabs(totalM - totalL);

    if (marqWinner) {
        cout << "O vencedor e Marquinhos com " << diff << " pontos a mais, ficando a frente em ";
        for (auto &s : aheadM) cout << s << "/";
    } else {
        cout << "O vencedor e Luis com " << diff << " pontos a mais, ficando a frente em ";
        for (auto &s : aheadL) cout << s << "/";
    }

    return 0;
}