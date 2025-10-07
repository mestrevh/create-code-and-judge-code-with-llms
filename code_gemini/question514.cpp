/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> aux;

void merge(std::vector<int>& X, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; ++k) {
        aux[k] = X[k];
    }

    int i = lo;
    int j = mid + 1;

    for (int k = lo; k <= hi; ++k) {
        if (i > mid) {
            X[k] = aux[j++];
        } else if (j > hi) {
            X[k] = aux[i++];
        } else if (aux[i] >= aux[j]) {
            X[k] = aux[i++];
        } else {
            X[k] = aux[j++];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long x0, a, c, m;

    while (std::cin >> n >> x0 >> a >> c >> m) {
        std::vector<int> X(n);
        if (n > 0) {
            X[0] = x0;
            for (int j = 1; j < n; ++j) {
                X[j] = (1LL * a * X[j - 1] + c) % m;
            }
        }

        if (n > 0) {
            aux.assign(n, 0);
        }

        for (int sz = 1; sz < n; sz *= 2) {
            for (int hi = n - 1; hi >= 0; hi -= (2 * sz)) {
                int mid = hi - sz;
                int lo = std::max(0, hi - 2 * sz + 1);
                if (mid >= lo) {
                    merge(X, lo, mid, hi);
                }
            }
            
            int group_sz = 2 * sz;
            int first_sz = n % group_sz;
            if (first_sz == 0 && n > 0) {
                first_sz = group_sz;
            }
        
            int current_idx = 0;
            bool first_group_printed = false;
            while (current_idx < n) {
                if (first_group_printed) {
                    std::cout << " ";
                }
                std::cout << "|";
                
                int group_limit;
                if (!first_group_printed) {
                    group_limit = current_idx + first_sz;
                    first_group_printed = true;
                } else {
                    group_limit = current_idx + group_sz;
                }
                
                int limit = std::min(group_limit, n);

                while (current_idx < limit) {
                    std::cout << " " << X[current_idx];
                    current_idx++;
                }
            }
            std::cout << " |\n";
        }
        std::cout << "\n";
    }
    
    return 0;
}
