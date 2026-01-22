/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Yoshi {
    string color;
    int price;
    int speed;
    double cost_benefit;

    Yoshi(string c, int p, int s) : color(c), price(p), speed(s) {
        cost_benefit = static_cast<double>(s) / p;
    }
};

int main() {
    int M;
    cin >> M;

    vector<Yoshi> yoshis = {
        {"Verde", 20, 10},
        {"Vermelho", 20, 20},
        {"Azul", 25, 40},
        {"Amarelo", 20, 40}
    };

    Yoshi best("", 0, 0);
    bool can_buy = false;

    for (const auto& y : yoshis) {
        if (y.price <= M) {
            can_buy = true;
            if (y.cost_benefit > best.cost_benefit) {
                best = y;
            }
        }
    }

    if (!can_buy) {
        cout << "Acho que vou a pé :(" << endl;
        return 0;
    }

    double best_cost_benefit = best.cost_benefit;

    for (const auto& y : yoshis) {
        if (y.color == "Verde" && y.price <= M && best_cost_benefit - y.cost_benefit <= 1e-9) {
            best = y;
            break;
        }
    }

    cout << best.color << endl;
    return 0;
}
