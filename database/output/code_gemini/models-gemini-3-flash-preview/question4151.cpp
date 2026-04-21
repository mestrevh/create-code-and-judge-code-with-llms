/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> messages;
    char grid[12][12];
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            grid[i][j] = 'o';
        }
    }

    for (int i = 0; i < n; ++i) {
        int key;
        if (!(cin >> key)) break;
        
        string encoded;
        getline(cin, encoded);
        
        if (!encoded.empty() && (encoded[0] == ' ' || encoded[0] == '\t')) {
            encoded.erase(0, 1);
        }
        
        while (!encoded.empty() && (encoded.back() == '\r' || encoded.back() == '\n')) {
            encoded.pop_back();
        }

        string decoded = "";
        int shift = (key % 26 + 26) % 26;
        for (char c : encoded) {
            if (c >= 'A' && c <= 'Z') {
                int val = (c - 'A' - shift + 26) % 26;
                decoded += (char)(val + 'A');
            } else if (c >= 'a' && c <= 'z') {
                int val = (c - 'a' - shift + 26) % 26;
                decoded += (char)(val + 'a');
            } else {
                decoded += c;
            }
        }
        messages.push_back(decoded);

        int x_coord, y_coord;
        if (cin >> x_coord >> y_coord) {
            if (x_coord >= 1 && x_coord <= 12 && y_coord >= 1 && y_coord <= 12) {
                grid[y_coord - 1][x_coord - 1] = 'x';
            }
        }
    }

    for (const string& s : messages) {
        cout << s << "\n";
    }

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}