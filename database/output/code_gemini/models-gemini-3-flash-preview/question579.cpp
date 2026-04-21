/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void printArray(const vector<int>& A, const string& prefix) {
    cout << prefix;
    for (int i = 0; i < (int)A.size(); ++i) {
        cout << A[i] << (i == (int)A.size() - 1 ? "" : " | ");
    }
    cout << endl;
}

int partition(vector<int>& A, int p, int r) {
    int pivot = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    int q = i + 1;

    cout << "\nPivot: " << pivot << endl;
    cout << "Partition(A," << p + 1 << "," << r + 1 << "): ";
    for (int k = p; k < q; ++k) {
        cout << A[k] << " ";
    }
    cout << "<= " << pivot << " <";
    for (int k = q + 1; k <= r; ++k) {
        cout << " " << A[k];
    }
    cout << endl;
    printArray(A, "Estado atual de A: ");

    return q;
}

void quicksort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;
    if (line.empty()) return 0;

    stringstream ss(line);
    vector<int> A;
    int val;
    while (ss >> val) {
        A.push_back(val);
    }

    if (A.empty()) return 0;

    printArray(A, "Estado inicial: ");
    quicksort(A, 0, (int)A.size() - 1);
    cout << "\n";
    printArray(A, "Resultado Final: ");

    return 0;
}