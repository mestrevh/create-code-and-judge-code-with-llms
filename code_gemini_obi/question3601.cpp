/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n, d = 0;
    cin >> n;
    int dist;
    for (int i = 0; i < n; ++i) {
        cin >> dist;
        d += dist;
    }
    cout << d + (n - 1) << endl;
    return 0;
}
