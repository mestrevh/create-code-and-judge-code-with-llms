/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a;
    int n;
    long long c;
    if (!(cin >> a)) return 0;
    cin >> n >> c;

    vector<long long> maint(n + 2, 0), sell(n + 1, 0), scrap(n + 1, 0);

    for (int i = 0; i <= n + 1; i++) cin >> maint[i];
    for (int i = 1; i <= n + 1; i++) cin >> sell[i];
    for (int i = 1; i <= n + 1; i++) cin >> scrap[i];

    const long long INF = (1LL<<62);

    vector<long long> dp(n + 2, INF);
    vector<int> takeB(n + 1, 0);

    dp[n + 1] = scrap[min<long long>(n + 1, n + 1)];
    for (int age = n; age >= 0; --age) {
        int period = age; // not used
    }

    for (int t = n; t >= 0; --t) {
        // dp_age[t] concept: minimal cost from start of year (t+1) to end, given current age=t? not.
    }

    // We'll instead use state (i = year index, age of current equipment at end of year i?) simpler:
    // Decision at end of year k (1..n) for equipment that exists during year k with some age at that time.
    // Equivalent:
    // Let f[k][j] = minimal cost from year k..n, where at beginning of year k current equipment age=j (0..n).
    // At beginning of year 1, age=a.
    // Transition for equipment during year k:
    // If keep (M): pay maintenance for age j at year k (maint[j]); at end of year, age increases by 1 -> begin year k+1 with age=j+1.
    // If buy (B): sell current (no sale at age 0 allowed) at end of year k: sell[j] + then pay purchase c.
    // But purchase happens at end of year k, so new equipment begins year k+1 with age 0.
    // Also during year k, if we buy at end, we still kept during year k, so we paid maintenance for age j for year k regardless.
    // thus both actions include maintenance for year k.
    // Additionally after decision at end of year k, age for next year is:
    // - keep: j+1
    // - buy: 0
    // At horizon end after year n: must sell as scrap depending on age at end of year n (after action).
    // Scrap value uses age of equipment at end of year n (which is beginning year n+1).
    // If we keep at end of year n, age becomes j+1. If we buy at end of year n, new age becomes 0, but problem says scrap price given for ages 1..n+1.
    // Since age 0 at end of year n implies new equipment just bought, but then end-of-horizon sale requires scrap price by age; age 0 not given.
    // Also statement: "you are obliged to sell it as scrap at end ... value varies with age. Consider 1<=n<=5000. The age 0 corresponds to new equipment. As you only decide at end of the year, there is no possibility of selling an equipment with age 0."
    // Therefore at end of year n, age cannot be 0. That means option B at year n is not feasible because it would create age 0 at end.
    // We'll enforce: at year n, only allow M; for j=0 at year n keep leads to scrap age 1 which exists.
    // Also at any year k, selling current due to B requires current age j>=1 (since cannot sell age 0). We'll enforce j>=1.
    // dp dimension: k from 1..n+1 (n+1 is beyond horizon start; terminal handled).
    int maxAge = n + 1;
    vector<vector<long long>> dp2(n + 2, vector<long long>(maxAge + 1, INF));
    vector<vector<char>> choice(n + 1, vector<char>(maxAge + 1, 0)); // 0=M,1=B

    auto initAge = (int)a;
    if (initAge > maxAge) initAge = maxAge;

    dp2[1][initAge] = 0;

    for (int k = 1; k <= n; k++) {
        for (int j = 0; j <= maxAge; j++) {
            long long cur = dp2[k][j];
            if (cur >= INF) continue;

            long long base = cur + maint[j];

            // Keep
            if (j + 1 <= maxAge) {
                long long &ref = dp2[k + 1][j + 1];
                long long val = base;
                if (val < ref) {
                    ref = val;
                    if (k <= n - 1) choice[k][j] = 0;
                }
            }

            // Buy at end of year k -> next age 0, but must sell current at age j (only if j>=1)
            // Also if k==n then next age would be 0 at end horizon which is forbidden.
            if (j >= 1 && k < n) {
                long long &ref = dp2[k + 1][0];
                long long val = base + sell[j] + c;
                if (val < ref) {
                    ref = val;
                    choice[k][j] = 1;
                }
            }
        }
    }

    // Terminal: after year n decisions, equipment age at end of year n equals age at beginning of year n+1 in dp2[n+1][age].
    // Scrap price is provided for ages 1..n+1, so age must be >=1.
    long long best = INF;
    int bestAge = -1;
    for (int j = 1; j <= maxAge; j++) {
        if (dp2[n + 1][j] < best) {
            best = dp2[n + 1][j];
            bestAge = j;
        }
    }

    // Reconstruct decisions.
    // We need parent pointers; we only stored choice for B when improved, but for proper reconstruction we need parent ages.
    // Let's do full DP with parent for each state using tie-safe unique optimum.
    vector<vector<long long>> dp(n + 2, vector<long long>(maxAge + 1, INF));
    vector<vector<int>> parAge(n + 2, vector<int>(maxAge + 1, -1));
    vector<vector<char>> parAct(n + 2, vector<char>(maxAge + 1, 0)); // 'M' or 'B' taken at end of year k-1 leading into this state

    dp[1][initAge] = 0;
    for (int k = 1; k <= n; k++) {
        for (int j = 0; j <= maxAge; j++) {
            long long cur = dp[k][j];
            if (cur >= INF) continue;
            long long base = cur + maint[j];

            // Keep -> state (k+1, j+1) at beginning of year k+1
            if (j + 1 <= maxAge) {
                long long val = base;
                int nj = j + 1;
                if (val < dp[k + 1][nj]) {
                    dp[k + 1][nj] = val;
                    parAge[k + 1][nj] = j;
                    parAct[k + 1][nj] = 0;
                }
            }
            // Buy -> state (k+1,0)
            if (j >= 1 && k < n) {
                long long val = base + sell[j] + c;
                int nj = 0;
                if (val < dp[k + 1][nj]) {
                    dp[k + 1][nj] = val;
                    parAge[k + 1][nj] = j;
                    parAct[k + 1][nj] = 1;
                }
            }
        }
    }

    long long finalBest = INF;
    int ageEnd = -1;
    for (int j = 1; j <= maxAge; j++) {
        long long val = dp[n + 1][j] + 0; 
        if (val < finalBest) {
            finalBest = val;
            ageEnd = j;
        }
    }
    // But dp[n+1][j] currently excludes scrap. We must add scrap at end:
    finalBest = INF;
    for (int j = 1; j <= maxAge; j++) {
        if (dp[n + 1][j] >= INF) continue;
        long long val = dp[n + 1][j] - sell[j] + scrap[j]; // wait: scrap at end without selling? Actually if action included selling for B, keep doesn't sell.
        // Our transitions don't include any sale at year end unless buying.
        // At the very end, regardless, must sell as scrap. So add scrap[j] only once, no other sale.
        // Therefore final cost = dp[n+1][j] + scrap[j].
        long long tot = dp[n + 1][j] + scrap[j];
        if (tot < finalBest) {
            finalBest = tot;
            ageEnd = j;
        }
    }

    string ans(n, 'M');
    int curAge = ageEnd;
    for (int k = n; k >= 1; k--) {
        int prevAge = parAge[k + 1][curAge];
        char act = parAct[k + 1][curAge];
        // act indicates decision at end of year k that transitions from prevAge to curAge
        // if act==0 => M, if act==1 => B
        ans[k - 1] = (act ? 'B' : 'M');
        curAge = prevAge;
    }

    cout << finalBest << "\n" << ans << "\n";
    return 0;
}