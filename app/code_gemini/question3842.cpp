/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, n;
    std::cin >> a >> n;

    long long meme_man_time = a;
    long long elapsed_time = 0;
    long long time_limit_seconds = n * 60;

    while (true) {
        if (elapsed_time > time_limit_seconds) {
            std::cout << "fui pedir comida mesmo" << std::endl;
            break;
        }

        if (meme_man_time == 0) {
            std::cout << elapsed_time << std::endl;
            break;
        }

        if (meme_man_time % 13 == 0) {
            long long potential_new_time = meme_man_time - 60;
            if (potential_new_time > 0 && potential_new_time % 60 == 0) {
                meme_man_time += 30;
            } else {
                meme_man_time -= 60;
            }
        }
        
        elapsed_time++;
        meme_man_time++;
    }

    return 0;
}
