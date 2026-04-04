/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

struct Entry {
    string cantor;
    string genero;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int I;
    if (!(cin >> I)) return 0;
    string line;
    getline(cin, line); 

    vector<Entry> cds_list;
    for (int i = 0; i < I; ++i) {
        if (!getline(cin, line)) break;
        size_t pos = line.find('-');
        if (pos != string::npos) {
            cds_list.push_back({line.substr(0, pos), line.substr(pos + 1)});
        } else {
            cds_list.push_back({line, ""});
        }
    }

    map<pair<string, string>, deque<int>> cover_map;
    vector<Entry> covers_list;
    for (int i = 0; i < I; ++i) {
        if (!getline(cin, line)) break;
        size_t pos = line.find('-');
        if (pos != string::npos) {
            Entry e = {line.substr(0, pos), line.substr(pos + 1)};
            covers_list.push_back(e);
            cover_map[{e.cantor, e.genero}].push_back(i);
        } else {
            Entry e = {line, ""};
            covers_list.push_back(e);
            cover_map[{e.cantor, e.genero}].push_back(i);
        }
    }

    vector<Entry> matches;
    vector<bool> cd_matched(cds_list.size(), false);
    vector<bool> cover_matched(covers_list.size(), false);

    for (int i = 0; i < (int)cds_list.size(); ++i) {
        pair<string, string> p = {cds_list[i].cantor, cds_list[i].genero};
        if (cover_map.count(p) && !cover_map[p].empty()) {
            matches.push_back(cds_list[i]);
            int cover_idx = cover_map[p].front();
            cover_map[p].pop_front();
            cd_matched[i] = true;
            cover_matched[cover_idx] = true;
        }
    }

    sort(matches.begin(), matches.end(), [](const Entry& a, const Entry& b) {
        if (a.cantor != b.cantor) return a.cantor < b.cantor;
        return a.genero < b.genero;
    });

    for (const auto& m : matches) {
        cout << m.cantor << " " << m.genero << "\n";
    }

    vector<string> unmatched_cds;
    for (int i = 0; i < (int)cds_list.size(); ++i) {
        if (!cd_matched[i]) {
            unmatched_cds.push_back(cds_list[i].cantor);
        }
    }

    vector<string> unmatched_covers;
    for (int i = 0; i < (int)covers_list.size(); ++i) {
        if (!cover_matched[i]) {
            unmatched_covers.push_back(covers_list[i].cantor);
        }
    }

    if (!unmatched_cds.empty() || !unmatched_covers.empty()) {
        cout << "Chandler, você vai ter que comprar a capa para os CDs: ";
        for (size_t i = 0; i < unmatched_cds.size(); ++i) {
            cout << unmatched_cds[i] << (i == unmatched_cds.size() - 1 ? "" : ", ");
        }
        cout << ". E os CDs para as capas: ";
        for (size_t i = 0; i < unmatched_covers.size(); ++i) {
            cout << unmatched_covers[i] << (i == unmatched_covers.size() - 1 ? "" : ", ");
        }
        cout << "." << endl;
    }

    return 0;
}