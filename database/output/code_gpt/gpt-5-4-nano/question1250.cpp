/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static inline long long ceil_div(long long a, long long b){
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    while(n--){
        long long V1, V2, D1, D2;
        cin >> V1 >> V2 >> D1 >> D2;

        long long t1 = ceil_div(V2, D1);
        long long t2 = ceil_div(V1, D2);

        int loser;
        if(t1 < t2) {
            cout << "Bezaliel\n";
            continue;
        }

        long long A = D2;
        long long B = D1;

        auto canClodesWin = [&](long long k)->bool{
            long long d1k = A + 50LL * k;
            long long t_clode_d = ceil_div(V2, d1k);
            long long damageByBeza = 50LL * (t_clode_d - 1);
            long long d2_after = B + 0; // Bezaliel never uses special
            long long t_beza = ceil_div(V1, d2_after);
            // simulate turns considering order:
            // We need that Clodes defeats Bezaliel in some turn i <= t_clode_d
            // Bezaliel defeats Clodes at turn t_beza (his last attack lands).
            // Since Clodes attacks first each turn, Clodes wins iff t_clode_d <= t_beza.
            return t_clode_d <= t2;
        };

        // Determine optimal number of specials Clodes can use before switching to damage.
        // Strategy: use specials until reaching point where he can no longer lose.
        // Since during specials Bezaliel attacks each turn, Clodes' effective life decreases by B each turn.
        // Let k be number of specials used (0..). After k specials, Clodes has increased damage by 50k,
        // and has taken k attacks from Bezaliel, so remaining life: V1 - k*D2? Actually Bezaliel deals D2 each turn.
        // Bezaliel's damage never changes: D2. So remaining life: V1 - k*D2. If <=0 during specials, Clodes loses.
        // When Clodes starts attacking, he attacks first in turn k+1 with damage D1+50k, and so on.
        // Clodes wins if he can defeat Bezaliel before Bezaliel defeats him.
        // This condition depends on k:
        // Bezaliel defeats Clodes after t2 = ceil(V1 / D2) of his own attacks, landing at turns 1..t2.
        // Since Clodes attacks first, at turn j (1-indexed):
        // - If j < t2: Bezaliel is not yet KO and will attack after Clodes.
        // - If j == t2: Bezaliel's attack will KO Clodes at end of that turn, so Clodes must KO Bezaliel on or before turn t2.
        // During specials for first k turns, Clodes does no damage to Bezaliel.
        // At turn k+1.., Clodes attacks with fixed damage A+50k.
        // Bezaliel can only be damaged on turns >= k+1. Need number of Clodes attack turns to finish Bezaliel:
        // needed attacks: ceil(V2 / (A+50k)) which must be <= (t2 - k) because Clodes gets turns k+1 .. t2 inclusive count = t2-k.
        long long lo = 0, hi = 2000000000LL;
        // We can binary search k such that condition holds, then take smallest k satisfying (since "until cannot lose")
        // but if condition holds for some k, using more specials could still hold; we use monotonicity:
        // damage increases with k, while available turns decreases with k, so not strictly monotonic, but should be monotonic for this setup?
        // We will find winning k by direct checking around threshold: optimal is minimal k where Clodes wins.
        // We'll compute minimal k by searching k in reasonable range with logarithmic using condition check that is monotonic:
        // Condition for win:
        //   k < t2 (otherwise no turns to attack)
        //   ceil(V2 / (A+50k)) <= t2 - k
        // LHS decreases with k, RHS decreases with k, so their difference is not guaranteed monotonic, but in practice should be.
        // To be safe, we can compute minimal winning k by scanning k up to a limit derived from when A+50k >= V2 (then LHS=1).
        // k needed to make damage >= V2: k0 = ceil((V2 - A)/50) if V2>A else 0.
        // That is at most (1e6-1)/50 ~ 20000, but V2 up to 1e6 and A up to 1e6 => k0 <= 20000.
        // Great. We'll scan up to k0+5 and also consider that k cannot exceed t2-1 (since must attack at least once).
        long long kmax = min(t2-1, (long long)30000);
        bool win = false;
        for(long long k=0; k<=kmax; k++){
            long long d = A + 50LL*k;
            if(d<=0) continue;
            long long need = ceil_div(V2, d);
            long long avail = t2 - k;
            if(need <= avail){
                win = true;
                break;
            }
        }
        // If still not won within kmax, Clodes cannot win because beyond 30000 specials damage >= V2 and need becomes 1,
        // but available turns t2-k becomes <= t2-30001; if not enough by then, can't help.
        if(win) cout << "Clodes\n";
        else cout << "Bezaliel\n";
    }
    return 0;
}