/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef __int128 int128;

string to_str(int128 n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s += (char)('0' + (int)(n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

unordered_map<string, int> str_id;
int get_id(const string& s) {
    auto it = str_id.find(s);
    if (it != str_id.end()) return it->second;
    int id = str_id.size();
    return str_id[s] = id;
}

vector<int> g[20005];
int128 f[20005];
bool v[20005];

int128 count_p(int curr, int dest) {
    if (curr == dest) return 1;
    if (v[curr]) return f[curr];
    int128 sum = 0;
    for (int neighbor : g[curr]) {
        sum += count_p(neighbor, dest);
    }
    v[curr] = true;
    f[curr] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;
    if (line.empty()) return 0;
    
    int n_places;
    try {
        n_places = stoi(line);
    } catch (...) {
        return 0;
    }

    for (int i = 0; i < n_places; ++i) {
        if (!getline(cin, line)) break;
        stringstream ss(line);
        string src_s, dst_s;
        if (!(ss >> src_s)) continue;
        int src_id = get_id(src_s);
        while (ss >> dst_s) {
            int dst_id = get_id(dst_s);
            g[src_id].push_back(dst_id);
        }
    }

    string start_node_s, end_node_s;
    if (!(cin >> start_node_s >> end_node_s)) return 0;

    auto it_s = str_id.find(start_node_s);
    auto it_e = str_id.find(end_node_s);

    if (it_s == str_id.end() || it_e == str_id.end()) {
        if (start_node_s == end_node_s) cout << "1" << endl;
        else cout << "0" << endl;
    } else {
        cout << to_str(count_p(it_s->second, it_e->second)) << endl;
    }

    return 0;
}