/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long total_seconds = 0;
    int minutes, seconds;

    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> minutes >> seconds)) break;
        total_seconds += (static_cast<long long>(minutes) * 60 + seconds);
    }

    long long h = total_seconds / 3600;
    long long rem = total_seconds % 3600;
    long long m = rem / 60;
    long long s = rem % 60;

    std::cout << h << "\n" << m << "\n" << s << "\n";

    return 0;
}