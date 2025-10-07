/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);

        string processed_line = "";
        for (char c : line) {
            if (isalnum(c)) {
                processed_line += tolower(c);
            }
        }

        string reversed_line = processed_line;
        reverse(reversed_line.begin(), reversed_line.end());

        if (processed_line == reversed_line) {
            cout << "Aluno " << i << ": Correto!, entendeu e trouxe um palindromo" << endl;
        } else {
            cout << "Aluno " << i << ": Incorreto!, não entendeu o que é um palindromo" << endl;
        }
    }

    return 0;
}
