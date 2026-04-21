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
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> result;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long val;
            cin >> val;
            if (i == j) {
                if (x != 0 && val % x == 0) {
                    result.push_back(val);
                } else if (x == 0 && val == 0) {
                    result.push_back(val);
                }
            }
        }
    }

    if (result.empty()) {
        cout << "NMDX" << endl;
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}