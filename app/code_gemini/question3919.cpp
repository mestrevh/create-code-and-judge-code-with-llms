/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int count = 0;
    int x;
    for (int i = 0; i < 20; ++i) {
        if (std::cin >> x) {
            if (x == -1) {
                break;
            }
            if (x == n) {
                count++;
            }
        } else {
            break;
        }
    }
    std::cout << n << " aparece " << count << " vezes\n";
    return 0;
}
