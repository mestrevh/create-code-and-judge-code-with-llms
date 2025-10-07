/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long F(int n, long long C, long long T) {
    if (n == 0) return C;
    if (n == 1) return T;
    return 2 * F(n - 1, C, T) + F(n - 2, C, T);
}

void solve(long long C, long long T, long long P, int attempts = 0, long long blood_loss = 0) {
    long long force = F(attempts, C, T);
    blood_loss += 12;

    if (blood_loss > 300) {
        cout << "Eleven ficou fraca demais e acabou desmaiando" << endl;
        return;
    }
    
    if (force >= P) {
        cout << "Eleven perdeu " << blood_loss << "ml de sangue." << endl;
        return;
    }
    
    solve(C, T, P, attempts + 1, blood_loss);
}

int main() {
    long long C, T, P;
    cin >> C >> T >> P;
    solve(C, T, P);
    return 0;
}
