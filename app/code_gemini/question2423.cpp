/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    long long t1, v1, t2, v2, t3, v3;
    std::cin >> t1 >> v1;
    std::cin >> t2 >> v2;
    std::cin >> t3 >> v3;

    int ideal = (n - m) / 2;

    if (ideal > m) {
        std::cout << "Não cantarei, desculpa.\n";
    } else {
        long long m_plus_1 = m + 1;
        long long vergonha1 = (t1 * v1) / m_plus_1;
        long long vergonha2 = (t2 * v2) / m_plus_1;
        long long vergonha3 = (t3 * v3) / m_plus_1;

        int chosen_song = 1;
        long long min_vergonha = vergonha1;

        if (vergonha2 < min_vergonha) {
            chosen_song = 2;
            min_vergonha = vergonha2;
        }

        if (vergonha3 < min_vergonha) {
            chosen_song = 3;
        }

        std::cout << "Você deve cantar a música " << chosen_song << ", boa sorte!\n";
    }

    return 0;
}
