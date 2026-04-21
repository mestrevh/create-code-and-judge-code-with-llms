/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    string line;
    // Consume the remaining newline character after reading the integer n
    getline(cin, line);

    while (n--) {
        if (!getline(cin, line)) {
            break;
        }

        bool capitalize_next = true;
        for (int i = 0; i < (int)line.length(); ++i) {
            unsigned char uc = (unsigned char)line[i];
            
            if (uc == '.') {
                // After a period, the next alphabetical character should be capitalized
                capitalize_next = true;
            } else if (isalpha(uc)) {
                if (capitalize_next) {
                    line[i] = (char)toupper(uc);
                    capitalize_next = false;
                }
            }
            // Non-alphabetical characters (digits, spaces, etc.) do not reset the 
            // capitalize_next flag, as we are looking for the first actual letter.
        }
        
        cout << line << "\n";
    }

    return 0;
}