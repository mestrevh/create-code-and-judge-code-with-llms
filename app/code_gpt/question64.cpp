/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n, m || n) {
        int l, k;
        cin >> l >> k;
        vector<int> lengths(k);
        for (int i = 0; i < k; ++i) {
            cin >> lengths[i];
        }

        int area = m * n;
        int neededLength = area * 100 / l; // comprimento necessário em cm
        sort(lengths.rbegin(), lengths.rend());

        int count = 0;
        int totalLength = 0;

        for (int i = 0; i < k; ++i) {
            totalLength += lengths[i];
            count++;
            if (totalLength >= neededLength) {
                cout << count << endl;
                break;
            }
            if (i == k - 1) {
                cout << "impossivel" << endl;
            }
        }
    }
    return 0;
}
