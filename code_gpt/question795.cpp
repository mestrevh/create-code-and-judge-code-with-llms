/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> hexagonal_incompletos(50001);
    hexagonal_incompletos[1] = 1;
    for (int n = 2; n <= 50000; ++n) {
        hexagonal_incompletos[n] = hexagonal_incompletos[n - 1] + 6 * (n - 1);
    }

    int N;
    while (cin >> N) {
        cout << hexagonal_incompletos[N] << endl;
    }
    
    return 0;
}
