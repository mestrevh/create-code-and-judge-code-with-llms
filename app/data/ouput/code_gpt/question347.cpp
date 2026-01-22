/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int triangular(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int N;
    cin >> N;
    int nth = triangular(N);
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += triangular(i);
    }

    char paridade;
    if (nth % 2 == 0 && sum % 2 == 0) {
        paridade = 'P';
    } else if (nth % 2 != 0 && sum % 2 != 0) {
        paridade = 'I';
    } else {
        paridade = 'N';
    }

    cout << nth << " " << sum << " " << paridade << endl;
    return 0;
}
