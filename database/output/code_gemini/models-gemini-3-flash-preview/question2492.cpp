/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    // CP standard I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    // Reading the input word. cin skips leading whitespace and stops at the first trailing whitespace.
    if (!(std::cin >> s)) return 0;

    int n = (int)s.length();
    bool is_palindrome = true;

    // Using two pointers approach (i and n-1-i) to check for palindrome property in O(N) time.
    // Space complexity is O(N) to store the string.
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    // Output True or False as specified in the problem format.
    if (is_palindrome) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    return 0;
}