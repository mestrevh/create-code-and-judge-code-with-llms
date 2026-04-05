/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<string> readAllInput() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string s;
    while (getline(cin, s)) lines.push_back(s);
    return lines;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines = readAllInput();
    if (lines.empty()) return 0;

    const string sep = "_______________________________________________________________________________";
    vector<vector<string>> grids;
    vector<string> cur;

    int n = (int)lines.size();
    for (int i = 0; i < n; i++) {
        string &line = lines[i];
        bool is_sep = true;
        if (!line.empty()) {
            for (char c : line) if (c != '_') { is_sep = false; break; }
        }
        if (is_sep && !line.empty() && cur.empty() == false) {
            cur.push_back(line);
            grids.push_back(cur);
            cur.clear();
        } else if (is_sep && cur.empty()) {
            cur.clear();
            vector<string> g;
            g.push_back(line);
            grids.push_back(g);
        } else {
            cur.push_back(line);
        }
    }
    if (!cur.empty()) {
        grids.push_back(cur);
        cur.clear();
    }

    for (size_t gi = 0; gi < grids.size(); gi++) {
        vector<string> g = grids[gi];

        int sepIndex = -1;
        for (int i = 0; i < (int)g.size(); i++) {
            bool is_sep = !g[i].empty();
            if (is_sep) {
                for (char c : g[i]) if (c != '_') { is_sep = false; break; }
            }
            if (is_sep) { sepIndex = i; break; }
        }
        if (sepIndex == -1) {
            for (auto &line : g) cout << line << "\n";
            if (gi + 1 < grids.size()) cout << "";
            continue;
        }

        int H = sepIndex;
        vector<string> input(H);
        for (int i = 0; i < H; i++) input[i] = g[i];

        int maxW = 0;
        for (auto &row : input) maxW = max(maxW, (int)row.size());

        vector<string> grid(H);
        for (int i = 0; i < H; i++) {
            grid[i] = input[i];
            if ((int)grid[i].size() < maxW) grid[i] += string(maxW - grid[i].size(), ' ');
        }

        int W = maxW;

        vector<vector<unsigned char>> blocked(H, vector<unsigned char>(W, 0));
        vector<vector<char>> orig(H, vector<char>(W, ' '));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                char c = grid[i][j];
                orig[i][j] = c;
                if (c != ' ') blocked[i][j] = 1;
            }
        }

        int dh[4] = {-1, 1, 0, 0};
        int dw[4] = {0, 0, -1, 1};

        vector<vector<int>> comp(H, vector<int>(W, -1));
        int compCnt = 0;
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
            if (blocked[i][j]) continue;
            if (comp[i][j] != -1) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            comp[i][j] = compCnt;
            while(!q.empty()){
                auto [x,y]=q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dh[k], ny=y+dw[k];
                    if(nx<0||nx>=H||ny<0||ny>=W) continue;
                    if(blocked[nx][ny]) continue;
                    if(comp[nx][ny]==-1){
                        comp[nx][ny]=compCnt;
                        q.push({nx,ny});
                    }
                }
            }
            compCnt++;
        }

        vector<char> mark(compCnt, 0);
        vector<char> isOutside(compCnt, 0);
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
            if (blocked[i][j]) continue;
            int id = comp[i][j];
            if (i==0 || i==H-1 || j==0 || j==W-1) isOutside[id] = 1;
            char c = orig[i][j];
            if (c != ' ') {
                if (mark[id] == 0) mark[id] = c;
            }
        }

        vector<vector<int>> filledCompMark(compCnt, vector<int>(1,0)); // dummy to silence unused
        vector<char> finalMark(compCnt, 0);

        for (int id = 0; id < compCnt; id++) {
            if (isOutside[id]) continue;
            finalMark[id] = mark[id];
        }

        vector<vector<char>> out = grid;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (blocked[i][j]) continue;
                int id = comp[i][j];
                if (!isOutside[id]) {
                    char m = finalMark[id];
                    if (m == 0) m = ' ';
                    out[i][j] = m;
                }
            }
        }

        for (int i = 0; i < H; i++) {
            string line = out[i];
            while (!line.empty() && line.back() == ' ') line.pop_back();
            if (line.empty()) line = "";
            cout << line << "\n";
        }
        for (int i = sepIndex; i < (int)g.size(); i++) cout << g[i] << "\n";
        if (gi + 1 < grids.size()) {
        }
    }

    return 0;
}