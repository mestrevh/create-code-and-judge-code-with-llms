/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    if (!(cin >> C >> N)) return 0;

    priority_queue<int, vector<int>, greater<int>> tellers;
    for (int i = 0; i < C; ++i) {
        tellers.push(0);
    }

    int delayed_customers = 0;
    for (int i = 0; i < N; ++i) {
        int T, D;
        cin >> T >> D;

        int earliest_free_time = tellers.top();
        tellers.pop();

        int start_time = max(T, earliest_free_time);
        
        if (start_time - T > 20) {
            delayed_customers++;
        }

        tellers.push(start_time + D);
    }

    cout << delayed_customers << endl;

    return 0;
}

_
