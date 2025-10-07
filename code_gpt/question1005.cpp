/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class BloomFilter {
private:
    vector<bool> bitArray;
    vector<int> bases;
    int M, K;

    int hash(const string& s, int b) const {
        int hashValue = 0;
        for (int i = 0; i < s.size(); ++i) {
            hashValue = (hashValue + s[i] * pow(b, i)) % M;
        }
        return hashValue;
    }

public:
    BloomFilter(int m, int k, const vector<int>& b) : M(m), K(k), bases(b) {
        bitArray.resize(M, false);
    }

    void add(const string& s) {
        for (int i = 0; i < K; ++i) {
            bitArray[hash(s, bases[i])] = true;
        }
    }

    int check(const string& s, const unordered_set<string>& actualUsers) const {
        bool allSet = true;
        for (int i = 0; i < K; ++i) {
            if (!bitArray[hash(s, bases[i])]) {
                return 0;
            }
        }
        if (actualUsers.count(s)) {
            return 2;
        }
        return 1;
    }
};

int main() {
    int N;
    cin >> N;

    BloomFilter bloom(0, 0, {});
    unordered_set<string> users;

    for (int i = 0; i < N; ++i) {
        string user;
        cin >> user;
        users.insert(user);
    }

    int M, K;
    cin >> M >> K;

    vector<int> bases(K);
    for (int i = 0; i < K; ++i) {
        cin >> bases[i];
    }

    bloom = BloomFilter(M, K, bases);
    for (const auto& user : users) {
        bloom.add(user);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;
        cout << bloom.check(query, users) << endl;
    }

    return 0;
}
