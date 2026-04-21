/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t1, t2, t3, t4;
    if (cin >> t1 >> t2 >> t3 >> t4) {
        int result = (t1 + t2 + t3 + t4) - 3;
        cout << result << "\n";
    }

    return 0;
}