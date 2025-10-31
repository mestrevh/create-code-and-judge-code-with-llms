/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class HashTableA {
public:
    int M;
    int N;
    std::vector<std::vector<int>> table;

    HashTableA(int initial_size) : M(initial_size), N(0) {
        table.resize(M);
    }

    void insert(int key) {
        if (N + 1 >= M * 0.75) {
            rehash();
        }
        int index = key % M;
        table[index].push_back(key);
        N++;
    }

    void rehash() {
        std::vector<int> all_elements;
        all_elements.reserve(N);
        for (const auto& bucket : table) {
            for (int key : bucket) {
                all_elements.push_back(key);
            }
        }

        M *= 2;
        N = 0;
        table.assign(M, std::vector<int>());

        for (int key : all_elements) {
            int index = key % M;
            table[index].push_back(key);
            N++;
        }
    }

    long long search(int key) {
        int index = key % M;
        if (table[index].empty()) {
            return 1;
        }
        long long comparisons = 0;
        for (int val : table[index]) {
            comparisons++;
            if (val == key) {
                return comparisons;
            }
        }
        return comparisons;
    }

    bool exists(int key) {
        int index = key % M;
        for (int val : table[index]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};

class HashTableB {
public:
    int M;
    int N;
    std::vector<std::vector<int>> table;

    HashTableB(int initial_size) : M(initial_size), N(0) {
        table.resize(M);
    }

    void insert(int key) {
        if (N + 1 >= M * 0.75) {
            rehash();
        }
        int index = key % M;
        auto it = std::lower_bound(table[index].begin(), table[index].end(), key);
        table[index].insert(it, key);
        N++;
    }

    void rehash() {
        std::vector<int> all_elements;
        all_elements.reserve(N);
        for (const auto& bucket : table) {
            for (int key : bucket) {
                all_elements.push_back(key);
            }
        }

        M *= 2;
        N = 0;
        table.assign(M, std::vector<int>());

        for (int key : all_elements) {
            int index = key % M;
            auto it = std::lower_bound(table[index].begin(), table[index].end(), key);
            table[index].insert(it, key);
            N++;
        }
    }

    long long search(int key) {
        int index = key % M;
        if (table[index].empty()) {
            return 1;
        }
        long long comparisons = 0;
        int low = 0;
        int high = table[index].size() - 1;
        while (low <= high) {
            comparisons++;
            int mid = low + (high - low) / 2;
            if (table[index][mid] == key) {
                return comparisons;
            }
            if (table[index][mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return comparisons;
    }
};

class HashTableC {
public:
    int M;
    int N;
    std::vector<long long> table;
    const long long EMPTY = -1;

    HashTableC(int initial_size) : M(initial_size), N(0) {
        table.assign(M, EMPTY);
    }

    int h0(int k) {
        return k % M;
    }

    int h1(int k) {
        return (2 * (k % (M / 2))) + 1;
    }

    void insert(int key) {
        if (N + 1 >= M * 0.75) {
            rehash();
        }
        int i = 0;
        int first_hash = h0(key);
        int second_hash = h1(key);
        while (i < M) {
            int pos = (first_hash + (long long)i * second_hash) % M;
            if (table[pos] == EMPTY) {
                table[pos] = key;
                N++;
                return;
            }
            i++;
        }
    }

    void rehash() {
        std::vector<long long> all_elements;
        all_elements.reserve(N);
        for (long long key : table) {
            if (key != EMPTY) {
                all_elements.push_back(key);
            }
        }

        M *= 2;
        N = 0;
        table.assign(M, EMPTY);

        for (long long key : all_elements) {
            int i = 0;
            int first_hash = h0(key);
            int second_hash = h1(key);
            while (i < M) {
                int pos = (first_hash + (long long)i * second_hash) % M;
                if (table[pos] == EMPTY) {
                    table[pos] = key;
                    N++;
                    break;
                }
                i++;
            }
        }
    }

    long long search(int key) {
        long long comparisons = 0;
        int i = 0;
        int first_hash = h0(key);
        int second_hash = h1(key);

        while (i < M) {
            int pos = (first_hash + (long long)i * second_hash) % M;
            
            comparisons++;
            if (table[pos] == key) {
                return comparisons;
            }

            if (table[pos] == EMPTY) {
                 comparisons++;
                 return comparisons;
            }
            i++;
        }
        return comparisons;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int K, M_init, N_keys, Q_queries;
    int t = 0;
    while (std::cin >> K >> M_init >> N_keys >> Q_queries) {
        HashTableA table_a(M_init);
        HashTableB table_b(M_init);
        HashTableC table_c(M_init);

        std::vector<int> keys_to_insert(N_keys);
        for (int i = 0; i < N_keys; ++i) {
            std::cin >> keys_to_insert[i];
        }
        
        for (int key : keys_to_insert) {
            table_a.insert(key);
            table_b.insert(key);
            table_c.insert(key);
        }
        
        long long P = 0, A = 0, B = 0, C = 0;

        std::vector<int> keys_to_search(Q_queries);
        for (int i = 0; i < Q_queries; ++i) {
            std::cin >> keys_to_search[i];
        }

        for (int key : keys_to_search) {
            if (!table_a.exists(key)) {
                P++;
            }
            A += table_a.search(key);
            B += table_b.search(key);
            C += table_c.search(key);
        }

        std::cout << "caso " << t << ": " << P << " " << A << " " << B << " " << C << "\n";
        t++;
    }
    
    return 0;
}
