/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& V, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = V[l + i];
    for (int j = 0; j < n2; j++) R[j] = V[m + 1 + j];

    cout << "Executando o merge nos arrays {";
    for (int i = 0; i < n1; i++) {
        cout << L[i] << (i < n1 - 1 ? ", " : "");
    }
    cout << "} e {";
    for (int j = 0; j < n2; j++) {
        cout << R[j] << (j < n2 - 1 ? ", " : "");
    }
    cout << "}\n";

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            V[k++] = L[i++];
        } else {
            V[k++] = R[j++];
        }
    }
    while (i < n1) V[k++] = L[i++];
    while (j < n2) V[k++] = R[j++];

    cout << "array ordenado : {";
    for (int x = l; x <= r; x++) {
        cout << V[x] << (x < r ? ", " : "");
    }
    cout << "}\n";
}

void mergeSort(vector<int>& V, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        cout << "Separando o array V[" << l << "..." << r << "] : {";
        for (int i = l; i <= r; i++) {
            cout << V[i] << (i < r ? ", " : "");
        }
        cout << "} em V[" << l << "..." << m << "] : {";
        for (int i = l; i <= m; i++) {
            cout << V[i] << (i < m ? ", " : "");
        }
        cout << "} e V[" << m + 1 << "..." << r << "] : {";
        for (int i = m + 1; i <= r; i++) {
            cout << V[i] << (i < r ? ", " : "");
        }
        cout << "}\n";

        mergeSort(V, l, m);
        mergeSort(V, m + 1, r);
        merge(V, l, m, r);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    mergeSort(V, 0, N - 1);
    cout << "O array ordenado : ";
    for (int i = 0; i < N; i++) {
        cout << V[i] << (i < N - 1 ? " " : "");
    }
    cout << "\n";
    return 0;
}
