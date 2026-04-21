/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    long long cost;
    long long perf;
};

vector<Item> filter_pareto(vector<Item>& v) {
    if (v.empty()) return {};
    sort(v.begin(), v.end(), [](const Item& a, const Item& b) {
        if (a.cost != b.cost) return a.cost < b.cost;
        return a.perf > b.perf;
    });
    vector<Item> filtered;
    for (const auto& item : v) {
        if (filtered.empty() || item.perf > filtered.back().perf) {
            filtered.push_back(item);
        }
    }
    return filtered;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long money;
    int n;
    if (!(cin >> money >> n)) return 0;

    vector<Item> motors, rodas, latarias;
    for (int i = 0; i < n; ++i) {
        string type;
        long long c, p;
        cin >> type >> c >> p;
        if (type == "Motor") motors.push_back({c, p});
        else if (type == "Roda") rodas.push_back({c, p});
        else if (type == "Lataria") latarias.push_back({c, p});
    }

    if (motors.empty() || rodas.empty() || latarias.empty()) {
        cout << "Nao foi possivel construir uma caranga..." << endl;
        return 0;
    }

    vector<Item> f_motors = filter_pareto(motors);
    vector<Item> f_rodas = filter_pareto(rodas);
    vector<Item> f_latarias = filter_pareto(latarias);

    vector<Item> mr_combined;
    for (const auto& m : f_motors) {
        for (const auto& r : f_rodas) {
            if (m.cost + r.cost <= money) {
                mr_combined.push_back({m.cost + r.cost, m.perf + r.perf});
            }
        }
    }
    
    if (mr_combined.empty()) {
        cout << "Nao foi possivel construir uma caranga..." << endl;
        return 0;
    }

    vector<Item> f_mr = filter_pareto(mr_combined);

    long long max_p = -1;
    long long min_c = -1;

    for (const auto& mr : f_mr) {
        long long target = money - mr.cost;
        auto it = upper_bound(f_latarias.begin(), f_latarias.end(), target, [](long long val, const Item& a) {
            return val < a.cost;
        });
        
        if (it != f_latarias.begin()) {
            const auto& l = *(--it);
            long long total_p = mr.perf + l.perf;
            long long total_c = mr.cost + l.cost;
            
            if (total_p > max_p) {
                max_p = total_p;
                min_c = total_c;
            } else if (total_p == max_p) {
                if (min_c == -1 || total_c < min_c) {
                    min_c = total_c;
                }
            }
        }
    }

    if (max_p == -1) {
        cout << "Nao foi possivel construir uma caranga..." << endl;
    } else {
        cout << "Minha nave tem uma performance de " << max_p << " pontos" << endl;
        if (money - min_c > 0) {
            cout << "E ainda me sobraram " << money - min_c << " mangos!" << endl;
        }
    }

    return 0;
}