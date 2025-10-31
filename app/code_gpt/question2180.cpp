/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        int k = 0;
        for (int i = 1; i < n; ++i) {
            k = max(k, heights[i] - heights[i - 1]);
        }
        if (heights[0] > k) {
            k = heights[0];
        }
        cout << "Case " << t << ": " << k << endl;
    }
    return 0;
}
