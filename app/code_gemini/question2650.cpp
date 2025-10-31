/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        freq[x]++;
    }
    for (const auto& pair : freq) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
    return 0;
}
