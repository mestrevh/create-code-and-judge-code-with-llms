/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    int sum = 0;

    while (ss >> word) {
        sum += word[0] - 'a' + 1;
    }

    cout << sum << endl;

    return 0;
}
`