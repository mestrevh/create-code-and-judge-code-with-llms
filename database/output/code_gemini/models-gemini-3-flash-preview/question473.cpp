/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p, m;
    double r;
    int approved_count = 0;

    while (std::cin >> p && p >= 0) {
        if (!(std::cin >> m >> r)) break;
        
        bool passes_portuguese = (p >= 40);
        bool passes_math = (m >= 21);
        bool passes_writing = (r >= 7.0);

        if (passes_portuguese && passes_math && passes_writing) {
            approved_count++;
        }
    }

    std::cout << approved_count << std::endl;

    return 0;
}