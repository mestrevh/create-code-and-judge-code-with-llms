/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static void printArrayBar(const vector<long long>& A) {
    for (size_t i = 0; i < A.size(); i++) {
        if (i) cout << " | ";
        cout << A[i];
    }
    cout << "\n";
}

static void printPartitionLine(const vector<long long>& A, int p, int r, long long pivot) {
    vector<long long> le, gt;
    le.reserve(r - p + 1);
    gt.reserve(r - p + 1);
    for (int i = p; i <= r; i++) {
        if (A[i] <= pivot) le.push_back(A[i]);
        else gt.push_back(A[i]);
    }
    cout << "Partition(A," << p+1 << "," << r+1 << "): ";
    for (size_t i = 0; i < le.size(); i++) {
        if (i) cout << " ";
        cout << le[i];
    }
    cout << " <= " << pivot << " < ";
    for (size_t i = 0; i < gt.size(); i++) {
        if (i) cout << " ";
        cout << gt[i];
    }
    cout << "\n";
}

static int partitionQS(vector<long long>& A, int p, int r) {
    long long pivot = A[r];
    cout << "Pivot: " << pivot << "\n";
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= pivot) {
            i++;
            if (i != j) swap(A[i], A[j]);
        }
    }
    i++;
    if (i != r) swap(A[i], A[r]);
    printPartitionLine(A, p, r, pivot);
    cout << "Estado atual de A: ";
    printArrayBar(A);
    return i;
}

static void quicksort(vector<long long>& A, int p, int r) {
    if (p >= r) return;
    int q = partitionQS(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> A;
    long long x;
    while (cin >> x) A.push_back(x);

    cout << "Estado inicial: ";
    printArrayBar(A);

    if (!A.empty()) quicksort(A, 0, (int)A.size() - 1);

    cout << "Resultado Final: ";
    for (size_t i = 0; i < A.size(); i++) {
        if (i) cout << " | ";
        cout << A[i];
    }
    cout << "\n";
    return 0;
}