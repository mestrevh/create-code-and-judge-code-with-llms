/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<char, int> required;
    required['v'] = 1;
    required['o'] = 1;
    required['u'] = 1;
    required['p'] = 2;
    required['a'] = 2;
    required['s'] = 2;
    required['r'] = 1;
    required['e'] = 1;
    required['m'] = 1;
    required['1'] = 1;

    std::string line;
    std::getline(std::cin, line);

    std::map<char, int> available;
    for (char c : line) {
        available[tolower(c)]++;
    }

    int result = INT_MAX;
    for (auto const& pair : required) {
        char key = pair.first;
        int val = pair.second;
        result = std::min(result, available[key] / val);
    }

    std::cout << result << std::endl;

    return 0;
}
