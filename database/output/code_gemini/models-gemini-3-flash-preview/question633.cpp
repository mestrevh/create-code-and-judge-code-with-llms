/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

struct File {
    ll start;
    ll size;
    string name;
};

ll parseSize(int d, string unit) {
    ll size = d;
    if (unit == "Mb") size *= 1024;
    else if (unit == "Gb") size *= 1024LL * 1024LL;
    return size;
}

ll parseSizeStr(string s) {
    size_t i = 0;
    while (i < s.size() && isdigit(s[i])) i++;
    int d = stoi(s.substr(0, i));
    string unit = s.substr(i);
    return parseSize(d, unit);
}

void optimize(vector<File>& files) {
    ll current_pos = 0;
    for (auto& f : files) {
        f.start = current_pos;
        current_pos += f.size;
    }
}

bool try_insert(vector<File>& files, string name, ll size, ll disk_size) {
    ll best_start = -1;
    ll min_gap_size = -1;

    auto check_gap = [&](ll g_start, ll g_size) {
        if (g_size >= size) {
            if (min_gap_size == -1 || g_size < min_gap_size) {
                min_gap_size = g_size;
                best_start = g_start;
            }
        }
    };

    if (files.empty()) {
        check_gap(0, disk_size);
    } else {
        check_gap(0, files[0].start);
        for (size_t i = 0; i < files.size() - 1; ++i) {
            check_gap(files[i].start + files[i].size, files[i + 1].start - (files[i].start + files[i].size));
        }
        check_gap(files.back().start + files.back().size, disk_size - (files.back().start + files.back().size));
    }

    if (best_start != -1) {
        File new_file = {best_start, size, name};
        auto it = lower_bound(files.begin(), files.end(), new_file, [](const File& a, const File& b) {
            return a.start < b.start;
        });
        files.insert(it, new_file);
        return true;
    }
    return false;
}

void solve() {
    int N;
    while (cin >> N && N != 0) {
        int D_val;
        string D_unit;
        string disk_size_raw;
        cin >> disk_size_raw;
        
        size_t unit_idx = 0;
        while(unit_idx < disk_size_raw.size() && isdigit(disk_size_raw[unit_idx])) unit_idx++;
        D_val = stoi(disk_size_raw.substr(0, unit_idx));
        D_unit = disk_size_raw.substr(unit_idx);
        
        ll disk_size = parseSize(D_val, D_unit);
        vector<File> files;
        map<string, ll> name_to_size;
        bool error = false;

        for (int i = 0; i < N; ++i) {
            string cmd;
            cin >> cmd;
            if (error) {
                if (cmd == "insere") { string n, s; cin >> n >> s; }
                else if (cmd == "remove") { string n; cin >> n; }
                continue;
            }

            if (cmd == "insere") {
                string name, size_str;
                cin >> name >> size_str;
                ll size = parseSizeStr(size_str);
                if (!try_insert(files, name, size, disk_size)) {
                    optimize(files);
                    if (!try_insert(files, name, size, disk_size)) {
                        cout << "ERRO: disco cheio" << endl;
                        error = true;
                    }
                }
            } else if (cmd == "remove") {
                string name;
                cin >> name;
                for (auto it = files.begin(); it != files.end(); ++it) {
                    if (it->name == name) {
                        files.erase(it);
                        break;
                    }
                }
            } else if (cmd == "otimiza") {
                optimize(files);
            }
        }

        if (!error) {
            ll block_size = disk_size / 8;
            string output = "";
            for (int b = 0; b < 8; ++b) {
                ll b_start = b * block_size;
                ll b_end = b_start + block_size;
                ll occupied = 0;
                for (const auto& f : files) {
                    ll f_start = f.start;
                    ll f_end = f.start + f.size;
                    ll overlap = max(0LL, min(b_end, f_end) - max(b_start, f_start));
                    occupied += overlap;
                }
                ll free_kb = block_size - occupied;
                double P = (free_kb * 100.0) / block_size;
                char c;
                if (P > 75.0) c = ' ';
                else if (P > 25.0) c = '-';
                else c = '#';
                output += "[";
                output += c;
                output += "]";
            }
            cout << output << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}