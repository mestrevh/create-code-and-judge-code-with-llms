/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string toLowerStr(string s){
    for(char &ch: s) ch = (char)tolower((unsigned char)ch);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q, X, C, N, M;
    if(!(cin >> Q >> X >> C >> N >> M)) return 0;

    vector<string> names(C);
    for(int i = 0; i < C; i++){
        cin >> names[i];
        names[i] = toLowerStr(names[i]);
    }

    vector<vector<char>> grid(N, vector<char>(M));
    auto inside = [&](int r, int c){ return r >= 0 && r < N && c >= 0 && c < M; };

    int ans = 0;
    string line;
    getline(cin, line);

    for(int qi = 0; qi < Q; qi++){
        for(int i = 0; i < N; i++){
            while(true){
                if(!std::getline(cin, line)) line.clear();
                if((int)line.size() == 0) continue;
                break;
            }
            while((int)line.size() < M){
                string extra;
                if(!getline(cin, extra)) break;
                if((int)extra.size() == 0) continue;
                line += extra;
            }
            for(int j = 0; j < M; j++){
                char ch = (j < (int)line.size() ? line[j] : ' ');
                grid[i][j] = (char)tolower((unsigned char)ch);
            }
        }

        long long total = 0;

        for(const string &pat : names){
            int L = (int)pat.size();
            if(L > max(N, M) + 1) {
                ;
            }

            for(int r = 0; r < N; r++){
                for(int c = 0; c < M; c++){
                    for(int d = 0; d < 4; d++){
                        int dr = 0, dc = 0;
                        if(d == 0){ dr = 0; dc = 1; }
                        else if(d == 1){ dr = 0; dc = -1; }
                        else if(d == 2){ dr = 1; dc = 0; }
                        else { dr = -1; dc = 0; }

                        int rr = r, cc = c;
                        bool ok = true;
                        for(int k = 0; k < L; k++){
                            if(!inside(rr, cc) || grid[rr][cc] != pat[k]) { ok = false; break; }
                            rr += dr;
                            cc += dc;
                        }
                        if(ok){
                            total++;
                            if(total > X) break;
                        }
                    }
                    if(total > X) break;
                }
                if(total > X) break;
            }
            if(total > X) break;
        }

        if(total <= X) ans++;
    }

    cout << ans << "\n";
    return 0;
}