/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;

    vector<int> told_by(N + 1);
    vector<int> day_of_signup(N + 1, -1);
    for (int i = 1; i <= N; ++i) {
        cin >> told_by[i];
    }

    queue<int> q;
    q.push(0);
    day_of_signup[0] = 0;
    
    while (!q.empty()) {
        int person = q.front();
        q.pop();
        
        for (int i = 1; i <= N; ++i) {
            if (told_by[i] == person && day_of_signup[i] == -1) {
                day_of_signup[i] = day_of_signup[person] + 1;
                if (day_of_signup[i] < Y) {
                    q.push(i);
                }
            }
        }
    }

    int total_subscribers = 0;
    for (int i = 1; i <= N; ++i) {
        if (day_of_signup[i] != -1 && day_of_signup[i] < Y) {
            total_subscribers++;
        }
    }

    cout << (total_subscribers >= X ? "S" : "N") << endl;
    return 0;
}
