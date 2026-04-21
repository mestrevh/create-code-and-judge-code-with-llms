/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    // Optimization of I/O operations for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string name;
    // Reading the input string. Using cin >> name to capture the word provided in test cases.
    // If the name could contain spaces, std::getline(std::cin, name) would be preferred.
    if (!(std::cin >> name)) return 0;

    // Convert the entire string to uppercase as per the test case requirements
    for (size_t i = 0; i < name.length(); ++i) {
        name[i] = (char)std::toupper((unsigned char)name[i]);
    }

    // Build and print the staircase format
    std::string current_step = "";
    for (char c : name) {
        current_step += c;
        std::cout << current_step << "\n";
    }

    return 0;
}