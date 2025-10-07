/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string decodeMessage(string message, int shift) {
    for (char &c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return message;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> decodedMessages;
    vector<pair<int, int>> coordinates;
    
    for (int i = 0; i < n; ++i) {
        int shift;
        string encodedMessage;
        getline(cin >> ws, encodedMessage);
        cin >> shift;
        coordinates.emplace_back(i, shift);
        
        decodedMessages.push_back(decodeMessage(encodedMessage, shift));
        int x, y;
        cin >> x >> y;
        coordinates[i] = {x, y};
    }
    
    for (const string &msg : decodedMessages) {
        cout << msg << endl;
    }
    
    vector<vector<char>> grid(12, vector<char>(12, 'o'));
    for (auto &coord : coordinates) {
        grid[coord.first][coord.second] = 'x';
    }
    
    for (const auto &row : grid) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}
