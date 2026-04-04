/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    double p_qty, m_qty, g_qty;
    cin >> p_qty >> m_qty >> g_qty;

    double base_p = 25.0;
    double base_m = 40.0;
    double base_g = 70.0;

    double final_p, final_m, final_g;
    double interest_p = 0, interest_m = 0, interest_g = 0;

    if (is_prime(n)) {
        final_p = base_p * pow(1.125, n);
        final_m = base_m * pow(1.29, n);
        final_g = base_g * pow(1.22, n);
        
        interest_p = final_p - base_p;
        interest_m = final_m - base_m;
        interest_g = final_g - base_g;
    } else {
        final_p = base_p;
        final_m = base_m;
        final_g = base_g;
        interest_p = 0;
        interest_m = 0;
        interest_g = 0;
    }

    double total_interest = (p_qty * interest_p) + (m_qty * interest_m) + (g_qty * interest_g);
    double total_revenue = (p_qty * final_p) + (m_qty * final_m) + (g_qty * final_g);

    cout << fixed << setprecision(2) << total_interest << "\n";
    cout << fixed << setprecision(2) << total_revenue << "\n";

    return 0;
}