/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    long double m;
    cin >> m;

    vector<long double> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        long double x; 
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        long double x; 
        cin >> x;
        b[i] = x;
    }

    if (m < 0) { cout << -1 << "\n"; return 0; }

    long double lo = 0, hi = 1;
    auto can = [&](long double F)->bool{
        long double fuel = F;
        long double weight = m;

        auto spend = [&](long double consumption, long double rate)->bool{
            long double use = consumption;
            if (use < 0) return false;
            long double cost = use;
            if (fuel + 1e-18L < cost) return false;
            fuel -= cost;
            weight += use * 0 - use; 
            return true;
        };

        for (int i = 1; i <= n; i++) {
            long double need = weight / a[i];
            if (fuel + 1e-12L < need) return false;
            fuel -= need;
            weight += need / b[i]; // wait for landing? incorrect
        }
        return true;
    };

    // Re-derive correctly:
    // For phase "takeoff from i": consume x fuel such that x * a_i = weight_before + x.
    // => x*(a_i - 1) = weight_before => x = weight_before / (a_i - 1)
    // After takeoff, fuel mass x is spent (reduced), so weight_after_takeoff = weight_before - x.
    // But during takeoff, equation indicates x depends on weight_before, and final weight_after_takeoff = weight_before - x.
    // For "landing at i": similarly, x_fuel such that x * b_i = weight_before + x => x = weight_before / (b_i - 1),
    // and weight_after_landing = weight_before - x.
    // Total phases along route: takeoff at 1, landing at 2, takeoff at 2, landing at 3, ..., takeoff at n, landing at 1.
    // We need minimal total fuel F that allows all phases sequentially without running out.
    // Since fuel is consumed exactly per phase based on current weight (which depends on previous consumption),
    // total fuel is deterministic, so minimal is just total required. But we don't know because current weight depends on fuel consumption,
    // and consumption depends only on weight_before which depends on previous consumption; still deterministic starting from m and no extra fuel.
    // However, since Natasha can choose to carry a fuel load at start, weight_before includes that carried fuel.
    // She can only get fuel in Terra (planet 1) initially. So initial carried fuel F affects all subsequent weights.
    // During flight, weight decreases as fuel is burned. Therefore we must find minimal initial F such that during each phase,
    // enough fuel remains to pay required consumption considering that consumption formula uses current weight (including remaining fuel).
    // Let total initial fuel = F. Initial weight W0 = m + F.
    // During takeoff/landing with coefficient c, if current weight is W, fuel consumed x satisfies x*c = W + x => x = W/(c-1).
    // After burning x, new remaining fuel = (W - m) - x, and new weight W' = W - x.
    // So weight update: W' = W - W/(c-1) = W * (1 - 1/(c-1)) = W*( (c-2)/(c-1) ) . But note W includes m+remaining fuel.
    // This depends only on W, not separately on m.
    // Yet consumption x uses W. Great: deterministic evolution of W given F.
    // We just need minimal F so that fuel never negative; equivalently remaining fuel >=0 at all times,
    // meaning W >= m at all times.
    // Because remaining fuel = W - m.
    // So we need to ensure W never drops below m before completion.
    // Since after each phase, W becomes W' = W - W/(c-1) = W*(c-2)/(c-1).
    // But we must also ensure c>1; if c==1 impossible unless W==0.
    // For m>=1, c==1 makes division by 0. We'll treat infeasible.
    // Total requirement: find minimal F such that after performing all phases, at the end landing on 1 can be done.
    // During final landing, we also need fuel to cover consumption; hence weight just before final landing must be >= m (always).
    // After final landing, remaining fuel could be >=0, which will be true if consumption accounted.
    // We'll binary search F with can(F) simulating W and ensuring W >= m at each step and fuel >= required.
    // Implementation: in each phase coefficient c:
    // If c<=1, infeasible.
    // consume x = W/(c-1). Need x <= remaining fuel = W - m.
    // But since consume derived from W, check holds: x <= W-m <=> W/(c-1) <= W-m.
    // If not, not enough fuel.
    // Update W -= x.
    // If at any time remaining fuel < 0, fail.
    // Total phases count: 2n (takeoff at i for i=1..n, landing at i for i=2..n plus landing at 1).
    // Landing coefficients b[planet]. Takeoff coefficients a[planet].
    // Phase order:
    // takeoff at 1 (a1), landing at 2 (b2), takeoff at 2 (a2), landing at 3 (b3), ..., takeoff at n (an), landing at 1 (b1).
    // That is for i=1..n-1: takeoff a[i], landing b[i+1]; after loop: takeoff a[n], landing b[1].
    // Also for n=2: takeoff a1, landing b2, takeoff a2, landing b1.

    vector<long double> coeff;
    vector<int> isTakeoff;
    coeff.reserve(2*n);
    for (int i = 1; i <= n-1; i++) {
        coeff.push_back(a[i]);
        coeff.push_back(b[i+1]);
    }
    coeff.push_back(a[n]);
    coeff.push_back(b[1]);

    auto can = [&](long double F)->bool{
        long double W = m + F;
        if (W + 1e-18L < m) return false;
        for (int k = 0; k < (int)coeff.size(); k++) {
            long double c = coeff[k];
            if (c <= 1.0L + 1e-18L) return false;
            long double x = W / (c - 1.0L);
            long double fuelRemain = W - m;
            if (x > fuelRemain + 1e-12L) return false;
            W -= x;
            if (W + 1e-12L < m) return false;
        }
        return true;
    };

    if (!can(0.0L)) {
        lo = 0;
    } else {
        cout.setf(std::ios::fixed); cout<<setprecision(2)<<0.00<<"\n";
        return 0;
    }

    hi = 1;
    while (!can(hi)) {
        hi *= 2;
        if (hi > 1e10L) break;
    }

    if (!can(hi)) {
        cout << -1 << "\n";
        return 0;
    }

    for (int it = 0; it < 200; it++) {
        long double mid = (lo + hi) / 2;
        if (can(mid)) hi = mid;
        else lo = mid;
    }

    if (hi < 0) { cout << -1 << "\n"; return 0; }
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)hi + 1e-9 << "\n";
    return 0;
}