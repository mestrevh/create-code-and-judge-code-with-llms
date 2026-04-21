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

    int n1;
    if (!(cin >> n1) || n1 < 1) {
        cout << "Erro - A lista deve ter pelo menos 1 elemento." << endl;
        return 0;
    }

    vector<int> l1(n1);
    for (int i = 0; i < n1; ++i) {
        if (!(cin >> l1[i])) break;
    }

    int n2;
    if (!(cin >> n2) || n2 < 1) {
        cout << "Erro - A lista deve ter pelo menos 1 elemento." << endl;
        return 0;
    }

    vector<int> l2(n2);
    for (int i = 0; i < n2; ++i) {
        if (!(cin >> l2[i])) break;
    }

    for (int i = 0; i < n1; ++i) {
        cout << l1[i] << " ";
    }

    for (int i = 0; i < n2; ++i) {
        cout << l2[i] << (i == n2 - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}