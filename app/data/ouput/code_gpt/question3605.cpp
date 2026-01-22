/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr;
    int num;
    while (std::cin >> num) {
        arr.push_back(num);
    }

    int n = arr.size();
    if (n < 3) return 0;

    // Encontra a mediana de 3
    int mid = n / 2;
    std::vector<int> med_arr = {arr[0], arr[mid], arr[n - 1]};
    std::sort(med_arr.begin(), med_arr.end());
    int pivot = med_arr[1];

    // Particiona o vetor
    std::vector<int> left, right;
    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else right.push_back(x);
    }
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());

    std::cout << pivot << std::endl;
    for (int x : left) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
