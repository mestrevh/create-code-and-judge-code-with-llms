/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    string output;
    for (int i = 0; i < input.size(); i += 2) {
        output += input[i];
    }
    cout << output << endl;
    return 0;
}
