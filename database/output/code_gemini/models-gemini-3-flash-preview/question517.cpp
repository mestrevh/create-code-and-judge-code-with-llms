/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <cstdio>

using namespace std;

static int parent[10005];
static int rankDSU[10005];
static int rootID[10005];

static int findRoot(int i) {
    int root = i;
    while (parent[root] != root)
        root = parent[root];
    while (parent[i] != root) {
        int next = parent[i];
        parent[i] = root;
        i = next;
    }
    return root;
}

static void unite(int i, int j) {
    int root_i = findRoot(i);
    int root_j = findRoot(j);
    if (root_i != root_j) {
        if (rankDSU[root_i] < rankDSU[root_j]) {
            parent[root_i] = root_j;
        } else if (rankDSU[root_i] > rankDSU[root_j]) {
            parent[root_j] = root_i;
        } else {
            parent[root_i] = root_j;
            rankDSU[root_j]++;
        }
    }
}

static char in_buf[1 << 20];
static int in_pos = 0;
static int in_len = 0;

inline int get_char() {
    if (in_pos >= in_len) {
        in_len = fread(in_buf, 1, sizeof(in_buf), stdin);
        in_pos = 0;
        if (in_len == 0) return EOF;
    }
    return (unsigned char)in_buf[in_pos++];
}

inline int readInt() {
    int res = 0;
    int c = get_char();
    while (c != EOF && (c < '0' || c > '9')) c = get_char();
    if (c == EOF) return -1;
    while (c >= '0' && c <= '9') {
        res = res * 10 + (c - '0');
        c = get_char();
    }
    return res;
}

static char out_buf[1 << 20];
static int out_pos = 0;

inline void flush_out() {
    if (out_pos > 0) {
        fwrite(out_buf, 1, out_pos, stdout);
        out_pos = 0;
    }
}

inline void put_char(char c) {
    if (out_pos >= (1 << 20)) flush_out();
    out_buf[out_pos++] = c;
}

inline void put_int(int n) {
    if (n == 0) {
        put_char('0');
        return;
    }
    char buf[12];
    int p = 0;
    while (n > 0) {
        buf[p++] = (n % 10) + '0';
        n /= 10;
    }
    while (p > 0) put_char(buf[--p]);
}

int main() {
    int N, M, Q;
    bool firstCase = true;
    while (true) {
        N = readInt();
        if (N == -1) break;
        M = readInt();
        Q = readInt();

        if (!firstCase) put_char('\n');
        firstCase = false;
        
        int numCells = N * N;
        for (int i = 0; i < numCells; ++i) {
            parent[i] = i;
            rankDSU[i] = 0;
        }

        int v_walls_limit = N * (N - 1);
        for (int i = 0; i < M; ++i) {
            int w = readInt();
            if (w == -1) break;
            int u, v;
            if (w < v_walls_limit) {
                int r = w / (N - 1);
                int c = w % (N - 1);
                u = r * N + c;
                v = u + 1;
            } else {
                int w_prime = w - v_walls_limit;
                int r = w_prime / N;
                int c = w_prime % N;
                u = r * N + c;
                v = u + N;
            }
            if (u < numCells && v < numCells)
                unite(u, v);
        }

        for (int i = 0; i < numCells; ++i) {
            rootID[i] = findRoot(i);
        }

        for (int j = 1; j <= Q; ++j) {
            int A = readInt();
            int B = readInt();
            if (A == -1 || B == -1) break;
            put_int(j);
            put_char('.');
            if (A < numCells && B < numCells) {
                put_char((rootID[A] == rootID[B]) ? '1' : '0');
            } else {
                put_char('0');
            }
            put_char('\n');
        }
    }
    flush_out();
    return 0;
}