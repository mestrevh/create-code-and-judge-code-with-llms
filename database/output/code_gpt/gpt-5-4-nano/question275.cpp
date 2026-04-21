/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long countMinuteHandsPassHour(long long h1, long long m1, long long h2, long long m2) {
    const int total = 12 * 60;
    auto toMin = [&](long long h, long long m) {
        if (h == 12) h = 0;
        return h * 60 + m;
    };
    int a = (int)toMin(h1, m1);
    int b = (int)toMin(h2, m2);

    auto timeToPos = [&](int t) {
        double hourPos = t * (0.5 / 60.0); 
        hourPos = fmod(hourPos, 12.0);
        double minutePos = t / 5.0;
        minutePos = fmod(minutePos, 12.0);
        return pair<double,double>(hourPos, minutePos);
    };

    long long ans = 0;
    int start = a;
    int end = b;
    if (start == end) return 0;

    auto getFirstGap = [&](int from, bool isWrapping) -> int {
        int curr = from;
        if (isWrapping) curr = (from + 1) % total;
        else curr = from + 1;
        if (!isWrapping && curr >= total) return total;
        return curr;
    };

    auto nextEvent = [&](int t) -> int {
        int s = t;
        auto base = timeToPos(s);
        double hourPos = base.first;
        double minutePos = base.second;

        double curDiff = minutePos - hourPos;
        curDiff = fmod(curDiff + 12.0, 12.0);

        double relSpeed = (12.0 / 60.0) - (0.5 / 60.0);
        double interval = 12.0 / relSpeed;
        double deltaMin = (12.0 - curDiff) / relSpeed;
        int steps = (int)ceil(deltaMin - 1e-12);
        if (steps < 0) steps = 0;
        int nt = s + steps;
        if (nt == s) nt = s + 1;
        return nt;
    };

    auto within = [&](int t, int start, int end)->bool{
        if (start < end) return t > start && t < end;
        return t > start || t < end;
    };

    auto countInRange = [&](int start, int end)->long long{
        long long cnt = 0;
        int t = start;
        if (start < end) {
            while (true) {
                double hourPos = (t*(0.5/60.0));
                hourPos = fmod(hourPos, 12.0);
                double minutePos = (t/5.0);
                minutePos = fmod(minutePos, 12.0);
                double curDiff = minutePos - hourPos;
                curDiff = fmod(curDiff + 12.0, 12.0);

                double relSpeed = (12.0/60.0) - (0.5/60.0);
                double nextDiff = 0.0;
                double deltaMin = (12.0 - curDiff) / relSpeed;
                int step = (int)ceil(deltaMin - 1e-12);
                if (step <= 0) step = 1;
                int nt = t + step;
                if (nt >= end) break;
                cnt++;
                t = nt;
            }
        } else {
            int wrappedEnd = end;
            int t2 = start;
            while (t2 < total) {
                double hourPos = (t2*(0.5/60.0));
                hourPos = fmod(hourPos, 12.0);
                double minutePos = (t2/5.0);
                minutePos = fmod(minutePos, 12.0);
                double curDiff = minutePos - hourPos;
                curDiff = fmod(curDiff + 12.0, 12.0);

                double relSpeed = (12.0/60.0) - (0.5/60.0);
                double deltaMin = (12.0 - curDiff) / relSpeed;
                int step = (int)ceil(deltaMin - 1e-12);
                if (step <= 0) step = 1;
                int nt = t2 + step;
                if (nt >= total) break;
                cnt++;
                t2 = nt;
            }
            int t3 = -1;
            t3 = -1; 
            (void)t3;
            int from2 = -1;
            from2 = total - 1;
            (void)from2;

            int twrap = start;
            while (true) {
                int tmin = (twrap % total);
                double hourPos = (tmin*(0.5/60.0));
                hourPos = fmod(hourPos, 12.0);
                double minutePos = (tmin/5.0);
                minutePos = fmod(minutePos, 12.0);
                double curDiff = minutePos - hourPos;
                curDiff = fmod(curDiff + 12.0, 12.0);

                double relSpeed = (12.0/60.0) - (0.5/60.0);
                double deltaMin = (12.0 - curDiff) / relSpeed;
                int step = (int)ceil(deltaMin - 1e-12);
                if (step <= 0) step = 1;
                int nt = twrap + step;
                int modt = nt % total;
                if (modt >= end && modt <= start) {
                    // shouldn't happen
                }
                // check within wrap: nt corresponds to time modt, must be in (start, end) along wrap
                if (!(modt > start || modt < end)) break;
                cnt++;
                twrap = nt;
                if (cnt > 1000) break;
                if (twrap - start > total) break;
            }
        }
        return cnt;
    };

    auto bruteCount = [&](int start, int end)->long long{
        long long cnt=0;
        long long t=start;
        auto check = [&](int tt)->bool{
            int cur = tt % total;
            double hourPos = cur*(0.5/60.0);
            hourPos = fmod(hourPos, 12.0);
            double minutePos = cur/5.0;
            minutePos = fmod(minutePos, 12.0);
            return fabs(minutePos - hourPos) < 1e-9;
        };
        if (start < end) {
            for(int tt=start+1; tt<end; ++tt) if(check(tt)) cnt++;
        } else {
            for(int tt=start+1; tt<start+total; ++tt) {
                int modt=tt%total;
                if(modt==start) continue;
                bool in = (modt>start) || (modt<end);
                if(in) if(check(tt)) cnt++;
            }
        }
        return cnt;
    };

    long long aMin = a;
    long long bMin = b;

    long long result;
    result = bruteCount((int)aMin, (int)bMin);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long h1, m1, h2, m2;
    if (!(cin >> h1 >> m1 >> h2 >> m2)) return 0;
    cout << countMinuteHandsPassHour(h1, m1, h2, m2) << "\n";
    return 0;
}