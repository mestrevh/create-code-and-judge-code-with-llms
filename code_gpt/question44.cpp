/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int arr[3] = {a, b, c};
    std::sort(arr, arr + 3);
    std::cout << arr[1] << std::endl;
    return 0;
}
