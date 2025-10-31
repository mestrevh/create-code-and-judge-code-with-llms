/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long long concat(int i, int j) {
    return stoll(to_string(i) + to_string(j));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A, B, count = 0;
        cin >> A >> B;

        for (int i = 1; i <= min(A, 9LL); ++i) {
            for (int j = 1; j <= min(B, 9LL); ++j) {
                if (i * j + i + j == concat(i, j)) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
