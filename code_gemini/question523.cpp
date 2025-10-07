/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::map<std::string, int> word_times;
    for (int i = 0; i < n; ++i) {
        std::string word;
        int time;
        std::cin >> word >> time;
        word_times[word] = time;
    }

    int m;
    std::cin >> m;
    long long total_time = 0;
    for (int i = 0; i < m; ++i) {
        std::string word_in_text;
        std::cin >> word_in_text;
        total_time += word_times[word_in_text];
    }
    std::cout << total_time << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Caso " << i << ": ";
        solve();
    }

    return 0;
}
