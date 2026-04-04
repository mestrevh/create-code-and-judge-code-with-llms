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

    int n;
    while (cin >> n) {
        vector<long long> cpfs(n);
        for (int i = 0; i < n; ++i) {
            cin >> cpfs[i];
        }
        vector<int> grades(n);
        for (int i = 0; i < n; ++i) {
            cin >> grades[i];
        }

        int m;
        if (!(cin >> m)) break;
        while (m--) {
            long long query_cpf;
            cin >> query_cpf;
            auto it = lower_bound(cpfs.begin(), cpfs.end(), query_cpf);
            if (it != cpfs.end() && *it == query_cpf) {
                int index = distance(cpfs.begin(), it);
                cout << grades[index] << "\n";
            } else {
                cout << "NAO SE APRESENTOU\n";
            }
        }
    }

    return 0;
}