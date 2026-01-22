/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n), VetOUr(n), ANDrray(n);
    vector<int> freqA(n + 1, 0), freqB(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        freqA[A[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        freqB[B[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        VetOUr[i] = A[i] | B[i];
        ANDrray[i] = A[i] & B[i];
    }

    cout << "VetOUr:\n";
    for (int i = 0; i < n; ++i) {
        cout << VetOUr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    cout << "ANDrray:\n";
    for (int i = 0; i < n; ++i) {
        cout << ANDrray[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    cout << "Frequencia em A:\n";
    for (int i = 0; i <= n; ++i) {
        cout << freqA[i];
        if (i < n) cout << " ";
    }
    cout << endl;

    cout << "Frequencia em B:\n";
    for (int i = 0; i <= n; ++i) {
        cout << freqB[i];
        if (i < n) cout << " ";
    }
    cout << endl;

    return 0;
}
