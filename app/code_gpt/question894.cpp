/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int countCombinations(int n, int d, int caras = 0, int coroas = 0) {
    if (n == 0) {
        return abs(caras - coroas) == d ? 1 : 0;
    }
    return countCombinations(n - 1, d, caras + 1, coroas) + 
           countCombinations(n - 1, d, caras, coroas + 1);
}

int main() {
    int N, D;
    cin >> N >> D;
    cout << countCombinations(N, D) << endl;
    return 0;
}
