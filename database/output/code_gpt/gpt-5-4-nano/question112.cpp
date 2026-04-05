/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    const int intervals = 10;
    vector<int> freq(intervals, 0);
    int ignored = 0;

    auto getIndex = [&](double x) -> int {
        if (x == 10.0) return 9;
        if (x < 0.0 || x > 10.0) return -1;
        int idx = int(floor(x));
        if (idx < 0) idx = 0;
        if (idx >= 10) idx = 9;
        if (x == 0.0) idx = 0;
        double low = idx * 1.0;
        double high = (idx + 1) * 1.0;
        if (idx == 0) {
            if (x < low || x > high) return -1;
        } else {
            if (!(x > low && x <= high)) return -1;
        }
        return idx;
    };

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        int idx = getIndex(x);
        if (idx < 0) ignored++;
        else freq[idx]++;
    }

    int maxFreq = 0;
    for (int f : freq) maxFreq = max(maxFreq, f);

    int H = min(20, maxFreq);

    if (H == 0) {
        int levels = 20;
        vector<string> canvas(levels + 1, string(30, ' '));
        canvas[0].assign(0, '\0');
        cout << "^" << "\n";
    }

    int width = 10;
    int maxBarHeight = 20;
    vector<int> barH(intervals, 0);
    if (maxFreq == 0) {
        for (int i = 0; i < intervals; i++) barH[i] = 0;
    } else {
        for (int i = 0; i < intervals; i++) {
            barH[i] = (freq[i] * maxBarHeight) / maxFreq;
        }
    }

    vector<string> out;
    out.reserve(maxBarHeight + 1 + 2);

    out.push_back("^");

    int yTop = maxBarHeight;
    int yTicksVals[5] = {maxBarHeight, (3 * maxBarHeight) / 4, maxBarHeight / 2, maxBarHeight / 4, 0};
    int yTickPos[5];
    for (int i = 0; i < 5; i++) yTickPos[i] = yTop - yTicksVals[i];

    auto freqAtY = [&](int yFromTop) -> int {
        int level = yTop - yFromTop;
        return (level * maxFreq) / maxBarHeight;
    };

    int numTicks = 5;
    vector<pair<int,int>> ticks;
    for (int k = 0; k < 5; k++) {
        int y = yTop - yTicksVals[k];
        ticks.push_back({y, yTicksVals[k]});
    }
    sort(ticks.begin(), ticks.end());

    int axisX1 = 0;
    int axisX2 = 0;

    auto labelForTick = [&](int h) -> string {
        int real = (h * maxFreq) / maxBarHeight;
        if (h == 0) return "   0";
        int digits = to_string(real).size();
        string s = to_string(real);
        if (digits == 1) return "   " + s;
        if (digits == 2) return "  " + s;
        if (digits == 3) return " " + s;
        return s;
    };

    int chartWidth = 10 + 1 + 1 + 4;
    chartWidth = 22;

    int leftLabelWidth = 4;

    for (int y = 0; y < maxBarHeight; y++) {
        int currentHeight = maxBarHeight - y;
        string line(leftLabelWidth, ' ');

        bool isTick = false;
        int tickH = 0;
        for (int k = 0; k < numTicks; k++) {
            if (ticks[k].first == y) {
                isTick = true;
                tickH = ticks[k].second;
                break;
            }
        }
        if (isTick) line = labelForTick(tickH);

        line += " +";
        line += " ";

        for (int i = 0; i < intervals; i++) {
            line += '|';
            line += (barH[i] >= currentHeight ? '*' : ' ');
            line += '|';
            if (i != intervals - 1) line += "_";
        }
        out.push_back(line);

        if (y == maxBarHeight - 1) break;
    }

    string axis = string(leftLabelWidth + 2 + 1, '-') ;
    axis.clear();
    axis += string(leftLabelWidth, ' ');
    axis += '+';
    axis += string(8, '-');
    axis += '+';
    axis += string(8, '-');
    axis += '+';
    axis.clear();

    axis = string(leftLabelWidth, ' ');
    axis += " 0";
    axis.clear();

    int barBlockWidth = intervals * 3 + (intervals - 1);
    int totalWidth = leftLabelWidth + 2 + 1 + barBlockWidth;

    string base = string(leftLabelWidth, ' ');
    base += "0";
    base = string(leftLabelWidth - 1, ' ') + "0" + "--------" + "+";
    base.clear();
    base = string(leftLabelWidth, ' ');
    base += "0--------+---------+";
    base += ">";
    out.clear();
    out.push_back("^");

    for (int y = 0; y < maxBarHeight; y++) {
        int currentHeight = maxBarHeight - y;
        string line(leftLabelWidth, ' ');

        int level = currentHeight;
        int real = (maxBarHeight == 0 ? 0 : (level * maxFreq) / maxBarHeight);

        bool tick = (currentHeight == maxBarHeight || currentHeight == (3 * maxBarHeight) / 4 || currentHeight == maxBarHeight / 2 || currentHeight == maxBarHeight / 4 || currentHeight == 0);
        if (tick) {
            string s = to_string(real);
            if ((int)s.size() < 4) line = string(4 - (int)s.size(), ' ') + s;
        }

        if (tick) {
            line = string(4, ' ');
            string s = to_string(real);
            if ((int)s.size() <= 4) line.replace(4 - (int)s.size(), (int)s.size(), s);
        }

        line += " +";
        line += " ";

        for (int i = 0; i < intervals; i++) {
            line += '|';
            line += (barH[i] >= currentHeight ? '*' : ' ');
            line += '|';
            if (i != intervals - 1) line += '_';
        }
        out.push_back(line);
    }

    string xAxis = string(leftLabelWidth, ' ');
    xAxis += "0";
    xAxis += "--------+---------+>";
    out.push_back(xAxis);

    string labels = string(leftLabelWidth + 1, ' ');
    labels += "0.0      5.0      10.0";
    out.push_back(labels);

    out.push_back("Valores ignorados: " + to_string(ignored));

    for (auto &s : out) cout << s << "\n";
    return 0;
}