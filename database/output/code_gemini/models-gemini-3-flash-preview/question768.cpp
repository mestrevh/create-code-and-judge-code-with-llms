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

    int n1;
    while (cin >> n1) {
        vector<int> v1(n1);
        for (int i = 0; i < n1; ++i) {
            cin >> v1[i];
        }

        int n2;
        if (!(cin >> n2)) break;
        vector<int> v2(n2);
        for (int i = 0; i < n2; ++i) {
            cin >> v2[i];
        }

        vector<int> res;
        res.reserve(max(n1, n2) + 1);

        int i = n1 - 1;
        int j = n2 - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += v1[i];
                i--;
            }
            if (j >= 0) {
                sum += v2[j];
                j--;
            }
            res.push_back(sum % 10);
            carry = sum / 10;
        }

        for (int k = (int)res.size() - 1; k >= 0; --k) {
            cout << res[k];
        }
        cout << "\n";
    }

    return 0;
}