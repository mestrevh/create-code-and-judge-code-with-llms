/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <tuple>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

struct Result {
    ll p, m, g;
};

map<pair<ll, ll>, Result> memo;

Result solve_surface(ll L, ll W) {
    if (L == 0 || W == 0) {
        return {0, 0, 0};
    }
    if (L > W) swap(L, W);
    if (memo.count({L, W})) {
        return memo[{L, W}];
    }

    Result best_res = {-1, -1, -1};
    ll min_cost = -1;

    // Option G
    if (L >= 30 && W >= 30) {
        ll num_g = (L / 30) * (W / 30);
        Result rem1 = solve_surface(L, W % 30);
        Result rem2 = solve_surface(L % 30, (W / 30) * 30);
        Result current_res = {rem1.p + rem2.p, rem1.m + rem2.m, num_g + rem1.g + rem2.g};
        ll current_cost = current_res.p * 2 + current_res.m * 15 + current_res.g * 50;
        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
            best_res = current_res;
        }
    }

    // Option M
    if (L >= 15 && W >= 15) {
        ll num_m = (L / 15) * (W / 15);
        Result rem1 = solve_surface(L, W % 15);
        Result rem2 = solve_surface(L % 15, (W / 15) * 15);
        Result current_res = {rem1.p + rem2.p, num_m + rem1.m + rem2.m, rem1.g + rem2.g};
        ll current_cost = current_res.p * 2 + current_res.m * 15 + current_res.g * 50;
        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
            best_res = current_res;
        }
    }

    // Option P
    if (L >= 5 && W >= 5) {
        ll num_p = (L / 5) * (W / 5);
        Result current_res = {num_p, 0, 0};
        ll current_cost = current_res.p * 2;
         if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
            best_res = current_res;
        }
    }
    
    return memo[{L, W}] = best_res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double X, Y, Z;
    ll P, M, G;

    while (cin >> X >> Y >> Z && (X != 0 || Y != 0 || Z != 0)) {
        cin >> P >> M >> G;

        memo.clear();

        ll Xc = round(X * 100);
        ll Yc = round(Y * 100);
        ll Zc = round(Z * 100);

        Result bottom_res = solve_surface(Xc, Yc);
        Result wall1_res = solve_surface(Xc, Zc);
        Result wall2_res = solve_surface(Yc, Zc);

        ll p_ans = bottom_res.p + 2 * wall1_res.p + 2 * wall2_res.p;
        ll m_ans = bottom_res.m + 2 * wall1_res.m + 2 * wall2_res.m;
        ll g_ans = bottom_res.g + 2 * wall1_res.g + 2 * wall2_res.g;
        
        if (g_ans > G) {
            m_ans += (g_ans - G) * 4;
            g_ans = G;
        }
        if (m_ans > M) {
            p_ans += (m_ans - M) * 9;
            m_ans = M;
        }

        if (p_ans > P) {
            cout << "impossivel\n";
        } else {
            cout << p_ans << " " << m_ans << " " << g_ans << "\n";
        }
    }

    return 0;
}
