/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int K, N, M, X, Y;
    while (cin >> K, K) {
        cin >> N >> M;
        for (int i = 0; i < K; ++i) {
            cin >> X >> Y;
            if (X == N || Y == M) {
                cout << "divisa" << endl;
            } else if (X < N && Y > M) {
                cout << "NO" << endl;
            } else if (X > N && Y > M) {
                cout << "NE" << endl;
            } else if (X > N && Y < M) {
                cout << "SE" << endl;
            } else {
                cout << "SO" << endl;
            }
        }
    }
    return 0;
}
