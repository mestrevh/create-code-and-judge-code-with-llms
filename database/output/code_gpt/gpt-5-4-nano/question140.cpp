/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
};
static const double EPS = 1e-9;

int sgn(double v){
    if (v > EPS) return 1;
    if (v < -EPS) return -1;
    return 0;
}

double dist2(const Point& a, const Point& b){
    double dx=a.x-b.x, dy=a.y-b.y;
    return dx*dx+dy*dy;
}

double dist(const Point& a, const Point& b){
    return sqrt(dist2(a,b));
}

double cross(const Point& a, const Point& b, const Point& c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

bool onSegmentNoIntersectExt(const Point& a, const Point& b, const Point& p){
    if (fabs(cross(a,b,p)) > EPS) return false;
    if (p.x < min(a.x,b.x)-EPS || p.x > max(a.x,b.x)+EPS) return false;
    if (p.y < min(a.y,b.y)-EPS || p.y > max(a.y,b.y)+EPS) return false;
    return true;
}

bool segmentsProperIntersection(const Point& a, const Point& b, const Point& c, const Point& d){
    double ab_c = cross(a,b,c);
    double ab_d = cross(a,b,d);
    double cd_a = cross(c,d,a);
    double cd_b = cross(c,d,b);

    int s1 = sgn(ab_c);
    int s2 = sgn(ab_d);
    int s3 = sgn(cd_a);
    int s4 = sgn(cd_b);

    if (s1==0 || s2==0 || s3==0 || s4==0){
        return false;
    }
    return (s1*s2 < 0) && (s3*s4 < 0);
}

bool blockByWall(const Point& s, const Point& t, const Point& w1, const Point& w2){
    if (fabs(cross(s,t,w1)) <= EPS && fabs(cross(s,t,w2)) <= EPS){
        return false;
    }
    if (segmentsProperIntersection(s,t,w1,w2)) return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T,M,C;
    while (true){
        if(!(cin>>T>>M>>C)) return 0;
        if(T==-1 && M==-1 && C==-1) break;

        vector<pair<Point,Point>> walls;
        walls.reserve(M);
        for(int i=0;i<M;i++){
            long long X1,Y1,X2,Y2;
            cin>>X1>>Y1>>X2>>Y2;
            Point a{(double)X1,(double)Y1};
            Point b{(double)X2,(double)Y2};
            walls.push_back({a,b});
        }

        vector<Point> cabins(C);
        for(int i=0;i<C;i++){
            long long XC,YC;
            cin>>XC>>YC;
            cabins[i] = {(double)XC,(double)YC};
        }

        long long XQ,YQ,XP,YP;
        cin>>XQ>>YQ>>XP>>YP;
        Point Q{(double)XQ,(double)YQ};
        Point P{(double)XP,(double)YP};

        int N = C + 2;
        vector<Point> nodes(N);
        nodes[0]=Q;
        for(int i=0;i<C;i++) nodes[i+1]=cabins[i];
        nodes[N-1]=P;

        vector<vector<char>> vis(N, vector<char>(N,0));
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                bool ok = true;
                for(auto &w: walls){
                    const Point& a=w.first;
                    const Point& b=w.second;
                    if(blockByWall(nodes[i],nodes[j],a,b)){
                        ok=false; break;
                    }
                }
                if(ok){
                    vis[i][j]=vis[j][i]=1;
                }
            }
        }

        vector<double> best(N, numeric_limits<double>::infinity());
        best[0]=0.0;

        int K = T; 
        if(K==0){
            double ans = numeric_limits<double>::infinity();
            if(vis[0][N-1]) ans = dist(nodes[0], nodes[N-1]);
            else ans = numeric_limits<double>::infinity();
            cout.setf(std::ios::fixed); cout<<setprecision(1)<<ans+0.0<<"\n";
            continue;
        }

        vector<int> distSteps(N, INT_MAX);
        distSteps[0]=0;
        deque<int> dq;
        dq.push_back(0);

        while(!dq.empty()){
            int u=dq.front(); dq.pop_front();
            int du=distSteps[u];
            if(du>=K) continue;
            for(int v=1; v<N-1; v++){}
            for(int v=0; v<N; v++){
                if(!vis[u][v]) continue;
                int w = 1;
                int nd = du + w;
                if(nd<distSteps[v] && nd<=K+1){
                    distSteps[v]=nd;
                    dq.push_back(v);
                }
            }
        }

        int maxTele = K;
        const int INFINT = 1e9;
        vector<vector<double>> dp(maxTele+1, vector<double>(N, numeric_limits<double>::infinity()));
        dp[0][0]=0.0;

        for(int k=0;k<=maxTele;k++){
            for(int u=0;u<N;u++){
                if(dp[k][u] >= numeric_limits<double>::infinity()/4) continue;
                for(int v=0;v<N;v++){
                    if(u==v) continue;
                    if(!vis[u][v]) continue;
                    int nk = k + (v==N-1 ? 0 : 1);
                    if(nk>maxTele) continue;
                    double cost = dp[k][u] + (v==N-1 ? 1.0 : 0.0)*0.0; 
                }
            }
        }

        vector<vector<double>> dp2(maxTele+1, vector<double>(N, numeric_limits<double>::infinity()));
        dp2[0][0]=0.0;

        for(int k=0;k<=maxTele;k++){
            for(int u=0;u<N;u++){
                double cur=dp2[k][u];
                if(cur>=numeric_limits<double>::infinity()/4) continue;

                for(int v=0;v<N;v++){
                    if(u==v) continue;
                    if(!vis[u][v]) continue;

                    double w = dist(nodes[u], nodes[v]);
                    if(v==N-1){
                        dp2[k][v] = min(dp2[k][v], cur + w);
                    }else{
                        int nk = k + 1;
                        if(nk<=maxTele){
                            dp2[nk][v] = min(dp2[nk][v], cur);
                        }
                    }
                }
            }
        }

        double ans = numeric_limits<double>::infinity();
        for(int k=0;k<=maxTele;k++){
            ans = min(ans, dp2[k][N-1]);
        }

        if(ans==numeric_limits<double>::infinity()){
            cout.setf(std::ios::fixed); cout<<setprecision(1)<<0.0<<"\n";
        }else{
            cout.setf(std::ios::fixed); cout<<setprecision(1)<<ans<<"\n";
        }
    }
    return 0;
}