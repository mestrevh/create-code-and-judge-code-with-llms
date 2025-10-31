/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int C;
    cin >> C;
    cin.ignore();
    for (int caso = 0; caso < C; caso++) {
        string s;
        vector<vector<int>> contatos;
        while (getline(cin, s) && !s.empty()) {
            stringstream ss(s);
            int K;
            ss >> K;
            vector<int> temp(K);
            for (int i = 0; i < K; i++) {
                ss >> temp[i];
            }
            contatos.push_back(temp);
        }
        int N = contatos.size();
        
        int S;
        cin >> S;
        
        vector<int> infected(N, 0);
        vector<int> t(N, 0);
        
        queue<int> q;
        q.push(S);
        infected[S] = 1;
        int total_infected = 1;
        
        for (int second = 0; !q.empty(); second++) {
            int size = q.size();
            t[second] = total_infected;
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (int neighbor : contatos[curr]) {
                    if (!infected[neighbor]) {
                        infected[neighbor] = 1;
                        total_infected++;
                        q.push(neighbor);
                    }
                }
            }
        }
        while (t.size() < N) t.push_back(total_infected);
        
        cout << "caso " << caso << ":";
        for (int i = 0; i < N; i++) {
            cout << " " << t[i];
        }
        cout << "\n\n";
    }
    return 0;
}
