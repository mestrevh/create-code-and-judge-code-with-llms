/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n, dist = 0, pos = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        dist += abs(pos - x);
        pos = x;
    }
    cout << dist << endl;
    return 0;
}
