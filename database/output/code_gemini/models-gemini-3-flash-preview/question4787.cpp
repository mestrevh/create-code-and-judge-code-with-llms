/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Pokemon {
    string name;
    string type;
    int power;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n, t;
    int p;
    vector<Pokemon> pks;
    while (cin >> n >> t >> p) {
        pks.push_back({n, t, p});
    }

    if (pks.empty()) return 0;

    map<string, int> counts;
    long long total_power = 0;
    int max_len = 0;
    for (const auto& pk : pks) {
        counts[pk.type]++;
        total_power += pk.power;
        if ((int)pk.name.length() > max_len) {
            max_len = (int)pk.name.length();
        }
    }

    int max_freq = 0;
    for (auto const& pair : counts) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
        }
    }

    string res_type = "";
    vector<string> priority = {"fogo", "agua", "planta", "eletrico", "dragao"};
    for (const string& pt : priority) {
        if (counts.count(pt) && counts[pt] == max_freq) {
            res_type = pt;
            break;
        }
    }

    string res_name = "";
    int offset = 0;
    for (const auto& pk : pks) {
        double fraction = (total_power == 0) ? 0.0 : (double)pk.power / (double)total_power;
        int c = (int)(fraction * (double)max_len);
        if (c < 1) c = 1;
        
        for (int k = 0; k < c; ++k) {
            int idx = offset + k;
            if (idx < (int)pk.name.length()) {
                res_name += pk.name[idx];
            } else {
                res_name += pk.name.back();
            }
        }
        offset += c;
    }

    cout << "Nome: " << res_name << "\n";
    cout << "Tipo: " << res_type << "\n";
    cout << "Poder: " << total_power << "\n";

    return 0;
}