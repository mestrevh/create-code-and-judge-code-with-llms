/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::cin >> line && line != "0") {
        int maxLength = 0;
        int maxStart = -1;
        int maxEnd = -1;

        int currentLength = 0;
        int currentStart = -1;

        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '0') {
                if (currentLength == 0) {
                    currentStart = i;
                }
                currentLength++;
            } else {
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    maxStart = currentStart;
                    maxEnd = i - 1;
                }
                currentLength = 0;
            }
        }

        if (currentLength > maxLength) {
            maxLength = currentLength;
            maxStart = currentStart;
            maxEnd = line.length() - 1;
        }

        std::cout << maxStart << " " << maxEnd << std::endl;
    }

    return 0;
}
