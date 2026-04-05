/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string process_lyrics(string lyrics) {
    stringstream ss(lyrics);
    string word;
    string p = "";
    while (ss >> word) {
        if (!word.empty()) {
            string capitalized_word = word;
            capitalized_word[0] = (char)toupper((unsigned char)capitalized_word[0]);
            for (int i = 1; i < (int)capitalized_word.length(); i++) {
                capitalized_word[i] = (char)tolower((unsigned char)capitalized_word[i]);
            }
            p += capitalized_word;
        }
    }
    string final_p = "";
    for (char c : p) {
        if (c == 'a') final_p += '@';
        else if (c == 'E') final_p += '%';
        else if (c == 'e') final_p += '!';
        else if (c == 'i') final_p += '@';
        else if (c == 'o') final_p += '#';
        else if (c == 'u') final_p += '$';
        else final_p += c;
    }
    return final_p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string lyrics;
    if (!getline(cin, lyrics)) return 0;
    
    int K;
    if (!(cin >> K)) return 0;
    int N;
    if (!(cin >> N)) return 0;

    string P = process_lyrics(lyrics);
    int accepted_count = 0;
    vector<pair<string, string>> dict;

    for (int i = 0; i < N && accepted_count < K; i++) {
        int M;
        if (!(cin >> M)) break;
        
        string partA = "";
        if (accepted_count < (int)P.length()) {
            partA = P.substr(accepted_count, 5);
        }
        
        string partB = "";
        if ((int)P.length() >= 5) {
            partB = P.substr((int)P.length() - 5, 5);
        } else {
            partB = P;
        }
        
        string partC = "";
        if (M < (int)P.length()) {
            partC = P.substr(M, 5);
        }
        
        string pass = partA + partB + partC;
        reverse(pass.begin(), pass.end());
        
        cout << pass << endl;
        
        string choice;
        if (!(cin >> choice)) break;
        if (choice == "s" || choice == "S") {
            string username;
            if (cin >> username) {
                dict.push_back({username, pass});
                accepted_count++;
            }
        }
    }

    cout << "{";
    for (int i = 0; i < (int)dict.size(); i++) {
        cout << "'" << dict[i].first << "': ";
        string pass = dict[i].second;
        bool has_single_quote = false;
        for (char c : pass) {
            if (c == '\'') {
                has_single_quote = true;
                break;
            }
        }
        if (has_single_quote) cout << "\"" << pass << "\"";
        else cout << "'" << pass << "'";
        if (i < (int)dict.size() - 1) cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}