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

    vector<int> heights(5);
    for (int i = 0; i < 5; ++i) {
        if (!(cin >> heights[i])) break;
    }

    sort(heights.begin(), heights.end());

    cout << heights[0] << "\n";
    cout << heights[2] << "\n";
    cout << heights[4] << "\n";

    return 0;
}