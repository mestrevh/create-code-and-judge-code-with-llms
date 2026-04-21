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

    if (n < 3) {
        // Not possible to have an element with both predecessor and successor in the array
        // However, we must read the values to be safe or just exit.
        int temp;
        for (int i = 0; i < n; ++i) cin >> temp;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n - 1; ++i) {
        if (a[i-1] == a[i] - 1 && a[i+1] == a[i] + 1) {
            cout << a[i] << "\n";
        }
    }

    return 0;
}

// Complexity: O(N) time and O(N) space.
// Space complexity could be O(1) by only keeping track of the last three numbers,
// but O(N) is well within limits for standard competitive programming constraints.