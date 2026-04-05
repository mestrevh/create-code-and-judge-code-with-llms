/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline int idx(int r, int c, int L){ return r*L + c; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, L;
    bool firstCase = true;
    while ( (cin >> N >> A >> L) ) {
        if (N==0 && A==0 && L==0) break;

        vector<string> words(N);
        for (int i=0;i<N;i++) cin >> words[i];

        vector<string> grid(A);
        for (int r=0;r<A;r++) cin >> grid[r];

        vector<vector<int>> posByChar(26);
        for (int r=0;r<A;r++){
            for(int c=0;c<L;c++){
                char ch = grid[r][c];
                if('A'<=ch && ch<='Z'){
                    posByChar[ch-'A'].push_back(idx(r,c,L));
                }
            }
        }

        vector<vector<int>> solutions(N);

        vector<int> used(A*L, 0);
        vector<int> path;

        auto solveWord = [&](const string& w)->vector<int>{
            int len = (int)w.size();
            vector<int> result;
            vector<int> candidates;

            int firstChar = w[0]-'A';
            if (firstChar<0 || firstChar>=26) return {};
            candidates = posByChar[firstChar];

            vector<vector<int>> adj(A*L);
            static bool built = false;
            static int builtA=0,builtL=0;
            if (!built || builtA!=A || builtL!=L){
                built = true;
                builtA = A; builtL = L;
                for(int r=0;r<A;r++){
                    for(int c=0;c<L;c++){
                        int u = idx(r,c,L);
                        if(r>0) adj[u].push_back(idx(r-1,c,L));
                        if(r+1<A) adj[u].push_back(idx(r+1,c,L));
                        if(c>0) adj[u].push_back(idx(r,c-1,L));
                        if(c+1<L) adj[u].push_back(idx(r,c+1,L));
                    }
                }
            }

            function<bool(int,int,int)> dfs = [&](int pos, int u, int depth)->bool{
                if (depth==len-1){
                    result = path;
                    return true;
                }
                for(int v: adj[u]){
                    if (used[v]) continue;
                    int r = v / L, c = v % L;
                    if (grid[r][c] != w[depth+1]) continue;
                    used[v]=1;
                    path.push_back(v);
                    if (dfs(pos, v, depth+1)) return true;
                    path.pop_back();
                    used[v]=0;
                }
                return false;
            };

            for(int start: candidates){
                int r = start / L, c = start % L;
                if(grid[r][c] != w[0]) continue;
                fill(used.begin(), used.end(), 0);
                used[start]=1;
                path.clear();
                path.push_back(start);
                if (dfs(0,start,0)) return result;
            }
            return {};
        };

        for (int i=0;i<N;i++){
            solutions[i] = solveWord(words[i]);
        }

        if (!firstCase) cout << "\n";
        firstCase = false;

        for (int i=0;i<N;i++){
            auto &sol = solutions[i];
            for (int k=0;k<(int)sol.size();k++){
                int p = sol[k];
                int r = p / L, c = p % L;
                int row = r+1;
                int col = c+1;
                if (k) cout << ' ';
                cout << row << col;
            }
            if (i+1<N) cout << "\n";
        }
    }
    return 0;
}