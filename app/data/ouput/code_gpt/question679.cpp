/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long K, A, B, C, D;
        cin >> K >> A >> B >> C >> D;
        long long count = 0;

        for (long long X = A; X <= B; ++X) {
            for (long long Y = C; Y <= D; ++Y) {
                if (X + Y > K) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
