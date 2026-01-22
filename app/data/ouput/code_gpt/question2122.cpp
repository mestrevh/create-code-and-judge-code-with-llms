/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int f(int x) {
    if (x == 0) return 10;
    if (x == 1) return 11;
    if (x == 2) return 27;
    return f(x - 2) - f(x - 3);
}

int main() {
    int n;
    cin >> n;
    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }
    for (int x : inputs) {
        cout << f(x) << endl;
    }
    return 0;
}
