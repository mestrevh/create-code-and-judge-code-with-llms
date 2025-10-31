/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        long long result = (A + B) * (C + D);
        cout << result << endl;
    }
    return 0;
}
