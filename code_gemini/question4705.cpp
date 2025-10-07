/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string inverter_string2(string s) {
    string processed_s = "";
    for (char c : s) {
        if (isalnum(c)) {
            processed_s += tolower(c);
        }
    }
    string reversed_s = processed_s;
    reverse(reversed_s.begin(), reversed_s.end());
    if (processed_s == reversed_s) {
        return "Eh um palindromo";
    } else {
        return "Nao eh um palindromo";
    }
}

int main() {
    string input_string;
    getline(cin, input_string);
    cout << inverter_string2(input_string) << endl;
    return 0;
}
