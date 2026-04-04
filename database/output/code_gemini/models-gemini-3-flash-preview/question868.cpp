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

    int N, D;
    if (!(cin >> N >> D)) return 0;

    vector<int> matches;
    matches.reserve(N);

    for (int i = 0; i < N; ++i) {
        int num;
        if (!(cin >> num)) break;
        if (num % 10 == D) {
            matches.push_back(num);
        }
    }

    sort(matches.begin(), matches.end(), greater<int>());

    vector<int> result;
    for (int i = 0; i < 5; ++i) {
        if (i < (int)matches.size()) {
            result.push_back(matches[i]);
        } else {
            result.push_back(-1);
        }
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < 5; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}