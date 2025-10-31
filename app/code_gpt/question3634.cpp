/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> bongzilla(N), kingcoca(N);
    for (int i = 0; i < N; i++) cin >> bongzilla[i];
    for (int i = 0; i < N; i++) cin >> kingcoca[i];
    double lifeB = 0, lifeK = 0;
    cin >> lifeB >> lifeK;

    cout << fixed << setprecision(2) << lifeB << " " << lifeK << endl;

    for (int turn = 0; turn < N; turn++) {
        double damageB = bongzilla[turn];
        double damageK = kingcoca[turn];
        double healB = 0, healK = 0;

        if (turn > 0) {
            if (isPrime(bongzilla[turn - 1]) && damageB % 2 == 0) {
                damageB *= 2; // Raio
            }
            if (kingcoca[turn - 1] % 2 == 0 && isPrime(damageK)) {
                healK = damageK; // Frenesi
            }
        }

        if (isPrime(damageB)) {
            lifeK -= damageB * 1.5;
        } else if (damageB % 2 == 0) {
            lifeK -= damageB;
            healB += damageB / 2;
        } else {
            lifeK -= damageB;
        }

        if (turn > 0 && healK > 0) {
            lifeK += healK; // Aplicar cura do Frenesi
        }

        if (isPrime(damageK)) {
            lifeB -= damageK * 1.5;
        } else if (damageK % 2 == 0) {
            lifeB -= damageK;
            healB += damageK; // Cura
        } else {
            lifeB -= damageK;
        }

        lifeB += healB; // Aplicar cura do ataque de Bongzilla

        if (lifeB <= 0 || lifeK <= 0) {
            break; // Termina a batalha
        }

        cout << "TURNO " << turn + 1 << ": " << lifeB << " " << lifeK << endl;
    }

    if (lifeB <= 0 && lifeK <= 0) {
        cout << "EMPATE." << endl;
    } else if (lifeB <= 0) {
        cout << "VITORIA DO KINGCOCA." << endl;
    } else if (lifeK <= 0) {
        cout << "VITORIA DO BONGZILLA." << endl;
    } else {
        cout << "EMPATE." << endl;
    }

    return 0;
}
