/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string processString(const string& s) {
    string result;
    for (char c : s) {
        if (c == 'a' || c == 'A') result += '@';
        else if (c == 'e' || c == 'E') result += '%';
        else if (c == 'i' || c == 'I') result += '!';
        else if (c == 'o' || c == 'O') result += '#';
        else if (c == 'u' || c == 'U') result += '$';
        else if (c != ' ') result += c;
    }
    return result;
}

string generatePassword(const string& music, int passwordIndex, int magicNum) {
    string password;
    int start = passwordIndex;
    int end = passwordIndex + 5;
    int magicPos = magicNum + 5;

    if (end > music.length() || magicPos > music.length()) return "";

    password += music.substr(start, 5);
    password += music.substr(music.length() - 5);
    password += music.substr(magicPos, 5);
    reverse(password.begin(), password.end());

    return password;
}

int main() {
    string music;
    getline(cin, music);
    music = processString(music);
    
    unordered_map<string, string> userPasswordMap;
    int numPasswords;
    cin >> numPasswords;

    for (int i = 0; i < numPasswords; ++i) {
        int passwordIndex, magicNum;
        char accept;
        string username;

        cin >> passwordIndex >> accept >> username;

        if (accept == 's') {
            cin >> magicNum;
            string password = generatePassword(music, passwordIndex, magicNum);
            if (password.length() >= 15) {
                userPasswordMap[username] = password.substr(0, 15);
            }
        }
    }

    for (const auto& entry : userPasswordMap) {
        cout << entry.second << endl;
    }
    cout << "{";
    for (auto it = userPasswordMap.begin(); it != userPasswordMap.end(); ) {
        cout << "'" << it->first << "': '" << it->second << "'";
        if (++it != userPasswordMap.end()) cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
