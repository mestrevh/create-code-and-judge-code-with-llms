/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void print_subarray(const std::vector<int>& arr, int start, int end) {
    std::cout << "{";
    for (int i = start; i <= end; ++i) {
        std::cout << arr[i];
        if (i < end) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}

void merge(std::vector<int>& v, int l, int m, int r) {
    std::cout << "Executando o merge nos arrays ";
    print_subarray(v, l, m);
    std::cout << " e ";
    print_subarray(v, m + 1, r);
    std::cout << std::endl;

    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = v[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = v[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }

    std::cout << "array ordenado : ";
    print_subarray(v, l, r);
    std::cout << std::endl;
}

void mergesort(std::vector<int>& v, int l, int r) {
    if (l < r) {
        int m = (l + r - 1) / 2;

        std::cout << "Separando o array V[" << l << "..." << r << "] : ";
        print_subarray(v, l, r);
        std::cout << " em V[" << l << "..." << m << "] : ";
        print_subarray(v, l, m);
        std::cout << " e V[" << m + 1 << "..." << r << "] : ";
        print_subarray(v, m + 1, r);
        std::cout << std::endl;

        mergesort(v, l, m);
        mergesort(v, m + 1, r);

        merge(v, l, m, r);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "\nO array ordenado : " << std::endl;
        return 0;
    }

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    
    mergesort(v, 0, n - 1);

    std::cout << "\nO array ordenado : ";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
