/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pt {
    double x, y;
};

static const double EPS = 1e-9;

static inline double dist(const Pt& a, const Pt& b){
    double dx=a.x-b.x, dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

static inline int sgn(double v){
    if (v > EPS) return 1;
    if (v < -EPS) return -1;
    return 0;
}

static inline double cross(const Pt& a, const Pt& b, const Pt& c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

static inline bool onSegment(const Pt& a, const Pt& b, const Pt& p){
    if (sgn(cross(a,b,p)) != 0) return false;
    return (min(a.x,b.x)-EPS <= p.x && p.x <= max(a.x,b.x)+EPS &&
            min(a.y,b.y)-EPS && p.y <= max(a.y,b.y)+EPS);
}

static inline bool segmentsIntersectProperOrTouch(const Pt& a, const Pt& b, const Pt& c, const Pt& d){
    double c1 = cross(a,b,c);
    double c2 = cross(a,b,d);
    double c3 = cross(c,d,a);
    double c4 = cross(c,d,b);

    int s1 = sgn(c1), s2 = sgn(c2), s3 = sgn(c3), s4 = sgn(c4);

    if (s1 == 0 && onSegment(a,b,c)) return true;
    if (s2 == 0 && onSegment(a,b,d)) return true;
    if (s3 == 0 && onSegment(c,d,a)) return true;
    if (s4 == 0 && onSegment(c,d,b)) return true;

    return (s1*s2 < 0 && s3*s4 < 0);
}

static inline bool segmentsIntersectAny(const Pt& a, const Pt& b, const Pt& c, const Pt& d){
    return segmentsIntersectProperOrTouch(a,b,c,d);
}

static bool samePoint(const Pt& a, const Pt& b){
    return fabs(a.x-b.x) <= 1e-9 && fabs(a.y-b.y) <= 1e-9;
}

struct Segment{
    Pt p1, p2;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int xi, yi, xf, yf;
        int n;
        if(!(cin >> xi >> yi >> xf >> yf >> n)) return 0;
        if(xi==0 && yi==0 && xf==0 && yf==0 && n==0) break;

        vector<Segment> segs;
        segs.reserve(n);
        Pt start{(double)xi,(double)yi};
        Pt finish{(double)xf,(double)yf};

        for(int i=0;i<n;i++){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Segment s;
            s.p1 = Pt{(double)x1,(double)y1};
            s.p2 = Pt{(double)x2,(double)y2};
            segs.push_back(s);
        }

        vector<Pt> nodes;
        nodes.reserve(2*n + 2);
        nodes.push_back(start);
        nodes.push_back(finish);
        for(auto &s: segs){
            nodes.push_back(s.p1);
            nodes.push_back(s.p2);
        }

        int m = (int)nodes.size();
        vector<vector<pair<int,double>>> adj(m);

        vector<Pt> v1 = nodes; // just alias

        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                Pt a = nodes[i], b = nodes[j];
                bool ok = true;
                for(auto &s: segs){
                    Pt c = s.p1, d = s.p2;

                    bool shareA = samePoint(a,c) || samePoint(a,d);
                    bool shareB = samePoint(b,c) || samePoint(b,d);

                    if(shareA && shareB) {
                        continue;
                    }
                    if(shareA || shareB) {
                        Pt shared = shareA ? (samePoint(a,c)? c : d) : (samePoint(b,c)? c : d);
                        if(!samePoint(shared,a) && !samePoint(shared,b)){}
                        if(shareA){
                            if(segmentsIntersectProperOrTouch(a,b,c,d)){
                                if(onSegment(c,d,a) && onSegment(c,d,b)){}
                                else ok=false;
                            }
                        }else{
                            if(segmentsIntersectProperOrTouch(a,b,c,d)){
                                ok=false;
                            }
                        }
                        if(!ok) break;
                        continue;
                    }

                    if(segmentsIntersectAny(a,b,c,d)){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    double w = dist(a,b);
                    adj[i].push_back({j,w});
                    adj[j].push_back({i,w});
                }
            }
        }

        const double INF = 1e100;
        vector<double> d(m, INF);
        vector<char> vis(m, 0);
        d[0]=0;
        for(int it=0;it<m;it++){
            int u=-1;
            for(int i=0;i<m;i++){
                if(!vis[i] && (u==-1 || d[i] < d[u])) u=i;
            }
            if(u==-1) break;
            vis[u]=1;
            for(auto [v,w]: adj[u]){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                }
            }
        }

        double ans = d[1];
        cout.setf(std::ios::fixed); 
        cout<<setprecision(2)<<ans+1e-9<<"\n";
    }

    return 0;
}