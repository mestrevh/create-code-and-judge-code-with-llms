/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class HashTableA {
    vector<vector<int>> table;
public:
    HashTableA(int size) : table(size) {}
    void insert(int key) {
        table[key % table.size()].push_back(key);
    }
    bool search(int key, int &comparisons) {
        auto &bucket = table[key % table.size()];
        comparisons += bucket.size();
        return find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};

class HashTableB {
    vector<vector<int>> table;
public:
    HashTableB(int size) : table(size) {}
    void insert(int key) {
        auto &bucket = table[key % table.size()];
        bucket.push_back(key);
        sort(bucket.begin(), bucket.end());
    }
    bool search(int key, int &comparisons) {
        auto &bucket = table[key % table.size()];
        comparisons += bucket.size();
        return binary_search(bucket.begin(), bucket.end(), key);
    }
};

class HashTableC {
    vector<int> table;
    int M;
    int count;
public:
    HashTableC(int size) : M(size), count(0) {
        table.resize(M, -1);
    }
    int h0(int key) { return key % M; }
    int h1(int key) { return (2 * (key % (M / 2))) + 1; }
    
    void insert(int key) {
        int idx = h0(key);
        while (table[idx] != -1) {
            idx = (idx + h1(key)) % M;
        }
        table[idx] = key;
        count++;
        if (count / (double)M >= 0.75) {
            rehash();
        }
    }
    
    void rehash() {
        vector<int> old_table = table;
        M *= 2;
        table = vector<int>(M, -1);
        count = 0;
        for (int key : old_table) {
            if (key != -1) insert(key);
        }
    }
    
    bool search(int key, int &comparisons) {
        int idx = h0(key);
        while (true) {
            comparisons++;
            if (table[idx] == -1) return false;
            if (table[idx] == key) return true;
            idx = (idx + h1(key)) % M;
        }
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int K, M, N, Q;
        cin >> K >> M >> N >> Q;

        HashTableA hashA(M);
        HashTableB hashB(M);
        HashTableC hashC(M);

        vector<int> passwords(N);
        for (int &pw : passwords) {
            cin >> pw;
            hashA.insert(pw);
            hashB.insert(pw);
            hashC.insert(pw);
        }

        int penetras = 0;
        int compA = 0, compB = 0, compC = 0;

        for (int j = 0; j < Q; ++j) {
            int query;
            cin >> query;
            if (!hashA.search(query, compA)) penetras++;
            if (!hashB.search(query, compB)) penetras++;
            if (!hashC.search(query, compC)) penetras++;
        }

        cout << "caso " << t << ": " << penetras << " " << compA << " " << compB << " " << compC << endl;

        if (t != T - 1) cout << endl;
    }
    return 0;
}
