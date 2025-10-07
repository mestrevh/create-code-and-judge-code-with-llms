/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    string lang1, lang2, word;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    while (getline(cin, line) && line != "0") {
        int M = stoi(line);
        string orig, dest;
        getline(cin, line);
        stringstream ss(line);
        ss >> orig >> dest;
        
        unordered_map<string, unordered_map<string, vector<string>>> graph;
        
        for (int i = 0; i < M; i++) {
            string lang1, lang2, word;
            getline(cin, line);
            stringstream ss2(line);
            ss2 >> lang1 >> lang2 >> word;
            graph[lang1][lang2].push_back(word);
            graph[lang2][lang1].push_back(word);
        }
        
        queue<tuple<string, string, int>> q; // (current language, last word, current length)
        set<pair<string, char>> visited; // (language, first character of last word)
        
        for (const auto& w : graph[orig]) {
            for (const auto& word : w.second) {
                if (!word.empty()) {
                    q.push({w.first, word, (int)word.size()});
                    visited.insert({orig, word[0]});
                }
            }
        }
        
        int result = INT_MAX;
        while (!q.empty()) {
            auto [curr_lang, last_word, length] = q.front();
            q.pop();
            if (curr_lang == dest) {
                result = min(result, length);
                continue;
            }
            for (const auto& [next_lang, words] : graph[curr_lang]) {
                for (const auto& next_word : words) {
                    if (!next_word.empty() && next_word[0] != last_word[0] && 
                        visited.find({next_lang, next_word[0]}) == visited.end()) {
                        visited.insert({next_lang, next_word[0]});
                        q.push({next_lang, next_word, length + (int)next_word.size()});
                    }
                }
            }
            visited.erase({curr_lang, last_word[0]});
        }
        
        if (result == INT_MAX) {
            cout << "impossivel\n";
        } else {
            cout << result << "\n";
        }
    }
    
    return 0;
}
