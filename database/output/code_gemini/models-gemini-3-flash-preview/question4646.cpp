/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (getline(cin, line)) {
        stringstream ss(line);
        string word;
        int word_count = 0;
        while (ss >> word) {
            word_count++;
        }

        if (word_count % 2 == 0) {
            cout << "SIM" << endl;
        } else {
            cout << "NÃO" << endl;
        }
    }

    return 0;
}