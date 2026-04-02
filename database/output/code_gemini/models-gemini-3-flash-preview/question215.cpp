/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> scores(3);
    if (!(cin >> scores[0] >> scores[1] >> scores[2])) return 0;

    sort(scores.begin(), scores.end());

    cout << scores[1] << "\n";

    return 0;
}