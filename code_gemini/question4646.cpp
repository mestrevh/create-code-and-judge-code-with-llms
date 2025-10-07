/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    if (count % 2 == 0) {
        cout << "SIM" << endl;
    } else {
        cout << "NÃO" << endl;
    }

    return 0;
}
