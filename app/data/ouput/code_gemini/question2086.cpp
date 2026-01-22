/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int first_num;
    while (std::cin >> first_num) {
        if (first_num == -1) {
            break;
        }

        int numbers[1000];
        numbers[0] = first_num;

        for (int i = 1; i < 1000; ++i) {
            std::cin >> numbers[i];
        }

        int n_to_find;
        std::cin >> n_to_find;

        int count = 0;
        for (int i = 0; i < 1000; ++i) {
            if (numbers[i] == n_to_find) {
                count++;
            }
        }

        std::cout << n_to_find << " appeared " << count << " times\n";
    }

    return 0;
}
