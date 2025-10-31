/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

char decodeChar(char c, char keyChar, int keyVal) {
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' - keyVal + 26) % 26;
    } else if (c == '_') {
        return ' ';
    } else if (c == '#') {
        return '.';
    } else if (c == '&') {
        return ',';
    }
    return c; // Just in case, though all conditions are covered
}

int main() {
    string key, encoded, decoded = "";
    getline(cin, key);
    getline(cin, encoded);
    
    int keySum = 0;
    for (char c : key) {
        keySum += c;
    }
    int keyVal = keySum % 26;
    
    for (size_t i = 0; i < encoded.size(); ++i) {
        char keyChar = key[i % key.size()];
        decoded += decodeChar(encoded[i], keyChar, keyVal);
    }
    
    cout << decoded << endl;
    return 0;
}
