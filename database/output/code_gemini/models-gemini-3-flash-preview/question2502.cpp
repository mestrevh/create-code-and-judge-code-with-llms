/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.start != b.start) return a.start < b.start;
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Interval> scheduled(n);
    for (int i = 0; i < n; ++i) {
        cin >> scheduled[i].start >> scheduled[i].end;
    }

    vector<int> unscheduled(m);
    for (int i = 0; i < m; ++i) {
        cin >> unscheduled[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(scheduled.begin(), scheduled.end(), compareIntervals);

    vector<int> gaps;
    if (scheduled[0].start > 0) {
        gaps.push_back(scheduled[0].start);
    }

    for (int i = 0; i < n - 1; ++i) {
        int gap_size = scheduled[i + 1].start - scheduled[i].end;
        if (gap_size > 0) {
            gaps.push_back(gap_size);
        }
    }

    sort(unscheduled.begin(), unscheduled.end());

    int count = 0;
    for (int i = 0; i < m; ++i) {
        int duration = unscheduled[i];
        for (int j = 0; j < (int)gaps.size(); ++j) {
            if (gaps[j] >= duration) {
                gaps[j] -= duration;
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}