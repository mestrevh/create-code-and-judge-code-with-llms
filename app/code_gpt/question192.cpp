/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long N, P, Q, R, S, X, Y, I, J;
    cin >> N >> P >> Q >> R >> S >> X >> Y >> I >> J;

    long long A_ij = (P * I + Q) % X + 1;
    long long B_mn = (R * J + S) % Y + 1;

    long long C_ij = A_ij * B_mn;
    
    cout << C_ij << endl;

    return 0;
}
