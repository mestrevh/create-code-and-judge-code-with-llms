/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Subset {
    int a, b, c, sum;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> v(n);
    bool has_negative = false;
    for (int i = 0; i < n; ++i) {
        if (!(cin >> v[i])) break;
        if (v[i] < 0) {
            has_negative = true;
        }
    }

    if (has_negative) {
        cout << "-1" << "\n";
        return 0;
    }

    if (n < 3) {
        return 0;
    }

    vector<Subset> subsets;
    map<int, int> freq;

    // Generate all subsets of size 3 and count their sums.
    // The nested loops with i < j < k and a sorted input vector v
    // naturally generate the subsets in lexicographical order.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int s = v[i] + v[j] + v[k];
                subsets.push_back({v[i], v[j], v[k], s});
                freq[s]++;
            }
        }
    }

    // Output subsets that have unique sums in the order they were generated.
    for (const auto& sub : subsets) {
        if (freq[sub.sum] == 1) {
            cout << "{" << sub.a << "," << sub.b << "," << sub.c << "} = " << sub.sum << "\n";
        }
    }

    return 0;
}