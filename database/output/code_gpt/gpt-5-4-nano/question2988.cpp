/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string toLowerStr(string s){
    for(char &c: s) c = (char)tolower((unsigned char)c);
    return s;
}

static bool startsWithIgnoreCase(const string& s, const string& pref){
    if(pref.size() > s.size()) return false;
    for(size_t i=0;i<pref.size();i++){
        if(tolower((unsigned char)s[i]) != tolower((unsigned char)pref[i])) return false;
    }
    return true;
}

static bool containsWordIgnoreCase(const string& line, const string& word){
    string a = toLowerStr(line);
    string w = toLowerStr(word);
    return a.find(w) != string::npos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string,int>> hordes;
    string name;
    while(true){
        if(!getline(cin, name)) return 0;
        if(name.size()==0) continue;
        string tmp = name;
        if(tmp.find_first_not_of("-") == string::npos && tmp.find_first_not_of("-") == string::npos){
            if(tmp.find("----------") != string::npos){
                break;
            }
        }
        if(tmp == "----------") break;
        int moral;
        if(!(cin >> moral)) break;
        string dummy;
        getline(cin, dummy);
        hordes.push_back({tmp, moral});
        if(hordes.size() && hordes.back().first == "----------") break;
        streampos pos = cin.tellg();
        if(!cin.good()) break;
    }

    string line;
    vector<string> discursoLines;
    while(true){
        if(!getline(cin, line)) break;
        if(line.size()==0 && cin.eof()) break;
        discursoLines.push_back(line);
    }

    vector<bool> active(hordes.size(), true);
    int remaining = (int)hordes.size();
    int idx = 0;

    for(const string& disLine : discursoLines){
        if(remaining==0) break;
        if(idx >= (int)hordes.size()) break;

        while(idx < (int)hordes.size() && !active[idx]) idx++;
        if(idx >= (int)hordes.size()) break;

        string lineLower = toLowerStr(disLine);
        while(true){
            if(idx >= (int)hordes.size()) break;
            while(idx < (int)hordes.size() && !active[idx]) idx++;
            if(idx >= (int)hordes.size()) break;

            string race = hordes[idx].first;
            int &m = hordes[idx].second;
            char firstChar = race.empty() ? '\0' : race[0];
            int loss = 0;
            if(firstChar != '\0'){
                char target = (char)tolower((unsigned char)firstChar);
                for(char c: disLine){
                    if(tolower((unsigned char)c) == target) loss++;
                }
            }

            if(m > 0) m = max(0, m - loss);

            bool fleeDueName = false;
            if(!race.empty()){
                string raceLower = toLowerStr(race);
                if(lineLower.find(raceLower) != string::npos) fleeDueName = true;
            }

            bool flee = (m==0) || fleeDueName;
            if(flee){
                active[idx] = false;
                remaining--;
                if(idx >= 0 && idx < (int)hordes.size()){
                    cout << "A horda de " << hordes[idx].first << " fugiu\n";
                }
                idx++;
                continue;
            }else{
                break;
            }
        }
    }

    if(remaining==0) cout << "Nao ha mais inimigos a vista.";
    else cout << "Infelizmente o discurso nao foi tao intimidador assim.";

    return 0;
}