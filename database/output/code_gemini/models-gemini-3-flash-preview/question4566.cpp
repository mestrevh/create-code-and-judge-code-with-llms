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
    vector<char> chars(n);
    for (int i = 0; i < n; ++i) {
        cin >> chars[i];
    }

    int m;
    if (!(cin >> m)) return 0;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }

    int limit = max(n, m);
    for (int i = 0; i < limit; ++i) {
        char base;
        int offset = 0;

        if (i < n && i < m) {
            base = chars[i];
            offset = nums[i];
        } else if (i < m) {
            base = 'a';
            offset = nums[i];
        } else {
            base = chars[i];
            offset = 0;
        }

        int result_val = (int)base + offset;
        if (result_val >= (int)'a' && result_val <= (int)'z') {
            cout << (char)result_val;
        } else {
            cout << '.';
        }

        if (i < limit - 1) {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}