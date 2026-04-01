/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string p, a;
    if (!getline(cin, p)) return 0;
    if (!p.empty() && p.back() == '\r') p.pop_back();

    if (!getline(cin, a)) return 0;
    if (!a.empty() && a.back() == '\r') a.pop_back();

    int l_target;
    if (!(cin >> l_target)) return 0;

    int l_atk, atk_stat;
    if (p == "Slowbro") {
        l_atk = 30;
        atk_stat = 50;
    } else if (p == "Dragonite") {
        l_atk = 40;
        atk_stat = 128;
    } else {
        cout << "Pokemon invalido" << endl;
        return 0;
    }

    int power;
    double modifier;
    if (a == "Surf") {
        power = 90;
        modifier = 2.0;
    } else if (a == "Flamethrower") {
        power = 90;
        modifier = 0.5;
    } else if (a == "Grass Knot") {
        power = 120;
        modifier = 0.5;
    } else {
        cout << "Ataque invalido" << endl;
        return 0;
    }

    // Moltres constants: Base=90, IV=9, EV=25600
    // K = ((Base + IV) * 2 + floor(sqrt(EV)/4))
    // K = (99 * 2 + 160 / 4) = 198 + 40 = 238
    int k = 238;
    
    // HP and Defense calculation based on rules: rounded down
    // hp_max = floor((k * l_target) / 100 + l_target + 10)
    // def_target = floor((k * l_target) / 100 + 5)
    int hp_max = (k * l_target) / 100 + l_target + 10;
    int def_target = (k * l_target) / 100 + 5;

    // Pokemon standard damage formula parts:
    // Step 1: floor(2 * LevelAtk / 5) + 2
    int step1 = (2 * l_atk) / 5 + 2;
    // Step 2: floor(Step1 * Power * AtkStat / DefTarget)
    long long step2 = (1LL * step1 * power * atk_stat) / def_target;
    // Step 3: floor(Step2 / 50) + 2
    int step3 = (step2 / 50) + 2;
    // Step 4: floor(Step3 * Modifier)
    int dmg = (int)((double)step3 * modifier);

    // Biu hits 4 times
    int hp_final = hp_max - 4 * dmg;

    if (hp_final <= 0) {
        cout << "Moltres morto" << endl;
    } else if (hp_final < 10) {
        cout << "Moltres capturado" << endl;
    } else {
        cout << "Moltres fugiu" << endl;
    }

    return 0;
}