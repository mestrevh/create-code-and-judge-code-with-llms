/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline long long key2(int a, int b){
    return ( (long long)a << 32 ) ^ (unsigned int)b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    if (!(cin >> R >> C)) return 0;
    vector<vector<long long>> h(R, vector<long long>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> h[i][j];
        }
    }

    long long faces = 0;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            long long cur = h[i][j];
            long long down = 0, up = 0, left = 0, right = 0;
            if(i>0) down = h[i-1][j];
            if(i<R-1) up = h[i+1][j];
            if(j>0) left = h[i][j-1];
            if(j<C-1) right = h[i][j+1];

            vector<long long> neigh = {down, up, left, right};
            for(long long nb: neigh){
                if(cur > nb){
                    faces += (cur - nb);
                }
            }
        }
    }

    auto addRectFaces = [&](bool vertical){
        if(vertical){
            for(int i=0;i<R;i++){
                for(int j=0;j+1<C;j++){
                    long long a = h[i][j];
                    long long b = h[i][j+1];
                    long long mx = max(a,b);
                    long long mn = min(a,b);
                    faces += (mx - mn > 0) ? 1 : 0;
                }
            }
        }else{
            for(int i=0;i+1<R;i++){
                for(int j=0;j<C;j++){
                    long long a = h[i][j];
                    long long b = h[i+1][j];
                    long long mx = max(a,b);
                    long long mn = min(a,b);
                    faces += (mx - mn > 0) ? 1 : 0;
                }
            }
        }
    };

    addRectFaces(true);
    addRectFaces(false);

    faces += 1;

    return cout << faces << "\n", 0;
}