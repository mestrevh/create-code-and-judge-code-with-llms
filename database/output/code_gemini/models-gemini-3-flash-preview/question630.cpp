/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        map<string, int> nameToId;
        vector<string> idToName;
        vector<int> adj[210];
        int in_degree[210];
        bool taken[210];
        for (int i = 0; i < 210; ++i) {
            in_degree[i] = 0;
            taken[i] = false;
            adj[i].clear();
        }
        int nextId = 0;

        auto getId = [&](const string& s) {
            auto it = nameToId.find(s);
            if (it == nameToId.end()) {
                nameToId[s] = nextId;
                idToName.push_back(s);
                return nextId++;
            }
            return it->second;
        };

        for (int i = 0; i < N; ++i) {
            string advName;
            int K;
            cin >> advName >> K;
            int u = getId(advName);
            for (int j = 0; j < K; ++j) {
                string preName;
                cin >> preName;
                int v = getId(preName);
                adj[v].push_back(u);
                in_degree[u]++;
            }
        }

        int totalCourses = nextId;
        int totalTaken = 0;
        vector<vector<string>> results;

        while (totalTaken < totalCourses) {
            vector<int> candidates;
            for (int i = 0; i < totalCourses; ++i) {
                if (!taken[i] && in_degree[i] == 0) {
                    candidates.push_back(i);
                }
            }
            
            sort(candidates.begin(), candidates.end());
            
            vector<string> currentSemester;
            int countToTake = min((int)candidates.size(), M);
            
            vector<int> chosen;
            for (int i = 0; i < countToTake; ++i) {
                int u = candidates[i];
                taken[u] = true;
                currentSemester.push_back(idToName[u]);
                totalTaken++;
                chosen.push_back(u);
            }
            
            for (int u : chosen) {
                for (int v : adj[u]) {
                    in_degree[v]--;
                }
            }

            sort(currentSemester.begin(), currentSemester.end());
            results.push_back(currentSemester);
        }

        cout << "Formatura em " << results.size() << " semestres" << "\n";
        for (int i = 0; i < (int)results.size(); ++i) {
            cout << "Semestre " << i + 1 << " :";
            for (const string& s : results[i]) {
                cout << " " << s;
            }
            cout << "\n";
        }
    }

    return 0;
}