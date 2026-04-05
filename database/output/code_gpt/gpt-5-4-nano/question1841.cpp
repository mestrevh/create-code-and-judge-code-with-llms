/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    bool hasAny = false;

    long long sum = 0;
    long long cnt = 0;

    long long minVal = 0, maxVal = 0;
    string minName, maxName;

    while (true) {
        if (!(cin >> name)) break;
        if (name == "sair") break;

        long long score;
        if (!(cin >> score)) break;

        hasAny = true;
        cnt++;
        sum += score;

        if (cnt == 1) {
            minVal = maxVal = score;
            minName = maxName = name;
        } else {
            if (score <= minVal) {
                minVal = score;
                minName = name;
            }
            if (score >= maxVal) {
                maxVal = score;
                maxName = name;
            }
        }
    }

    if (!hasAny) {
        cout << "Nenhum jogador foi registrado.";
        return 0;
    }

    cout << minName << "\n" << maxName << "\n";
    double avg = (double)sum / (double)cnt;
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << avg;
    return 0;
}