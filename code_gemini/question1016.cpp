/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <set>
#include <iterator>

struct Node {
    long long key;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(long long k) : key(k) {}
};

Node* build(const std::vector<long long>& D, std::vector<int>& p, int start, int end) {
    if (start >= end) {
        return nullptr;
    }

    int n = end - start;
    int pivot_p_idx;

    if (n < 3) {
        pivot_p_idx = start;
    } else {
        int i1 = start;
        int i2 = start + (n - 1) / 2;
        int i3 = end - 1;

        long long v1 = D[p[i1]];
        long long v2 = D[p[i2]];
        long long v3 = D[p[i3]];

        if ((v2 <= v1 && v1 <= v3) || (v3 <= v1 && v1 <= v2)) {
            pivot_p_idx = i1;
        } else if ((v1 <= v2 && v2 <= v3) || (v3 <= v2 && v2 <= v1)) {
            pivot_p_idx = i2;
        } else {
            pivot_p_idx = i3;
        }
    }

    long long pivot_val = D[p[pivot_p_idx]];
    std::swap(p[pivot_p_idx], p[end - 1]);

    auto it = std::partition(p.begin() + start, p.begin() + end - 1,
                             [&](int idx) { return D[idx] < pivot_val; });
    int mid_idx = std::distance(p.begin(), it);

    Node* root = new Node(pivot_val);
    root->left = build(D, p, start, mid_idx);
    root->right = build(D, p, mid_idx, end - 1);

    return root;
}

int getHeight(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

void populateSet(Node* root, std::set<long long>& s) {
    if (!root) {
        return;
    }
    populateSet(root->left, s);
    s.insert(root->key);
    populateSet(root->right, s);
}

void deleteTree(Node* root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N_ll, M, seedD, A, C;
    std::cin >> N_ll >> M >> seedD >> A >> C;
    int N = static_cast<int>(N_ll);

    std::vector<long long> D(N);
    D[0] = seedD;
    for (int i = 1; i < N; ++i) {
        D[i] = (static_cast<__int128>(A) * D[i - 1] + C) % M;
    }

    std::vector<int> p(N);
    std::iota(p.begin(), p.end(), 0);

    Node* root = build(D, p, 0, N);
    
    int height = getHeight(root);
    std::cout << "0: " << height << "\n";

    std::set<long long> scene;
    populateSet(root, scene);
    deleteTree(root);

    int Q;
    std::cin >> Q;

    for (int j = 1; j <= Q; ++j) {
        std::string command;
        std::cin >> command;
        if (command == "ADD") {
            long long val;
            std::cin >> val;
            auto result = scene.insert(val);
            std::cout << j << ": " << (result.second ? 1 : 0) << "\n";
        } else if (command == "DEL") {
            long long L, R;
            std::cin >> L >> R;
            auto it_L = scene.lower_bound(L);
            auto it_R = scene.upper_bound(R);
            size_t count = std::distance(it_L, it_R);
            if (count > 0) {
                scene.erase(it_L, it_R);
            }
            std::cout << j << ": " << count << "\n";
        }
    }

    return 0;
}
