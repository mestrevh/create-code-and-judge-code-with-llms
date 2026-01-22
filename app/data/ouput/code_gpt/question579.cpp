/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void printArray(const vector<int>& A) {
    for (size_t i = 0; i < A.size(); ++i) {
        if (i > 0) cout << " | ";
        cout << A[i];
    }
    cout << endl;
}

int partition(vector<int>& A, int p, int r) {
    int pivot = A[r - 1];
    int i = p - 1;
    
    for (int j = p; j < r - 1; ++j) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r - 1]);
    
    cout << "Pivot: " << pivot << endl;
    cout << "Partition(A," << p << "," << r << "): ";
    
    for (int k = p - 1; k <= i; ++k) cout << A[k] << " ";
    cout << "<= " << pivot << " < ";
    for (int k = i + 2; k < r; ++k) cout << A[k] << " ";
    cout << endl;

    cout << "Estado atual de A: ";
    printArray(A);
    
    return i + 1;
}

void quicksort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> A;
    int num;
    
    while (iss >> num) {
        A.push_back(num);
    }
    
    cout << "Estado inicial: ";
    printArray(A);
    
    quicksort(A, 1, A.size() + 1);
    
    cout << "Resultado Final: ";
    printArray(A);
    
    return 0;
}
