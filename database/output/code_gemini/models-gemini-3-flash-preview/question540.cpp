/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int val;
    int original_idx;
    int sorted_pos;
};

long long get_dist(long long a, long long b) {
    return (a > b) ? (a - b) : (b - a);
}

void quicksort(const vector<Element>& segment) {
    if (segment.empty()) return;

    long long sum = 0;
    for (const auto& e : segment) sum += e.val;
    int count = segment.size();

    long long floor_mean = sum / count;
    if (sum < 0 && (sum % count != 0)) {
        floor_mean--;
    }

    long long best_dist = -1;
    int target_val = 0;

    for (const auto& e : segment) {
        long long d = get_dist(e.val, floor_mean);
        if (best_dist == -1 || d < best_dist || (d == best_dist && e.val < target_val)) {
            best_dist = d;
            target_val = e.val;
        }
    }

    int pivot_idx_in_segment = -1;
    for (int i = (int)segment.size() - 1; i >= 0; --i) {
        if (segment[i].val == target_val) {
            pivot_idx_in_segment = i;
            break;
        }
    }

    const Element& pivot_el = segment[pivot_idx_in_segment];
    cout << "(" << pivot_el.val << "," << pivot_el.sorted_pos << ")";

    vector<Element> left, right;
    for (int i = 0; i < (int)segment.size(); ++i) {
        if (i == pivot_idx_in_segment) continue;
        if (segment[i].val <= target_val) {
            left.push_back(segment[i]);
        } else {
            right.push_back(segment[i]);
        }
    }

    quicksort(left);
    quicksort(right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x0, a, c, m;
    while (cin >> n >> x0 >> a >> c >> m) {
        vector<Element> X(n);
        long long current_x = x0;
        for (int i = 0; i < n; ++i) {
            X[i].val = (int)current_x;
            X[i].original_idx = i;
            if (i < n - 1) {
                current_x = (a * current_x + c) % m;
            }
        }

        vector<Element> sorted_X = X;
        stable_sort(sorted_X.begin(), sorted_X.end(), [](const Element& e1, const Element& e2) {
            return e1.val < e2.val;
        });

        for (int i = 0; i < n; ++i) {
            X[sorted_X[i].original_idx].sorted_pos = i + 1;
        }

        quicksort(X);
        cout << "\n";
    }

    return 0;
}