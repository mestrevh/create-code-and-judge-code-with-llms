/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != 0) {
        for (int i = 0; i < N; ++i) {
            int a, b, c, d, e;
            std::cin >> a >> b >> c >> d >> e;

            int marked_count = 0;
            int marked_index = -1;

            if (a <= 127) {
                marked_count++;
                marked_index = 0;
            }
            if (b <= 127) {
                marked_count++;
                marked_index = 1;
            }
            if (c <= 127) {
                marked_count++;
                marked_index = 2;
            }
            if (d <= 127) {
                marked_count++;
                marked_index = 3;
            }
            if (e <= 127) {
                marked_count++;
                marked_index = 4;
            }

            if (marked_count == 1) {
                char answer = 'A' + marked_index;
                std::cout << answer << "\n";
            } else {
                std::cout << "*\n";
            }
        }
    }

    return 0;
}
