/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> passwords(n);
    unordered_map<char, string> cipher = {
        {'A', "C1"}, {'B', "C2"}, {'C', "C3"}, {'D', "C4"}, {'E', "C5"},
        {'F', "C6"}, {'G', "C7"}, {'H', "C8"}, {'I', "C9"}, {'J', "D1"},
        {'K', "D2"}, {'L', "D3"}, {'M', "D4"}, {'N', "D5"}, {'O', "D6"},
        {'P', "D7"}, {'Q', "D8"}, {'R', "D9"}, {'S', "E1"}, {'T', "E2"},
        {'U', "E3"}, {'V', "E4"}, {'W', "E5"}, {'X', "E6"}, {'Y', "E7"},
        {'Z', "E8"}, {'0', "F1"}, {'1', "F2"}, {'2', "F3"}, {'3', "F4"},
        {'4', "F5"}, {'5', "F6"}, {'6', "F7"}, {'7', "F8"}, {'8', "F9"},
        {'9', "G1"}
    };

    string result;
    int totalLength = 0;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        getline(cin, passwords[i]);
        for (char c : passwords[i]) {
            if (cipher.find(c) != cipher.end()) {
                result += cipher[c];
            } else if (!isalnum(c) || !isupper(c)) {
                valid = false;
                break;
            } else {
                result += c;
            }
        }
        if (!valid) break;
        totalLength += passwords[i].size();
        if (i < n - 1) result += "-";
    }

    if (valid) {
        cout << result << " " << totalLength << endl;
    } else {
        cout << "Alguma senha eh invalida!" << endl;
    }

    return 0;
}
