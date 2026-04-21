/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int K;
    while (true) {
        if (!(cin >> N >> K)) return 0;
        vector<int> L(K);
        for (int i = 0; i < K; i++) cin >> L[i];

        int Lmax = 0;
        for (int x : L) Lmax = max(Lmax, x);

        int minNeeded = max<long long>(2, Lmax);
        if (minNeeded > N) {
            cout << 'N' << "\n";
            continue;
        }

        auto can = [&](int T)->bool{
            int i = 0;
            int remaining = T;

            while (remaining > 0) {
                int nxt = (i < K ? L[i] : 0);
                if (nxt == 0) return false;

                if (nxt == 1 || nxt == 2) {
                    if (nxt > remaining) return false;
                    if (remaining != nxt) return false;
                    i++;
                    return i == K;
                } else {
                    if (nxt > remaining) return false;
                    if (remaining == nxt) {
                        return false;
                    }
                    // remaining >= nxt+1. We must place a subtree rooted at nxt using one of the children as part of the main path.
                    // Since after choosing this root, the main path continues with (nxt-1) or (nxt-2) depending on whether the prefix consumes exactly.
                    // The only way to satisfy spacing constraint is to map each consecutive lamp to consecutive nodes along a root-to-leaf path
                    // with no adjacent levels skipped. This implies the sequence must follow the Fibonacci-like descent:
                    // For T>=3, a root of size T has children T-1 and T-2, and along any downward path, sizes decrease by either 1 or 2 each step.
                    // Additionally, at size 1 or 2, leaf ends.
                    // We can simulate greedily with DP on prefix feasibility.
                    break;
                }
            }
            return false;
        };

        // Real solution: For this problem, feasibility is equivalent to checking whether the sequence of lamp diameters
        // corresponds to a valid descending path from N to 1 or 2 in the fixed tree rules,
        // because each ball has exactly two children and placing lamps on successive nodes requires
        // them to be consecutive along a single root-to-leaf path (no gaps possible due to fixed 20cm).
        // Therefore, we need:
        // L[0] == N' for some N' and then for each adjacent pair:
        // L[i+1] must be either L[i]-1 or L[i]-2, and must be >0.
        // Also, the path ends exactly at leaf where diameter is 1 or 2, and the sequence must have length equal to
        // number of nodes along that path to reach 1/2.
        // But since we only know top ball has diameter N, the first lamp must match N.
        // Yet examples show sequences can be attached to smaller subtree? Actually the top ball is fixed at N, lamps can be attached
        // anywhere in the tree only if cable length matches distance between consecutive balls (20cm) which implies consecutive lamps correspond to consecutive levels.
        // Thus the sequence must be a path starting at some node, not necessarily root. However the tree has no shorter-than-20cm edges, all edges are 20cm.
        // Cable can be attached at any node as long as it fits in the tree depth.
        // That means the sequence must match a downward path in the infinite Fibonacci tree, starting at some diameter x such that x >= first lamp,
        // but first lamp type must equal x (since lamp fits only exact diameter of that ball).
        // So the sequence must be exactly a downward path where L[0] is the diameter of the starting ball.
        // Additionally, since the available tree has maximum diameter N at the root, any node diameter in the tree is <= N and reachable from N.
        // In Fibonacci tree, every diameter value <= N exists, and any descending path from x stays within <= x <= N.
        // As long as L[0] <= N, existence of that starting node is guaranteed? Not necessarily if L[0] appears only after certain depth,
        // but tree is infinite below as long as you keep descending. In this construction, starting from root N you can reach any k <= N by descending via children.
        // Therefore any x <= N exists.
        //
        // Thus we check simply:
        // - L[0] <= N
        // - For i from 0..K-2: L[i+1] == L[i]-1 or L[i]-2
        // - At the end, L[K-1] must be 1 or 2 (since leaves only at 1 and 2; balls 1 or 2 cannot have children, so path must stop there).
        // - Also, if K==1, it's possible iff L[0] is reachable from N and (since path length 1, no need to be leaf?) cable ends at that node, doesn't require children.
        //   It is allowed to stop anywhere: consecutive lamps only require spacing; the cable can end at any ball.
        //   So no need for last to be 1/2 when K==1.
        // But if K>1, since next lamp must be on a child, last must have no constraint if K ends there; cable can end at internal node as well.
        // Problem statement: balls do not move; lamps are only those K. Cable just ends. It can end at internal node (has balls below still, cable just not continue).
        // So last can be any diameter <= N.
        // Constraint that prohibits lamps falling: only exact fits, nothing about needing children.
        //
        // However spacing between lamps is 20cm, meaning each lamp occupies consecutive balls along the path, but cable does not require further ball.
        // Therefore last can be any diameter.
        // Then what about K>1 and starting/transition rules? For a ball diameter k>=3 to have a lamp, it can have children but cable could stop at it; that's fine.
        // For ball diameter 1 or 2 with K>1, it cannot have another ball 20cm below because it has no children, so impossible.
        // So if L[i] is 1 or 2 and i < K-1 => N.
        //
        // Therefore final check:
        // - L[0] <= N
        // - For i in 0..K-2:
        //     if L[i] <=2 -> fail
        //     else require L[i+1] is L[i]-1 or L[i]-2
        // - Additionally, L values must stay within [1,N].
        // - Also, diameters cannot increase; implied by rule.
        //
        bool ok = true;
        if (K >= 1) {
            if (L[0] < 1 || L[0] > N) ok = false;
            for (int i = 0; i < K-1 && ok; i++) {
                int a = L[i], b = L[i+1];
                if (a <= 2) { ok = false; break; }
                if (!(b == a-1 || b == a-2)) { ok = false; break; }
                if (b < 1 || b > N) { ok = false; break; }
            }
        }
        cout << (ok ? 'S' : 'N') << "\n";
    }
    return 0;
}