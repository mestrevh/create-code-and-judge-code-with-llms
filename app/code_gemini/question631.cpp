/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

struct Task {
    int points;
    int start_time;
    int end_time;

    bool operator<(const Task& other) const {
        if (end_time != other.end_time) {
            return end_time < other.end_time;
        }
        return start_time < other.start_time;
    }
};

int time_to_minutes(const std::string& time_str) {
    int h, m;
    char colon;
    std::stringstream ss(time_str);
    ss >> h >> colon >> m;
    return h * 60 + m;
}

int find_prev_task(const std::vector<Task>& tasks, int current_index) {
    int target_start_time = tasks[current_index].start_time;
    int low = 0, high = current_index - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (tasks[mid].end_time <= target_start_time) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

long long solve_day(std::vector<Task>& tasks_for_day) {
    if (tasks_for_day.empty()) {
        return 0;
    }

    std::sort(tasks_for_day.begin(), tasks_for_day.end());

    int n = tasks_for_day.size();
    std::vector<long long> dp(n);

    dp[0] = tasks_for_day[0].points;

    for (int i = 1; i < n; ++i) {
        long long current_points = tasks_for_day[i].points;
        int prev_idx = find_prev_task(tasks_for_day, i);

        long long points_with_current = current_points;
        if (prev_idx != -1) {
            points_with_current += dp[prev_idx];
        }

        long long points_without_current = dp[i - 1];

        dp[i] = std::max(points_with_current, points_without_current);
    }

    return dp[n - 1];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::map<std::string, int> day_to_idx = {
        {"Seg", 0}, {"Ter", 1}, {"Qua", 2}, {"Qui", 3}, {"Sex", 4}
    };
    std::vector<std::string> idx_to_day = {"Seg", "Ter", "Qua", "Qui", "Sex"};

    while (std::cin >> N && N != 0) {
        std::vector<Task> tasks_by_day[5];

        for (int i = 0; i < N; ++i) {
            int code, points;
            std::string day_str, start_str, end_str;
            std::cin >> code >> points >> day_str >> start_str >> end_str;

            Task t;
            t.points = points;
            t.start_time = time_to_minutes(start_str);
            t.end_time = time_to_minutes(end_str);

            tasks_by_day[day_to_idx[day_str]].push_back(t);
        }

        std::vector<long long> daily_max_points(5);
        long long total_points = 0;

        for (int i = 0; i < 5; ++i) {
            daily_max_points[i] = solve_day(tasks_by_day[i]);
            total_points += daily_max_points[i];
        }

        std::cout << "Total de pontos: " << total_points << "\n";
        for (int i = 0; i < 5; ++i) {
            std::cout << idx_to_day[i] << ": " << daily_max_points[i] << "\n";
        }
    }

    return 0;
}
