/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Post {
    double score;
    int id;
    int index;
    string content;

    bool operator>(const Post& other) const {
        if (score != other.score) {
            return score > other.score;
        }
        return index < other.index;
    }
};

static double proximity_map[10000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int m;
    if (!(cin >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int id;
        double p;
        if (!(cin >> id >> p)) break;
        if (id >= 0 && id <= 10000000) {
            proximity_map[id] = p;
        }
    }

    int x;
    if (!(cin >> x)) return 0;

    vector<Post> updates;
    if (x > 0 && x <= 1000000) {
        updates.reserve(x);
    }

    for (int i = 0; i < x; ++i) {
        int id;
        double t;
        if (!(cin >> id >> t)) break;

        string content;
        getline(cin, content);
        if (!content.empty() && content[0] == ' ') {
            content.erase(0, 1);
        }

        double p_val = (id >= 0 && id <= 10000000) ? proximity_map[id] : 0.0;
        double s = 0.8 * p_val + 0.2 * t;
        updates.push_back({s, id, i, content});
    }

    int target = (n < (int)updates.size()) ? n : (int)updates.size();
    if (target < (int)updates.size()) {
        nth_element(updates.begin(), updates.begin() + target, updates.end(), greater<Post>());
        updates.resize(target);
    }
    
    sort(updates.begin(), updates.end(), greater<Post>());

    for (int i = 0; i < (int)updates.size(); ++i) {
        cout << updates[i].id << " " << updates[i].content << "\n";
    }

    return 0;
}