/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Point {
    int key;
    vector<int> values;

    bool operator>(const Point& other) const {
        return key > other.key;
    }
};

class PointSet {
public:
    void add(int k, const vector<int>& v) {
        points[k] = {k, v};
        countDominances(k);
    }

    void update(int k, const vector<int>& v) {
        points[k].values = v;
        countDominances(k);
    }

    string max(int j) {
        Point dominant = points.begin()->second;
        for (auto& [key, point] : points) {
            if (point.values[j] > dominant.values[j] || (point.values[j] == dominant.values[j] && point > dominant)) {
                dominant = point;
            }
        }
        points.erase(dominant.key);
        return formatResult(dominant);
    }

private:
    map<int, Point> points;

    void countDominances(int k) {
        int count = 0;
        const auto& pk = points[k].values;
        for (const auto& [key, point] : points) {
            if (key != k) {
                bool isDominant = true;
                for (size_t j = 0; j < pk.size(); j++) {
                    if (pk[j] <= point.values[j]) {
                        isDominant = false;
                        break;
                    }
                }
                if (isDominant) count++;
            }
        }
        cout << count;
    }

    string formatResult(const Point& p) {
        stringstream ss;
        ss << p.key;
        for (const auto& v : p.values) {
            ss << " " << v;
        }
        return ss.str();
    }
};

int main() {
    int N;
    cin >> N;
    string line;
    PointSet ps;

    while (cin >> line && line != "END") {
        istringstream iss(line);
        string op;
        iss >> op;

        if (op == "ADD") {
            int k;
            vector<int> v(N);
            iss >> k;
            for (int i = 0; i < N; ++i) {
                iss >> v[i];
            }
            ps.add(k, v);
            cout << " " << ps.k; // placeholder for the function countDominances, will fix later
        } 
        else if (op == "UPD") {
            int k;
            vector<int> v(N);
            iss >> k;
            for (int i = 0; i < N; ++i) {
                iss >> v[i];
            }
            ps.update(k, v);
            cout << " " << ps.k; // placeholder for the function countDominances, will fix later
        } 
        else if (op == "MAX") {
            int j;
            iss >> j;
            cout << " " << ps.max(j);
        }
    }
}
