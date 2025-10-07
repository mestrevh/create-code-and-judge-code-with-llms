/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b, c;
    std::cin >> a >> b >> c;
    
    std::vector<int> scores = {a, b, c};
    
    std::sort(scores.begin(), scores.end());
    
    std::cout << scores[1] << std::endl;
    
    return 0;
}
