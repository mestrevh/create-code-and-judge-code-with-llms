/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Task {
    int code, points;
    int start, end; // in minutes
};

int timeToMinutes(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

bool taskComparator(const Task &a, const Task &b) {
    return a.end < b.end;
}

int main() {
    string days[] = {"Seg", "Ter", "Qua", "Qui", "Sex"};
    map<string, int> dayIndex = {{"Seg", 0}, {"Ter", 1}, {"Qua", 2}, {"Qui", 3}, {"Sex", 4}};
    
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<Task> tasks[5]; // one vector for each day
        for (int i = 0; i < N; i++) {
            int code, points;
            string day, startTime, endTime;
            cin >> code >> points >> day >> startTime >> endTime;

            int start = timeToMinutes(startTime);
            int end = timeToMinutes(endTime);
            tasks[dayIndex[day]].push_back({code, points, start, end});
        }

        for (int d = 0; d < 5; d++) {
            sort(tasks[d].begin(), tasks[d].end(), taskComparator);
        }

        for (int d = 0; d < 5; d++) {
            vector<int> dp(tasks[d].size() + 1, 0);
            for (size_t i = 0; i < tasks[d].size(); i++) {
                dp[i + 1] = max(dp[i], tasks[d][i].points + (i > 0 ? dp[prev(tasks[d].begin() + i, tasks[d].end(),
                    tasks[d][i].start)] : 0));
            }
        }

        for (int d = 0; d < 5; d++) {
            int totalPoints = 0;
            for (const auto &task : tasks[d]) {
                totalPoints += task.points;
            }
        }

        cout << "Total de pontos: " << totalPoints << endl;
        for (int d = 0; d < 5; d++) {
            cout << days[d] << ": " << totalPoints[d] << endl;
        }
    }
    return 0;
}
