/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string monthName(int m){
    static const string months[12] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    if(m < 1 || m > 12) return "";
    return months[m-1];
}

static string normalizeMonthForCompare(string s){
    auto rm = [&](const string& a){
        s.erase(remove(s.begin(), s.end(), a[0]), s.end());
    };
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;

    unordered_map<int, vector<string>> byDayMonth;
    byDayMonth.reserve((size_t)N * 2);

    for(int i = 0; i < N; i++){
        string name;
        int day, month;
        cin >> name >> day >> month;
        int key = (month << 6) | day;
        byDayMonth[key].push_back(name);
    }

    vector<pair<pair<int,int>, vector<string>>> groups;
    groups.reserve(byDayMonth.size());
    for(auto &kv : byDayMonth){
        int key = kv.first;
        int month = key >> 6;
        int day = key & 63;
        if((int)kv.second.size() >= 2){
            groups.push_back({{day, month}, kv.second});
        }
    }

    if(groups.empty()){
        cout << "Ninguem faz aniversario no mesmo dia\n";
        return 0;
    }

    sort(groups.begin(), groups.end(), [](const auto& a, const auto& b){
        if(a.first.first != b.first.first) return a.first.first < b.first.first;
        return a.first.second < b.first.second;
    });

    for(auto &g : groups){
        int day = g.first.first;
        int month = g.first.second;
        string mname = monthName(month);

        vector<string>& names = g.second;
        sort(names.begin(), names.end(), [&](const string& x, const string& y){
            return x < y;
        });

        cout << "Dia " << day << " de " << mname << ": ";
        for(size_t i = 0; i < names.size(); i++){
            if(i) cout << ", ";
            cout << names[i];
        }
        cout << "\n";
    }

    return 0;
}