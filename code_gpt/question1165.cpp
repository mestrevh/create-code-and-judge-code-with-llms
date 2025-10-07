/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::pair<std::string, int> leetTransform(const std::string &input) {
    if (input.empty()) {
        return {"erro", 0};
    }
    for (char ch : input) {
        if (isdigit(ch)) {
            return {"numeros", 0};
        }
    }

    std::string leet;
    int count = 0;

    for (char ch : input) {
        switch (ch) {
            case 'a': case 'A':
                leet += '@'; count++; break;
            case 'e': case 'E':
                leet += '3'; count++; break;
            case 'i': case 'I':
                leet += '1'; count++; break;
            case 'o': case 'O':
                leet += '0'; count++; break;
            case 't': case 'T':
                leet += '7'; count++; break;
            case 's': case 'S':
                leet += '5'; count++; break;
            default:
                leet += ch; break;
        }
    }
    
    return {leet, count};
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    auto [leet, count] = leetTransform(input);
    std::cout << leet << std::endl << count << std::endl;
    return 0;
}
