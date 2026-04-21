/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline bool isBlankLine(const string& s){
    for(char c: s) if(!isspace((unsigned char)c)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    string line;
    getline(cin, line);

    vector<int> results;
    results.reserve(T);

    for(int tc = 0; tc < T; tc++){
        while(true){
            if(!getline(cin, line)) line.clear();
            if(line.empty() || isBlankLine(line)) continue;
            break;
        }

        vector<string> mat;
        int N = stoi(line);
        mat.reserve(N);

        for(int i = 0; i < N; i++){
            string row;
            while(true){
                getline(cin, row);
                if(row.empty() || isBlankLine(row)) continue;
                break;
            }
            if((int)row.size() > N) {
                string filtered;
                filtered.reserve(N);
                for(char c: row) if(c=='0' || c=='1') filtered.push_back(c);
                row = filtered;
            }
            mat.push_back(row);
        }

        vector<int> h(N, 0);
        vector<int> left(N, 0), right(N, N);
        int best = 0;

        for(int r = 0; r < N; r++){
            int curLeft = 0;
            for(int c = 0; c < N; c++){
                if(mat[r][c] == '1'){
                    left[c] = max(left[c], curLeft);
                }else{
                    left[c] = 0;
                    curLeft = c + 1;
                }
            }

            int curRight = N;
            for(int c = N - 1; c >= 0; c--){
                if(mat[r][c] == '1'){
                    right[c] = min(right[c], curRight);
                }else{
                    right[c] = N;
                    curRight = c;
                }
            }

            for(int c = 0; c < N; c++){
                if(mat[r][c] == '1') h[c] += 1;
                else h[c] = 0;
                int area = h[c] * (right[c] - left[c]);
                if(area > best) best = area;
            }
        }

        results.push_back(best);
    }

    for(int i = 0; i < (int)results.size(); i++){
        if(i) cout << "\n\n";
        cout << results[i];
    }
    return 0;
}