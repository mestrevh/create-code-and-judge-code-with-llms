/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> friends;
map<string, vector<string>> requirements;
map<string, int> inDegree;

void topologicalSort(int testCase) {
    queue<string> q;
    vector<string> result;

    for (const auto& friendName : friends) {
        if (inDegree[friendName] == 0) {
            q.push(friendName);
        }
    }

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        result.push_back(current);

        for (const auto& req : requirements[current]) {
            inDegree[req]--;
            if (inDegree[req] == 0) {
                q.push(req);
            }
        }
    }

    cout << "Teste " << testCase << endl;
    if (result.size() == friends.size()) {
        for (const auto& name : result) {
            cout << name << " ";
        }
        cout << endl;
    } else {
        cout << "impossivel" << endl;
    }
    cout << endl;
}

int main() {
    int n, testCase = 1;

    while (true) {
        cin >> n;
        if (n == 0) break;

        friends.clear();
        requirements.clear();
        inDegree.clear();

        friends.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> friends[i];
            inDegree[friends[i]] = 0;
        }

        for (int i = 0; i < n; ++i) {
            string friendName;
            cin >> friendName;
            int m;
            cin >> m;

            vector<string> reqs(m);
            for (int j = 0; j < m; ++j) {
                cin >> reqs[j];
                requirements[reqs[j]].push_back(friendName);
                inDegree[friendName]++;
            }
        }

        topologicalSort(testCase);
        testCase++;
    }

    return 0;
}
