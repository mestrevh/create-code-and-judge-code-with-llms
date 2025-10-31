/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    int bestDamage = 0, bestIndex = -1, bestIncrease = 0;

    for (int i = 1; i <= N; i++) {
        int K, B;
        cin >> K >> B;

        int newDamage = D + K * B;
        int increase = static_cast<int>(ceil(((double)(newDamage - D) / D) * 100));

        cout << "ELEMENTO #" << i << endl;
        cout << "DANO: " << newDamage << endl;
        cout << "AUMENTO: " << increase << "%" << endl;
        cout << endl;

        if (newDamage > bestDamage) {
            bestDamage = newDamage;
            bestIndex = i;
            bestIncrease = increase;
        }
    }

    cout << "ELEMENTO ESCOLHIDO: #" << bestIndex << endl;
    cout << "NOVO DANO DA ESPADA: " << bestDamage << endl;
    cout << "AUMENTO: " << bestIncrease << "%" << endl;

    return 0;
}
