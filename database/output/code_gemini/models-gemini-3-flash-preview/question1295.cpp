/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void printElements(const vector<int>& v, int l, int r) {
    cout << "{";
    for (int i = l; i <= r; ++i) {
        cout << v[i];
        if (i < r) cout << ", ";
    }
    cout << "}";
}

void merge(vector<int>& v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = (l + r - 1) / 2;
        
        cout << "Separando o array V[" << l << "..." << r << "] : ";
        printElements(v, l, r);
        cout << " em V[" << l << "..." << m << "] : ";
        printElements(v, l, m);
        cout << " e V[" << m + 1 << "..." << r << "] : ";
        printElements(v, m + 1, r);
        cout << "\n";

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        cout << "Executando o merge nos arrays ";
        printElements(v, l, m);
        cout << " e ";
        printElements(v, m + 1, r);
        cout << "\n";

        merge(v, l, m, r);

        cout << "array ordenado : ";
        printElements(v, l, r);
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        cout << "\nO array ordenado :" << endl;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    mergeSort(v, 0, n - 1);

    cout << "\nO array ordenado :";
    for (int i = 0; i < n; i++) {
        cout << " " << v[i];
    }
    cout << endl;

    return 0;
}