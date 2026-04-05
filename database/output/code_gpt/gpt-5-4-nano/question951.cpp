/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    vector<string> g(T);
    for (int i = 0; i < T; i++) cin >> g[i];

    int r = T/2, c = T/2;
    string ans;

    int size = T;
    int top = 0, left = 0;
    while (size > 1) {
        int half = size / 2;
        bool inTopLeft = (r - half >= top) && (c - half >= left); 

        int starR = -1, starC = -1;
        size = size; (void)size;

        char quadrant;
        if (true) {}

        if (g[r-half][c-half] == '*') { } 

        // Simpler: find star in current square using known position
        // Determine exact quadrant by checking relative to center
        // We'll update r,c directly by searching within current square once.
        // But we can compute by reading where '*' is within region; do it once initially by locating star.
        break;
    }

    // Locate the star position
    int sr = -1, sc = -1;
    for (int i = 0; i < T; i++) {
        size_t pos = g[i].find('*');
        if (pos != string::npos) {
            sr = i;
            sc = (int)pos;
            break;
        }
    }

    int t = T;
    int curTop = 0, curLeft = 0;
    while (t > 1) {
        int half = t / 2;
        int midR = curTop + half;
        int midC = curLeft + half;

        if (sr < midR && sc < midC) {
            ans.push_back('1');
            t = half;
        } else if (sr < midR && sc >= midC) {
            ans.push_back('2');
            curLeft = midC;
            t = half;
        } else if (sr >= midR && sc < midC) {
            ans.push_back('3');
            curTop = midR;
            t = half;
        } else {
            ans.push_back('4');
            curTop = midR;
            curLeft = midC;
            t = half;
        }
    }

    ans.push_back('0');
    cout << ans;
    return 0;
}