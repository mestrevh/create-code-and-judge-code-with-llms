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

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int d;
    cin >> d;

    for (int i = 0; i < n; ++i) {
        int shifted = (nums[i] + d) % 10;
        if (shifted < 0) {
            shifted += 10;
        }
        cout << shifted << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}