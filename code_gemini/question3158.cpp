/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double N_double, X_double, Y_double;
    int A, B;

    std::cin >> N_double >> A >> X_double >> B >> Y_double;

    long long N_cents = round(N_double * 100.0);
    long long X_cents = round(X_double * 100.0);
    long long Y_cents = round(Y_double * 100.0);

    int gs, gl;
    long long ps, pl;

    if (A < B) {
        gs = A;
        ps = X_cents;
        gl = B;
        pl = Y_cents;
    } else {
        gs = B;
        ps = Y_cents;
        gl = A;
        pl = X_cents;
    }

    long long p1_bought_s = 0, p1_bought_l = 0;

    long long gs_ll = gs;
    long long gl_ll = gl;

    if (gs_ll * pl > gl_ll * ps) {
        p1_bought_s = N_cents / ps;
        long long rem_cents = N_cents % ps;
        p1_bought_l = rem_cents / pl;
    } else if (gl_ll * ps > gs_ll * pl) {
        p1_bought_l = N_cents / pl;
        long long rem_cents = N_cents % pl;
        p1_bought_s = rem_cents / ps;
    } else {
        // Strategy 1: Prioritize small pots
        long long bought_s1 = N_cents / ps;
        long long rem_cents1 = N_cents % ps;
        long long bought_l1 = rem_cents1 / pl;
        long long total_bought1 = bought_s1 + bought_l1;
        long long total_pots1 = total_bought1 + (total_bought1 / 5);

        // Strategy 2: Prioritize large pots
        long long bought_l2 = N_cents / pl;
        long long rem_cents2 = N_cents % pl;
        long long bought_s2 = rem_cents2 / ps;
        long long total_bought2 = bought_s2 + bought_l2;
        long long total_pots2 = total_bought2 + (total_bought2 / 5);

        if (total_pots1 <= total_pots2) {
            p1_bought_s = bought_s1;
            p1_bought_l = bought_l1;
        } else {
            p1_bought_s = bought_s2;
            p1_bought_l = bought_l2;
        }
    }

    long long total_bought_p1 = p1_bought_s + p1_bought_l;
    long long free_pots = total_bought_p1 / 5;

    long long p1_s = p1_bought_s + free_pots;
    long long p1_l = p1_bought_l;

    long long final_s = p1_s;
    long long final_l = p1_l;
    long long extra_paid = 0;

    long long total_pots_p1 = p1_s + p1_l;
    if (total_pots_p1 > 0 && total_pots_p1 % 10 != 0) {
        long long pots_needed = 10 - (total_pots_p1 % 10);
        extra_paid = pots_needed;

        if (ps < pl) {
            final_s += pots_needed;
        } else if (pl < ps) {
            final_l += pots_needed;
        } else {
            if (p1_s > p1_l) {
                final_s += pots_needed;
            } else {
                final_l += pots_needed;
            }
        }
    }

    std::cout << final_s << " " << final_l << " " << extra_paid << std::endl;

    return 0;
}
