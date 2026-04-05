/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

/**
 * Funcao que verifica se a string processada (sem espacos e case-insensitive)
 * eh um palindromo.
 */
bool inverter_string2(const string& s) {
    string filtered = "";
    for (char c : s) {
        if (!isspace(static_cast<unsigned char>(c))) {
            filtered += static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
    }
    
    if (filtered.empty()) return true;
    
    int left = 0;
    int right = (int)filtered.length() - 1;
    
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

int main() {
    // Otimizacao de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    // Leitura da string (incluindo espacos)
    if (getline(cin, input)) {
        // Remocao de possivel \r no final da string em sistemas Windows
        if (!input.empty() && input.back() == '\r') {
            input.pop_back();
        }
        
        if (inverter_string2(input)) {
            cout << "Eh um palindromo" << endl;
        } else {
            cout << "Nao eh um palindromo" << endl;
        }
    }

    return 0;
}