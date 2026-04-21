/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string toUpperStr(string s){
    for(char &c: s) c = (char)toupper((unsigned char)c);
    return s;
}

static bool isInSet(const string& club, const unordered_set<string>& S){
    return S.find(club) != S.end();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> mesa1Clubs = {"FLAMENGO","SPORT","VITORIA"};
    unordered_set<string> mesa2Clubs = {"VASCO","TREZE","SANTOS"};
    unordered_set<string> mesa3Clubs = {"BAHIA","FORTALEZA","GREMIO"};

    int N = 0;
    struct Person { string name; int age; string club; };
    vector<Person> persons;

    while(true){
        string name;
        if(!(cin >> name)) break;
        if(name == "-1") break;
        int age; 
        string club;
        cin >> age >> club;
        persons.push_back({toUpperStr(name), age, toUpperStr(club)});
        N++;
        if(N > 10) break;
        string line;
        if(!(cin >> ws)) break;
        if(cin.peek() == EOF) break;
        if(cin.peek() == '\n'){
            // continue
        }
    }

    for(const auto& p : persons){
        bool placed = false;
        if(!placed && p.age >= 30 && isInSet(p.club, mesa1Clubs)) placed = true;
        if(placed) {}
    }

    array<vector<pair<int,string>>,4> mesas;
    // We'll insert as (orderIndex, name) but input needs the original uppercase name
    // For stable order, use index from insertion
    for(int i=0;i<(int)persons.size();i++){
        const auto& p = persons[i];
        int pos = -1;
        if(p.age >= 30 && isInSet(p.club, mesa1Clubs)) pos = 0;
        else if(p.age >= 18 && p.age <= 36 && isInSet(p.club, mesa2Clubs)) pos = 1;
        else if(p.age >= 10 && p.age <= 18 && isInSet(p.club, mesa3Clubs)) pos = 2;
        else pos = 3;
        mesas[pos].push_back({i+1, p.name});
    }

    for(int m=0;m<4;m++){
        cout << "MESA " << (m+1) << "\n";
        if(mesas[m].empty()){
            cout << "VAZIA\n\n";
        } else {
            for(size_t k=0;k<mesas[m].size();k++){
                cout << mesas[m][k].first << " " << mesas[m][k].second << "\n";
            }
            if(m!=3) cout << "\n";
        }
    }

    return 0;
}