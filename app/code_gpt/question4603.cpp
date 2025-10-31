/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n, comparisons = 0, shifts = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            shifts++;
            comparisons++;
        }
        if (j >= 0) {
            comparisons++;
        }
        arr[j + 1] = key;
        if (j + 1 != i) {
            shifts++;
        }
    }
    
    std::cout << "Array ordenado: \n";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nQuantidade de trocas: " << shifts << "\nQuantidade de comparacoes: " << comparisons << std::endl;

    return 0;
}
