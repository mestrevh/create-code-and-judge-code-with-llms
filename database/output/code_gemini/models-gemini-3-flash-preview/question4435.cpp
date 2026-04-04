/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Toy {
    string name;
    int id;
    int count;
};

struct Ride {
    long long fun;
    int toy_id;
};

bool rideCompare(const Ride& a, const Ride& b) {
    if (a.fun != b.fun) return a.fun > b.fun;
    return a.toy_id < b.toy_id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Toy> toys;
    vector<Ride> pool;
    string line;
    int current_id = 0;

    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line.empty()) continue;

        string name = line;
        long long d, a;
        if (!(cin >> d >> a)) break;
        
        string dummy;
        getline(cin, dummy);

        toys.push_back({name, current_id, 0});
        pool.push_back({d, current_id});
        pool.push_back({d - a, current_id});
        pool.push_back({d - 4 * a, current_id});
        current_id++;
    }

    if (pool.empty()) return 0;

    sort(pool.begin(), pool.end(), rideCompare);

    long long totalFun = 0;
    int chosen = 0;
    for (int i = 0; i < (int)pool.size() && chosen < 3; ++i) {
        totalFun += pool[i].fun;
        toys[pool[i].toy_id].count++;
        chosen++;
    }

    vector<Toy*> result;
    for (int i = 0; i < (int)toys.size(); ++i) {
        if (toys[i].count > 0) {
            result.push_back(&toys[i]);
        }
    }

    int uCount = (int)result.size();
    sort(result.begin(), result.end(), [uCount](Toy* a, Toy* b) {
        if (uCount == 3) {
            return a->id < b->id;
        } else {
            if (a->count != b->count) return a->count > b->count;
            return a->id < b->id;
        }
    });

    cout << "a maior diversao foi: " << totalFun << "\n";
    cout << "indo nos brinquedos: ";
    for (int i = 0; i < (int)result.size(); ++i) {
        cout << result[i]->name << " " << result[i]->count << (result[i]->count == 1 ? " vez" : " vezes");
        if (i == (int)result.size() - 1) {
            cout << ".\n";
        } else {
            cout << ", ";
        }
    }

    return 0;
}