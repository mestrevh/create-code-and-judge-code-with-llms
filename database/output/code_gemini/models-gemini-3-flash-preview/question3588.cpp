/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<int> arr(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < m; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        swap(arr[i], arr[min_idx]);

        cout << "[";
        for (int k = 0; k < m; ++k) {
            cout << arr[k];
            if (k < m - 1) {
                cout << ", ";
            }
        }
        cout << "]" << "\n";
    }

    return 0;
}