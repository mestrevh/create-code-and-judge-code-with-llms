/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool uniform;
    char val; // '0','1' when uniform
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        int L, C;
        cin >> L >> C;
        vector<string> a(L);
        for (int i = 0; i < L; i++) cin >> a[i];

        function<Node(int,int,int,int)> solve = [&](int r0, int c0, int r, int c) -> Node {
            char first = a[r0][c0];
            bool same = true;
            for (int i = r0; i < r0 + r && same; i++) {
                for (int j = c0; j < c0 + c && same; j++) {
                    if (a[i][j] != first) same = false;
                }
            }
            if (same) {
                return Node{true, first};
            }

            int rTop = (r + 1) / 2;
            int rBot = r / 2;
            int cLeft = (c + 1) / 2;
            int cRight = c / 2;

            Node tl = solve(r0, c0, rTop, cLeft);
            Node tr = solve(r0, c0 + cLeft, rTop, cRight);
            Node bl = solve(r0 + rTop, c0, rBot, cLeft);
            Node br = solve(r0 + rTop, c0 + cLeft, rBot, cRight);

            return Node{false, 0};
        };

        function<void(int,int,int,int,string&)> build = [&](int r0, int c0, int r, int c, string &out) {
            char first = a[r0][c0];
            bool same = true;
            for (int i = r0; i < r0 + r && same; i++) {
                for (int j = c0; j < c0 + c && same; j++) {
                    if (a[i][j] != first) same = false;
                }
            }
            if (same) {
                out.push_back(first);
                return;
            }

            out.push_back('D');

            int rTop = (r + 1) / 2;
            int rBot = r / 2;
            int cLeft = (c + 1) / 2;
            int cRight = c / 2;

            build(r0, c0, rTop, cLeft, out);
            build(r0, c0 + cLeft, rTop, cRight, out);
            build(r0 + rTop, c0, rBot, cLeft, out);
            build(r0 + rTop, c0 + cLeft, rBot, cRight, out);
        };

        string out;
        out.reserve(4 * (int)ceil(log2(max(L,C)+1)) * 50);
        build(0, 0, L, C, out);

        for (int i = 0; i < (int)out.size(); i += 50) {
            cout << out.substr(i, min(50, (int)out.size() - i)) << "\n";
        }
        if (n) {
            // No blank line between test cases per typical format; output already ends with newline.
        }
    }

    return 0;
}