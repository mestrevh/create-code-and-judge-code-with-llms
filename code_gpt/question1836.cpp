/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    while (getline(cin, input) && input != "FIM") {
        string output;
        bool error = false;
        for (char c : input) {
            if (c >= '0' && c <= '9') {
                output += c;
            } else if (c == 'o' || c == 'O') {
                output += '0';
            } else if (c == 'l') {
                output += '1';
            } else {
                error = true;
                break;
            }
        }
        if (error) {
            cout << "ERRO" << endl;
        } else {
            cout << (output.empty() ? "0" : output) << endl;
        }
    }
    return 0;
}
