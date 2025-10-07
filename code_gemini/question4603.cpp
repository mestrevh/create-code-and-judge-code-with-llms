/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int shifts = 0;
    int comparisons = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        comparisons++;
        arr[j + 1] = key;
    }

    cout << "Array ordenado: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Quantidade de trocas: " << shifts << endl;
    cout << "Quantidade de comparacoes: " << comparisons << endl;


    return 0;
}
