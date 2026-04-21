/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FastInput {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastInput() : idx(0), size(0) {}
    inline char read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }
    template<typename T>
    bool readInt(T &out) {
        char c;
        do {
            c = read();
            if (!c) return false;
        } while (c!='-' && (c<'0' || c>'9'));
        bool neg = false;
        if (c=='-') { neg = true; c = read(); }
        T val = 0;
        while (c>='0' && c<='9') {
            val = val*10 + (c - '0');
            c = read();
        }
        out = neg ? -val : val;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FastInput in;
    int N, M;
    bool firstCase = true;
    while (true) {
        if (!in.readInt(N)) return 0;
        in.readInt(M);
        if (N == 0 && M == 0) break;

        vector<vector<int>> w(N + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < M; i++) {
            int X, Y, Z;
            in.readInt(X); in.readInt(Y); in.readInt(Z);
            w[X][Y] = Z;
            w[Y][X] = Z;
        }

        long long best = -1;
        array<int,3> bestTriple{1,2,3};

        for (int a = 1; a <= N; a++) {
            for (int b = a + 1; b <= N; b++) {
                for (int c = b + 1; c <= N; c++) {
                    long long sum = (long long)w[a][b] + w[a][c] + w[b][c];
                    if (sum > best) {
                        best = sum;
                        bestTriple = {a,b,c};
                    } else if (sum == best) {
                        array<int,3> cur{a,b,c};
                        if (cur < bestTriple) bestTriple = cur;
                    }
                }
            }
        }

        if (!firstCase) {}
        firstCase = false;
        cout << bestTriple[0] << ' ' << bestTriple[1] << ' ' << bestTriple[2] << "\n";
    }
    return 0;
}