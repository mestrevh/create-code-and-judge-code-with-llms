/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    string line;
    getline(cin, line);

    while (n--) {
        if (!getline(cin, line)) break;
        
        string filtered = "";
        for (char c : line) {
            if (c != ' ') {
                filtered += (char)tolower((unsigned char)c);
            }
        }

        if (filtered.empty()) {
            cout << "SIM\n";
            continue;
        }

        bool is_palindrome = true;
        int left = 0;
        int right = (int)filtered.size() - 1;
        
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                is_palindrome = false;
                break;
            }
            left++;
            right--;
        }

        if (is_palindrome) {
            cout << "SIM\n";
        } else {
            cout << "NAO\n";
        }
    }

    return 0;
}