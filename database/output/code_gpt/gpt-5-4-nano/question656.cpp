/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline int valStr(const string& s, int mod) {
    if (s == "um") return 1 % mod;
    if (s == "dois") return 2 % mod;
    return 0 % mod; 
}

static inline int mapCount(const string& s) {
    if (s == "um") return 0;
    if (s == "dois") return 1;
    return 2;
}

static inline int mapShape(string s) {
    for (char &c : s) c = tolower(c);
    if (s.rfind("circulo", 0) == 0 || s.rfind("circulos", 0) == 0) return 0;
    if (s.rfind("quadrado", 0) == 0 || s.rfind("quadrados", 0) == 0) return 1;
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ) {
        if (N == 0) break;

        int cnt[3][3] = {}; 
        // cnt[i][j]: i=card type 0..2 (count of figures), j=shape 0..2

        for (int i = 0; i < N; i++) {
            string a, b;
            cin >> a >> b;
            int t = mapCount(a);
            int s = mapShape(b);
            cnt[t][s]++;
        }

        int best = 0;

        auto encode = [](int c0, int c1, int c2, int c3) {
            return c0 + 10*c1 + 100*c2 + 1000*c3;
        };

        auto dfs = [&](auto&& self, array<int,12> &v) -> int {
            int total = 0;
            for (int i=0;i<12;i++) total += v[i];
            int maxPossible = total/3;
            if (maxPossible <= best) return 0;

            int first = -1;
            for (int i = 0; i < 12; i++) if (v[i] > 0) { first = i; break; }
            if (first == -1) return 0;

            int i = first / 3;
            int s = first % 3;
            int tvals[2], sval[3];
            for (int k=0;k<3;k++) sval[k]=k;

            int shape = s;

            int used = 0;

            int c1idx = -1;
            int c2idx = -1;

            int c0 = i;
            int sc = shape;

            int idxs[2];
            for (int j = 0; j < 12; j++) {
                if (v[j] == 0) continue;
                if (j == first) continue;
                int i2 = j / 3;
                int s2 = j % 3;

                // Need third such that for each characteristic:
                // For figure count: values are mod 3 with rule: a+b+c ≡ 0 (mod 3)
                // With mapping 0 for "um", 1 for "dois", 2 for "tres"
                // For shape: same rule mod 3 as well but only depends on equality/difference of shapes;
                // since only 3 shapes, same rule works.
                int i3 = (3 - (c0 + i2) % 3) % 3;
                int s3 = (3 - (sc + s2) % 3) % 3;
                int k3 = i3*3 + s3;

                if (k3 < 0 || k3 >= 12) continue;

                int neededThird = k3;
                if (neededThird == first || neededThird == j) continue;

                if (v[neededThird] <= 0) continue;

                // make set
                v[first]--;
                v[j]--;
                v[neededThird]--;
                best = max(best, (total/3) - (sum(v.begin(), v.end())/3) + best); 
                int before = best;
                int res = self(self, v);
                best = max(best, res);
                v[first]++;
                v[j]++;
                v[neededThird]++;
            }
            return best;
        };

        struct StateHasher {
            size_t operator()(const array<int,12>& v) const {
                size_t h = 0;
                for (int i=0;i<12;i++) h = h*31u + (size_t)v[i];
                return h;
            }
        };

        unordered_map<array<int,12>, int, StateHasher> memo;

        function<int(array<int,12>&)> solve = [&](array<int,12>& v)->int{
            auto it = memo.find(v);
            if (it != memo.end()) return it->second;

            int total = 0;
            for (int i=0;i<12;i++) total += v[i];
            int upper = total/3;
            if (upper <= best) {
                memo[v]=0;
                return 0;
            }

            int first = -1;
            for (int i=0;i<12;i++) if (v[i]>0) { first=i; break; }
            if (first==-1) {
                memo[v]=0;
                return 0;
            }

            int baseAns = 0;

            int i1 = first/3;
            int s1 = first%3;

            for (int j=0;j<12;j++){
                if (v[j]==0 || j==first) continue;
                int i2 = j/3;
                int s2 = j%3;
                int i3 = (3 - (i1 + i2)%3) %3;
                int s3 = (3 - (s1 + s2)%3) %3;
                int k = i3*3 + s3;
                if (k<0||k>=12) continue;
                if (k==first || k==j) continue;
                if (v[k]==0) continue;

                v[first]--; v[j]--; v[k]--;
                int got = 1 + solve(v);
                baseAns = max(baseAns, got);
                v[first]++; v[j]++; v[k]++;
            }

            memo[v]=baseAns;
            return baseAns;
        };

        array<int,12> v{};
        for (int t=0;t<3;t++) for(int s=0;s<3;s++) v[t*3+s]=cnt[t][s];

        best = 0;
        int ans = solve(v);
        cout << ans << "\n";
    }
    return 0;
}