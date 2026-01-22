/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Digite uma String de números: ";
    getline(cin, input);
    
    stringstream ss(input);
    vector<string> numbers;
    string number;

    while (ss >> number) {
        numbers.push_back(number);
    }

    cout << "O inverso dos números digitados é: ";
    for (int i = numbers.size() - 1; i >= 0; --i) {
        cout << numbers[i];
        if (i != 0) cout << ", ";
    }
    cout << "." << endl;

    return 0;
}
