/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string hero, flower;
    long long bowserLife;

    if (!(cin >> hero >> flower >> bowserLife)) return 0;

    int damagePerHit = 0;

    if (hero == "Mario") {
        if (flower == "FireFlower") {
            damagePerHit = 73;
        } else if (flower == "IceFlower") {
            damagePerHit = 50;
        } else if (flower == "BoomerangFlower") {
            damagePerHit = 32;
        }
    } else if (hero == "Luigi") {
        if (flower == "FireFlower") {
            damagePerHit = 70;
        } else if (flower == "IceFlower") {
            damagePerHit = 45;
        } else if (flower == "BoomerangFlower") {
            damagePerHit = 28;
        }
    }

    long long totalDamage = (long long)damagePerHit * 4;

    if (totalDamage >= bowserLife) {
        cout << hero << " conseguiu derrotar o Bowser e salvar a princesa Peach." << endl;
    } else {
        cout << "O Bowser conseguiu escapar." << endl;
    }

    return 0;
}

