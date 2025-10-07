/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> cited(N + 1);
        set<int> suspects;
        vector<set<int>> alibis(N + 1);

        for (int i = 1; i <= N; ++i) {
            cin >> cited[i];
            if (cited[i] != 0) {
                alibis[cited[i]].insert(i);
            }
        }

        int noAlibi = 0;
        int suspectCount = 0;

        for (int i = 1; i <= N; ++i) {
            if (alibis[i].empty()) {
                noAlibi++;
            } else if (alibis[i].count(i) == 1) {
                suspects.insert(i);
            } else {
                bool isSuspect = true;
                for (int a : alibis[i]) {
                    if (a != i && !suspects.count(a)) {
                        isSuspect = false;
                        break;
                    }
                }
                if (isSuspect) {
                    suspects.insert(i);
                }
            }
        }

        suspectCount = suspects.size();
        cout << "Caso #" << t << ": " << noAlibi << " " << suspectCount << endl;
    }
    return 0;
}
