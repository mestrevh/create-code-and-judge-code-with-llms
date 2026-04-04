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

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool in_b = false;
    for (int width = 1; width < n; width *= 2) {
        vector<int>& src = in_b ? b : a;
        vector<int>& dst = in_b ? a : b;
        for (int i = 0; i < n; i += 2 * width) {
            int left = i;
            int mid = min(i + width, n);
            int right = min(i + 2 * width, n);
            
            int l = left, r = mid;
            for (int k = left; k < right; k++) {
                if (l < mid && (r >= right || src[l] <= src[r])) {
                    dst[k] = src[l++];
                } else {
                    dst[k] = src[r++];
                }
            }
        }
        in_b = !in_b;
    }

    const vector<int>& res = in_b ? b : a;
    for (int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}

