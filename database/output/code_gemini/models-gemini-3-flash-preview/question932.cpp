/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string temp;
        vector<string> words;
        while (ss >> temp) {
            words.push_back(temp);
        }
        
        if (words.size() == 1 && words[0] == "*") {
            break;
        }
        
        if (words.empty()) {
            continue;
        }

        for (int i = 0; i < (int)words.size(); ++i) {
            string &w = words[i];
            for (int j = 0; j < (int)w.length(); ++j) {
                w[j] = (char)tolower((unsigned char)w[j]);
            }
            
            if (w != "da" && w != "de" && w != "di" && 
                w != "do" && w != "du" && w != "e") {
                if (!w.empty()) {
                    w[0] = (char)toupper((unsigned char)w[0]);
                }
            }
            
            if (i > 0) {
                cout << " ";
            }
            cout << w;
        }
        cout << "\n";
    }
    
    return 0;
}