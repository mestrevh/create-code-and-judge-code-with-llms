/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Circle{
    double x,y,r;
};

static const double EPS = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W,H,n;
    while ( (cin>>W>>H>>n) ) {
        if (W==0 && H==0 && n==0) break;
        vector<Circle> c(n);
        for(int i=0;i<n;i++){
            cin >> c[i].x >> c[i].y >> c[i].r;
        }

        vector<double> xs;
        xs.reserve(2*n + 2);
        xs.push_back(0.0);
        xs.push_back((double)W);
        for(int i=0;i<n;i++){
            xs.push_back(c[i].x - c[i].r);
            xs.push_back(c[i].x + c[i].r);
        }
        sort(xs.begin(), xs.end());
        vector<double> xvals;
        xvals.reserve(xs.size());
        for(double v: xs){
            if(xvals.empty() || fabs(v - xvals.back()) > 1e-8) xvals.push_back(v);
        }

        auto yAt = [&](int i, double x, double& ylow, double& yhigh){
            double dx = x - c[i].x;
            double d2 = c[i].r*c[i].r - dx*dx;
            if(d2 < 0) d2 = 0;
            double dy = sqrt(d2);
            ylow = c[i].y - dy;
            yhigh = c[i].y + dy;
        };

        long long zones = 1;

        for(size_t k=0;k+1<xvals.size();k++){
            double L = xvals[k];
            double R = xvals[k+1];
            if(R - L <= 1e-8) continue;

            double xmid = (L + R) / 2.0;
            vector<pair<double,double>> intervals;
            intervals.reserve(n);
            for(int i=0;i<n;i++){
                double dx = xmid - c[i].x;
                if(dx*dx > c[i].r*c[i].r + 1e-7) continue;
                double ylow,yhigh;
                yAt(i,xmid,ylow,yhigh);
                intervals.push_back({ylow,yhigh});
            }
            if(intervals.empty()) continue;

            sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
                if(a.first != b.first) return a.first < b.first;
                return a.second > b.second;
            });

            int m = (int)intervals.size();
            int comps = 0;
            int i=0;
            while(i<m){
                comps++;
                double curEnd = intervals[i].second;
                i++;
                while(i<m && intervals[i].first <= curEnd + 1e-9){
                    curEnd = max(curEnd, intervals[i].second);
                    i++;
                }
            }
            long long add = (long long)comps;
            zones += add;
        }

        cout << zones << "\n";
    }
    return 0;
}