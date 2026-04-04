/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }

    if (a.empty()) {
        return 0;
    }

    int n = static_cast<int>(a.size());

    auto print_array = [&]() {
        for (int k = 0; k < n; ++k) {
            cout << a[k] << (k == n - 1 ? "" : " ");
        }
        cout << "\n";
    };

    print_array();

    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        bool moved = false;
        
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            moved = true;
        }
        
        if (moved) {
            a[j + 1] = key;
            print_array();
        }
    }

    return 0;
}