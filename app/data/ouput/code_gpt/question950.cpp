/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

string decrypt(const string& S, int& index) {
    if (index >= S.size()) return "";
    string result;
    if (S[index] == '*') {
        result += "(" + to_string(index + 1) + decrypt(S, ++index) + ")";
    } else {
        result += to_string(index + 1) + decrypt(S, ++index);
    }
    return result;
}

int main() {
    string S;
    cin >> S;
    int index = 0;
    cout << decrypt(S, index) << endl;
    return 0;
}
