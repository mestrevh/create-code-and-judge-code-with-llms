/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n, ans = 1, prev, curr;
    cin >> n;
    cin >> prev;
    for (int i = 1; i < n; ++i) {
        cin >> curr;
        if (curr != prev) ++ans;
        prev = curr;
    }
    cout << ans << endl;
    return 0;
}
