/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string rnaa_sequence;
    while (std::cin >> rnaa_sequence && rnaa_sequence != "Z") {
        std::stack<char> bases;
        int bonds = 0;

        for (char base : rnaa_sequence) {
            if (!bases.empty()) {
                char top_base = bases.top();
                if ((base == 'B' && top_base == 'S') || (base == 'S' && top_base == 'B')) {
                    bases.pop();
                    bonds++;
                } else if ((base == 'C' && top_base == 'F') || (base == 'F' && top_base == 'C')) {
                    bases.pop();
                    bonds++;
                } else {
                    bases.push(base);
                }
            } else {
                bases.push(base);
            }
        }
        std::cout << bonds << "\n";
    }

    return 0;
}
