/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dinheiro;
    int n;
    if (!(cin >> dinheiro >> n)) return 0;

    long long motorBest = -1;
    long long rodaBest = -1;
    long long latariaBest = -1;
    long long motorBestCost = 0;
    long long rodaBestCost = 0;
    long long latariaBestCost = 0;

    for (int i = 0; i < n; i++) {
        string tipo;
        long long custo, perf;
        cin >> tipo >> custo >> perf;
        if (tipo == "Motor") {
            if (perf > motorBest) {
                motorBest = perf;
                motorBestCost = custo;
            }
        } else if (tipo == "Roda") {
            if (perf > rodaBest) {
                rodaBest = perf;
                rodaBestCost = custo;
            }
        } else if (tipo == "Lataria") {
            if (perf > latariaBest) {
                latariaBest = perf;
                latariaBestCost = custo;
            }
        }
    }

    if (motorBest < 0 || rodaBest < 0 || latariaBest < 0) {
        cout << "Nao foi possivel construir uma caranga...";
        return 0;
    }

    long long totalCost = motorBestCost + rodaBestCost + latariaBestCost;
    if (totalCost > dinheiro) {
        cout << "Nao foi possivel construir uma caranga...";
        return 0;
    }

    long long performance = motorBest + rodaBest + latariaBest;
    cout << "Minha nave tem uma performance de " << performance << " pontos\n";
    long long sobra = dinheiro - totalCost;
    if (sobra > 0) {
        cout << "E ainda me sobraram " << sobra << " mangos!";
    }
    return 0;
}