/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int a, b;
};

bool compareIntervals(const Interval& x, const Interval& y) {
    if (x.b != y.b) return x.b < y.b;
    return x.a < y.a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<Interval> intervals(n);
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].a >> intervals[i].b;
        }

        sort(intervals.begin(), intervals.end(), compareIntervals);

        int photo_count = 0;
        int last_focal_point = -1;

        for (int i = 0; i < n; ++i) {
            if (intervals[i].a > last_focal_point) {
                photo_count++;
                last_focal_point = intervals[i].b;
            }
        }

        cout << photo_count << "\n";
    }

    return 0;
}