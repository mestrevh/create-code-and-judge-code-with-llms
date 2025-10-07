/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

double calculateCost(int type, int quantity) {
    double base_price_per_100ml = 0.0;
    double discount_percentage = 0.0;

    switch (type) {
        case 1: // Shake Crausk
            base_price_per_100ml = 2.0;
            if (quantity <= 500) {
                discount_percentage = 0.05;
            } else {
                discount_percentage = 0.10;
            }
            break;
        case 2: // Shake Extravaganza
            base_price_per_100ml = 3.0;
            if (quantity <= 500) {
                discount_percentage = 0.03;
            } else {
                discount_percentage = 0.06;
            }
            break;
        case 3: // Shake Calamidade
            base_price_per_100ml = 4.0;
            if (quantity <= 500) {
                discount_percentage = 0.04;
            } else {
                discount_percentage = 0.08;
            }
            break;
    }

    int units = quantity / 100;
    double total_base_price = units * base_price_per_100ml;
    double final_cost = total_base_price * (1.0 - discount_percentage);
    
    return final_cost;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int s1, s2;
    int q1, q2;
    int r;

    std::cin >> s1 >> s2 >> q1 >> q2 >> r;

    double cost1 = calculateCost(s1, q1);
    double cost2 = calculateCost(s2, q2);
    double total_cost = cost1 + cost2;

    if (total_cost > 1e-9) {
        double money = static_cast<double>(r);
        int multiplier = static_cast<int>(floor(money / total_cost));

        if (multiplier >= 2) {
            printf("Yeah! Shake %d vezes mais.\n", multiplier);
        } else if (multiplier == 1) {
            printf("De qualquer forma matamos nossa sede de shake.\n");
        } else {
            printf("Carambolas! O shake JA ERA.\n");
        }
    } else {
        printf("De qualquer forma matamos nossa sede de shake.\n");
    }

    return 0;
}
