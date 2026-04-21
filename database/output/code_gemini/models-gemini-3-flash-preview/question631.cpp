/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    int points;
    int start;
    int end;
};

int parseTime(string s) {
    int h, m;
    size_t colon = s.find(':');
    h = stoi(s.substr(0, colon));
    m = stoi(s.substr(colon + 1));
    return h * 60 + m;
}

int getDayIdx(string d) {
    if (d == "Seg") return 0;
    if (d == "Ter") return 1;
    if (d == "Qua") return 2;
    if (d == "Qui") return 3;
    if (d == "Sex") return 4;
    return -1;
}

int solveDay(vector<Task>& tasks) {
    if (tasks.empty()) return 0;

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        if (a.end != b.end) return a.end < b.end;
        return a.start < b.start;
    });

    int n = tasks.size();
    vector<int> dp(n + 1, 0);
    vector<int> end_times;
    for (const auto& t : tasks) end_times.push_back(t.end);

    for (int i = 0; i < n; ++i) {
        int p = -1;
        auto it = upper_bound(end_times.begin(), end_times.begin() + i, tasks[i].start);
        if (it != end_times.begin()) {
            p = distance(end_times.begin(), prev(it));
        }

        int includePoints = tasks[i].points + (p != -1 ? dp[p + 1] : 0);
        dp[i + 1] = max(dp[i], includePoints);
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        vector<Task> days[5];
        for (int i = 0; i < N; ++i) {
            int code, pts;
            string dayStr, startStr, endStr;
            cin >> code >> pts >> dayStr >> startStr >> endStr;
            int dIdx = getDayIdx(dayStr);
            if (dIdx != -1) {
                days[dIdx].push_back({pts, parseTime(startStr), parseTime(endStr)});
            }
        }

        int dayMax[5];
        int totalMax = 0;
        for (int i = 0; i < 5; ++i) {
            dayMax[i] = solveDay(days[i]);
            totalMax += dayMax[i];
        }

        cout << "Total de pontos: " << totalMax << "\n";
        cout << "Seg: " << dayMax[0] << "\n";
        cout << "Ter: " << dayMax[1] << "\n";
        cout << "Qua: " << dayMax[2] << "\n";
        cout << "Qui: " << dayMax[3] << "\n";
        cout << "Sex: " << dayMax[4] << "\n";
    }

    return 0;
}