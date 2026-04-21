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

    int n;
    if (!(cin >> n)) return 0;

    vector<int> req(3);
    for (int i = 0; i < 3; ++i) {
        cin >> req[i];
    }

    sort(req.begin(), req.end());

    int evolved = 0;
    for (int i = 0; i < 3; ++i) {
        if (n >= req[i]) {
            n -= req[i];
            evolved++;
        } else {
            break;
        }
    }

    cout << evolved << "\n";

    return 0;
}