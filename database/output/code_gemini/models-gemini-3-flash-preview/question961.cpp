/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int blink_counts[1140][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<unsigned short>> days;
    vector<unsigned short> day_maxes;

    int t;
    while (cin >> t && t != 0) {
        if (t == 1) {
            int Q;
            cin >> Q;
            vector<unsigned short> current_day;
            current_day.reserve(Q);
            unsigned short current_max = 0;
            for (int j = 0; j < Q; ++j) {
                unsigned short p;
                cin >> p;
                current_day.push_back(p);
                if (p > current_max) current_max = p;
                if (j < 1140) {
                    blink_counts[j][p]++;
                }
            }
            days.push_back(current_day);
            day_maxes.push_back(current_max);
            cout << days.size() << "\n";
        } else if (t == 2) {
            int d;
            cin >> d;
            if (d >= 0 && d < (int)days.size()) {
                int Q = (int)days[d].size();
                for (int j = 0; j < Q; ++j) {
                    if (j < 1140) {
                        blink_counts[j][days[d][j]]--;
                    }
                }
                days.erase(days.begin() + d);
                day_maxes.erase(day_maxes.begin() + d);
                cout << Q << "\n";
            }
        } else if (t == 3) {
            int i;
            cin >> i;
            if (i >= 0 && i < (int)day_maxes.size()) {
                cout << day_maxes[i] << "\n";
            }
        } else if (t == 4) {
            int j;
            cin >> j;
            int res = 0;
            if (j >= 0 && j < 1140) {
                for (int v = 1000; v > 0; --v) {
                    if (blink_counts[j][v] > 0) {
                        res = v;
                        break;
                    }
                }
            }
            cout << res << "\n";
        }
    }

    return 0;
}