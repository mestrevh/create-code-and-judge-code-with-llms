/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double initDist = 20.0;

    string line;
    vector<double> times; // para cada caminho: tempo total
    int pathNum = 0;
    bool hasAnyPath = false;

    auto trim = [](string s) {
        size_t i = 0;
        while (i < s.size() && isspace((unsigned char)s[i])) i++;
        size_t j = s.size();
        while (j > i && isspace((unsigned char)s[j-1])) j--;
        return s.substr(i, j-i);
    };

    while (true) {
        streampos posBefore = cin.tellg();
        if (!std::getline(cin, line)) break;
        line = trim(line);
        if (line.empty()) continue;
        if (line == "[") {
            hasAnyPath = true;
            pathNum++;
            double totalTime = 0.0;
            while (true) {
                if (!getline(cin, line)) break;
                line = trim(line);
                if (line.empty()) continue;
                if (line == "]") break;
                if (line == "C" || line == "T" || line == "S" || line == "P") {
                    // As per statement only C or T expected; ignore stray tokens
                } else {
                    // might be P number line or stray; handle tokens
                }

                if (line == "C") {
                    double d = 15.0; 
                    // But description says cipós yield 15m to Tarzan, to be used in distance.
                    // We'll compute by distance changes, so store a "movement" effect later.
                    // We'll parse by reading possibly number after? Actually input: lines can be S or P (S is 'C' or 'T', P is number seconds).
                    // So here 'C' or 'T' just adds instantaneous distance.
                    // We'll handle by reading duration already in time lines (numbers). C/T add distance directly.
                }

                // We need to parse properly: tokens are lines and could be: C or T or number.
                // We'll implement simpler: interpret current line:
                if (line == "C") {
                    // cipó: +15m to Tarzan
                    // We'll update current dist later during simulation with time segments. But easiest:
                    // Maintain Tarzan lead distance evolution over timeline with "events" (boosts).
                    // However speed of monkeys depends on global elapsed time, not on distance.
                    // Since boosts happen at certain times (the line with C/T occurs at a time boundary, without consuming time).
                    // The statement implies each line that's not '[' or ']' and not C/T is seconds consumed by that entry.
                    // So C/T lines consume 0 seconds.
                    // We'll update distance lead immediately at that moment.
                    // To do this, we need simulation inside each path.
                } else if (line == "T") {
                } else {
                    // number line: seconds duration
                }
            }
        } else {
            // ignore
        }
        // can't use posBefore
    }

    // The above parsing attempt is incomplete. Let's re-parse properly with full simulation.

    cin.clear();
    cin.seekg(0);

    struct PathResult {
        int idx;
        double finalDist;
        bool valid;
    };

    vector<PathResult> results;

    pathNum = 0;
    while (true) {
        if (!getline(cin, line)) break;
        line = trim(line);
        if (line.empty()) continue;
        if (line != "[") continue;

        pathNum++;
        double tarzanLead = 0.0; // distance Tarzan increased relative to monkeys? We'll track distance between them.
        double dist = initDist; // distance between Tarzan and monkeys (positive means monkeys behind)
        double t = 0.0;
        bool valid = false;
        bool killed = false;

        auto monkeysSpeedAt = [&](double time) {
            return (time > 20.0 ? 3.0 : 1.0);
        };

        while (getline(cin, line)) {
            line = trim(line);
            if (line.empty()) continue;
            if (line == "]") break;

            if (line == "C") {
                dist -= 15.0; // Tarzan gains 15m, reducing distance between them by 15m
            } else if (line == "T") {
                dist -= 30.0;
            } else {
                // should be seconds
                double sec = 0.0;
                try {
                    sec = stod(line);
                } catch (...) {
                    continue;
                }
                // simulate over duration sec with possible speed change at time 20
                double remaining = sec;
                while (remaining > 1e-12) {
                    double currentSpeed = monkeysSpeedAt(t);
                    double boundary = (currentSpeed == 0.0 ? t + remaining : 20.0);
                    if (t <= 20.0 && t + remaining > 20.0) {
                        double dt1 = 20.0 - t;
                        if (dt1 > 0) {
                            dist += currentSpeed * dt1;
                            t += dt1;
                            remaining -= dt1;
                        }
                        currentSpeed = monkeysSpeedAt(t);
                        continue;
                    } else {
                        dist += currentSpeed * remaining;
                        t += remaining;
                        remaining = 0.0;
                    }
                    if (dist <= 0) {
                        killed = true;
                        break;
                    }
                }
                if (killed) break;
            }

            if (dist <= 0) {
                killed = true;
                break;
            }
        }

        valid = !killed;
        if (valid) {
            results.push_back({pathNum, dist, true});
        } else {
            // still can compute but not valid
            results.push_back({pathNum, dist, false});
        }
    }

    bool anyEscape = false;
    double bestDist = -1e100;
    int bestIdx = -1;

    for (auto &r : results) {
        if (r.valid) {
            anyEscape = true;
            if (r.finalDist > bestDist) {
                bestDist = r.finalDist;
                bestIdx = r.idx;
            }
        }
    }

    if (!anyEscape) {
        cout << "UoooooOOooOOooooo UooooOOooOOooo";
    } else {
        cout << "Tarzan fugir caminho " << bestIdx;
    }

    return 0;
}