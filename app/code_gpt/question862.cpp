/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    if (input == "0") return 0;
    
    int max_len = 0, current_len = 0;
    int start = -1, max_start = -1, max_end = -1;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '0') {
            if (current_len == 0) start = i;
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start = start;
                max_end = start + current_len - 1;
            }
            current_len = 0;
        }
    }
    
    if (current_len > max_len) {
        max_start = start;
        max_end = start + current_len - 1;
    }
    
    if (max_len > 0) {
        std::cout << max_start << " " << max_end << std::endl;
    }
    
    return 0;
}
