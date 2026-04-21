/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Funcao de merge para o algoritmo Merge Sort.
 * Combina dois subvetores ordenados em um unico vetor ordenado.
 */
void merge(vector<int>& arr, vector<int>& tmp, int l, int m, int r) {
    int i = l;      // Indice inicial do primeiro subvetor
    int j = m + 1;  // Indice inicial do segundo subvetor
    int k = l;      // Indice inicial do vetor temporario

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        tmp[k++] = arr[i++];
    }

    while (j <= r) {
        tmp[k++] = arr[j++];
    }

    for (int p = l; p <= r; p++) {
        arr[p] = tmp[p];
    }
}

/**
 * Implementacao do Merge Sort.
 * Complexidade de tempo: O(N log N) no pior caso.
 */
void mergeSort(vector<int>& arr, vector<int>& tmp, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, tmp, l, m);
        mergeSort(arr, tmp, m + 1, r);
        merge(arr, tmp, l, m, r);
    }
}

/**
 * Implementacao da Busca Binaria.
 * Complexidade de tempo: O(log N) por consulta.
 */
bool binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    // Otimizacao de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> codes(N);
    for (int i = 0; i < N; ++i) {
        cin >> codes[i];
    }

    // Ordenacao obrigatoria utilizando Merge Sort
    vector<int> tmp(N);
    mergeSort(codes, tmp, 0, N - 1);

    int Q;
    if (!(cin >> Q)) return 0;

    while (Q--) {
        int query;
        cin >> query;
        // Busca obrigatoria utilizando Busca Binaria
        if (binarySearch(codes, query)) {
            cout << "SIM\n";
        } else {
            cout << "NAO\n";
        }
    }

    return 0;
}