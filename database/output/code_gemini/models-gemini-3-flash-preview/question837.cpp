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

    vector<int> speeds(5);
    for (int i = 0; i < 5; ++i) {
        if (!(cin >> speeds[i])) break;
    }

    sort(speeds.begin(), speeds.end(), greater<int>());

    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << " - " << speeds[i] << " km/h" << "\n";
    }

    return 0;
}