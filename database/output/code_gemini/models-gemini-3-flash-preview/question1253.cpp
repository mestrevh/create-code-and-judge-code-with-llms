/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct MonitorA {
    int M;
    int n;
    vector<vector<int>> table;

    MonitorA(int m) : M(m), n(0), table(m) {}

    void rehash() {
        vector<int> elements;
        for (int i = 0; i < M; i++) {
            for (int x : table[i]) {
                elements.push_back(x);
            }
        }
        M *= 2;
        table.assign(M, vector<int>());
        for (int x : elements) {
            table[x % M].push_back(x);
        }
    }

    void insert(int x) {
        if ((double)n / M >= 0.75) rehash();
        table[x % M].push_back(x);
        n++;
    }

    bool search(int x, ll& comps) {
        int h = x % M;
        for (int val : table[h]) {
            comps++;
            if (val == x) return true;
        }
        return false;
    }
};

struct MonitorB {
    int M;
    int n;
    vector<vector<int>> table;

    MonitorB(int m) : M(m), n(0), table(m) {}

    void rehash() {
        vector<int> elements;
        for (int i = 0; i < M; i++) {
            for (int x : table[i]) {
                elements.push_back(x);
            }
        }
        M *= 2;
        table.assign(M, vector<int>());
        for (int x : elements) {
            table[x % M].push_back(x);
        }
    }

    void insert(int x) {
        if ((double)n / M >= 0.75) rehash();
        int h = x % M;
        table[h].insert(lower_bound(table[h].begin(), table[h].end(), x), x);
        n++;
    }

    bool search(int x, ll& comps) {
        int h = x % M;
        const vector<int>& chain = table[h];
        int low = 0, high = (int)chain.size() - 1;
        while (low <= high) {
            comps++;
            int mid = low + (high - low) / 2;
            if (chain[mid] == x) return true;
            if (chain[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

struct MonitorC {
    int M;
    int n;
    vector<int> table;

    MonitorC(int m) : M(m), n(0), table(m, -1) {}

    void rehash() {
        vector<int> elements;
        for (int i = 0; i < M; i++) {
            if (table[i] != -1) elements.push_back(table[i]);
        }
        M *= 2;
        table.assign(M, -1);
        for (int x : elements) {
            int h0 = x % M;
            int h1 = (2 * (x % (M / 2))) + 1;
            for (int i = 0; i < M; i++) {
                int pos = (h0 + (ll)i * h1) % M;
                if (table[pos] == -1) {
                    table[pos] = x;
                    break;
                }
            }
        }
    }

    void insert(int x) {
        if ((double)n / M >= 0.75) rehash();
        int h0 = x % M;
        int h1 = (2 * (x % (M / 2))) + 1;
        for (int i = 0; i < M; i++) {
            int pos = (h0 + (ll)i * h1) % M;
            if (table[pos] == -1) {
                table[pos] = x;
                break;
            }
        }
        n++;
    }

    bool search(int x, ll& comps) {
        int h0 = x % M;
        int h1 = (2 * (x % (M / 2))) + 1;
        for (int i = 0; i < M; i++) {
            int pos = (h0 + (ll)i * h1) % M;
            if (table[pos] == -1) return false;
            comps++;
            if (table[pos] == x) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll K, M, N, Q;
    int case_num = 0;
    while (cin >> K >> M >> N >> Q) {
        MonitorA hA(M);
        MonitorB hB(M);
        MonitorC hC(M);

        for (int i = 0; i < N; i++) {
            int senha;
            cin >> senha;
            hA.insert(senha);
            hB.insert(senha);
            hC.insert(senha);
        }

        ll penetras = 0;
        ll totalA = 0, totalB = 0, totalC = 0;

        for (int i = 0; i < Q; i++) {
            int query;
            cin >> query;
            bool foundA = hA.search(query, totalA);
            bool foundB = hB.search(query, totalB);
            bool foundC = hC.search(query, totalC);
            if (!foundA) penetras++;
        }

        cout << "caso " << case_num++ << ": " << penetras << " " << totalA << " " << totalB << " " << totalC << "\n";
    }

    return 0;
}