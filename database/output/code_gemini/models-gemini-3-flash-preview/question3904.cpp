/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Present {
    int id;
    long long volume;
};

bool comparePresents(const Present& a, const Present& b) {
    if (a.volume != b.volume) {
        return a.volume > b.volume;
    }
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        if (!(cin >> N >> K)) break;
        vector<Present> presents(N);
        for (int i = 0; i < N; ++i) {
            int id;
            long long h, w, l;
            cin >> id >> h >> w >> l;
            presents[i].id = id;
            presents[i].volume = h * w * l;
        }

        sort(presents.begin(), presents.end(), comparePresents);

        vector<int> result_ids;
        result_ids.reserve(K);
        for (int i = 0; i < K; ++i) {
            result_ids.push_back(presents[i].id);
        }
        sort(result_ids.begin(), result_ids.end());

        for (int i = 0; i < K; ++i) {
            if (i > 0) cout << " ";
            cout << result_ids[i];
        }
        cout << "\n";
    }

    return 0;
}