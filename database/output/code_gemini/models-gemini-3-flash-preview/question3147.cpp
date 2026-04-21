/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

void troca(int &A, int &B) {
    if (A > B) {
        int temp = A;
        A = B;
        B = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (cin >> a >> b) {
        troca(a, b);
        cout << a << " " << b << "\n";
    }

    return 0;
}