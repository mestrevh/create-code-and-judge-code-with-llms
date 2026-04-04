/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    set<int> distinct_heights;
    int high = 0;
    int medium = 0;
    int low = 0;
    int min_h = 2147483647;
    int max_h = -2147483648;

    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        distinct_heights.insert(h);
        
        if (h >= 100) {
            high++;
        } else if (h >= 50) {
            medium++;
        } else {
            low++;
        }

        if (h < min_h) min_h = h;
        if (h > max_h) max_h = h;
    }

    cout << distinct_heights.size() << "\n";
    cout << high << "\n";
    cout << medium << "\n";
    cout << low << "\n";
    cout << (max_h - min_h) << "\n";

    return 0;
}