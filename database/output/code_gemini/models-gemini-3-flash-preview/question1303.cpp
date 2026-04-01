/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Excavator {
    int id;
    int relics[11];
};

bool compareExcavators(const Excavator& a, const Excavator& b) {
    for (int i = 10; i >= 1; --i) {
        if (a.relics[i] > b.relics[i]) return true;
        if (a.relics[i] < b.relics[i]) return false;
    }
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Excavator> list(N);
    for (int i = 0; i < N; ++i) {
        list[i].id = i + 1;
        int whistle;
        if (!(cin >> whistle)) break;
        for (int j = 1; j <= 10; ++j) {
            int r_count;
            cin >> r_count;
            if (j <= whistle) {
                list[i].relics[j] = r_count;
            } else {
                list[i].relics[j] = 0;
            }
        }
    }

    sort(list.begin(), list.end(), compareExcavators);

    for (int i = 0; i < N; ++i) {
        cout << list[i].id << "\n";
    }

    return 0;
}

