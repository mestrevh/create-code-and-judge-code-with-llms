/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long double PI = acosl(-1.0L);

static long double deg2rad(long double d){ return d * PI / 180.0L; }

static inline long double normAngle(long double a){
    a = fmodl(a, 2*PI);
    if(a < 0) a += 2*PI;
    return a;
}

struct Point{
    long double x,y;
};

static long double dot(const Point& a, const Point& b){ return a.x*b.x + a.y*b.y; }
static long double crossp(const Point& a, const Point& b){ return a.x*b.y - a.y*b.x; }
static Point operator-(const Point& a, const Point& b){ return {a.x-b.x, a.y-b.y}; }

static Point polarLineDir(long double ang){
    return {cosl(ang), sinl(ang)};
}

static long double angleOfVec(const Point& v){
    long double ang = atan2l(v.y, v.x);
    if(ang < 0) ang += 2*PI;
    return ang;
}

static bool intersectRayCircle(const Point& O, const Point& dir, const Point& C, long double R, long double &tOut){
    Point f = {O.x - C.x, O.y - C.y};
    long double a = dot(dir, dir);
    long double b = 2*dot(f, dir);
    long double c = dot(f,f) - R*R;
    long double disc = b*b - 4*a*c;
    if(disc < -1e-12L) return false;
    if(disc < 0) disc = 0;
    long double sdisc = sqrtl(disc);
    long double t1 = (-b - sdisc) / (2*a);
    long double t2 = (-b + sdisc) / (2*a);
    long double t = -1;
    if(t1 >= 0) t = t1;
    else if(t2 >= 0) t = t2;
    if(t < 0) return false;
    tOut = t;
    return true;
}

static bool intersectLineCircle(const Point& O, const Point& dir, const Point& C, long double R, Point& I1, Point& I2){
    Point f = {O.x - C.x, O.y - C.y};
    long double a = dot(dir, dir);
    long double b = 2*dot(f, dir);
    long double c = dot(f,f) - R*R;
    long double disc = b*b - 4*a*c;
    if(disc < -1e-12L) return false;
    if(disc < 0) disc = 0;
    long double sdisc = sqrtl(disc);
    long double t1 = (-b - sdisc) / (2*a);
    long double t2 = (-b + sdisc) / (2*a);
    I1 = {O.x + dir.x*t1, O.y + dir.y*t1};
    I2 = {O.x + dir.x*t2, O.y + dir.y*t2};
    return true;
}

static long double triangleArea(const Point& a, const Point& b, const Point& c){
    return fabsl(crossp(b-a, c-a)) / 2.0L;
}

static long double sectorArea(long double r, long double ang){
    return 0.5L * r * r * ang;
}

static long double areaWedgeCircle(const Point& C, long double R, const Point& P0, long double th1, long double th2){
    Point d1 = polarLineDir(th1);
    Point d2 = polarLineDir(th2);

    Point I1a, I1b, I2a, I2b;
    bool ok1 = intersectLineCircle(P0, d1, C, R, I1a, I1b);
    bool ok2 = intersectLineCircle(P0, d2, C, R, I2a, I2b);
    if(!ok1 || !ok2) return 0.0L;

    Point dirA = d1;
    long double tA;
    bool hitA = intersectRayCircle(P0, dirA, C, R, tA);
    if(!hitA) return 0.0L;
    Point A = {P0.x + dirA.x*tA, P0.y + dirA.y*tA};

    Point dirB = d2;
    long double tB;
    bool hitB = intersectRayCircle(P0, dirB, C, R, tB);
    if(!hitB) return 0.0L;
    Point B = {P0.x + dirB.x*tB, P0.y + dirB.y*tB};

    vector<pair<long double, Point>> boundary;
    boundary.push_back({angleOfVec({A.x - C.x, A.y - C.y}), A});
    boundary.push_back({angleOfVec({B.x - C.x, B.y - C.y}), B});

    long double angA = boundary[0].first;
    long double angB = boundary[1].first;

    auto areaByTriangleFan = [&](bool major){
        long double dist = sqrtl((P0.x-C.x)*(P0.x-C.x) + (P0.y-C.y)*(P0.y-C.y));
        if(dist < 1e-15L) return 0.0L;
        long double angO = angleBetween({A.x-P0.x, A.y-P0.y}, {B.x-P0.x, B.y-P0.y});
        return 0.0L;
    };

    long double theta = th2 - th1;
    theta = fmodl(theta, 2*PI);
    if(theta < 0) theta += 2*PI;

    if(theta < 1e-18L) return 0.0L;

    long double angA_fromC = angleOfVec({A.x - C.x, A.y - C.y});
    long double angB_fromC = angleOfVec({B.x - C.x, B.y - C.y});

    long double diffMinor = angB_fromC - angA_fromC;
    diffMinor = fmodl(diffMinor, 2*PI);
    if(diffMinor < 0) diffMinor += 2*PI;
    if(diffMinor > PI) diffMinor = 2*PI - diffMinor;

    bool isFirstSmall = (theta <= PI + 1e-12L);

    vector<Point> pts;
    pts.push_back(P0);
    pts.push_back(A);
    pts.push_back(B);

    auto getAngleAtP = [&](){
        Point u = {A.x - P0.x, A.y - P0.y};
        Point v = {B.x - P0.x, B.y - P0.y};
        long double nu = sqrtl(dot(u,u));
        long double nv = sqrtl(dot(v,v));
        long double c = dot(u,v) / (nu*nv);
        if(c > 1) c = 1;
        if(c < -1) c = -1;
        long double ang = acosl(c);
        return ang;
    };

    long double angAtP = getAngleAtP();

    if(!isFirstSmall){
        angAtP = 2*PI - angAtP;
    }

    long double areaTri = triangleArea(P0, A, B);
    long double areaSec = sectorArea(R, angAtP);

    return areaTri + areaSec;
}

static long double angleBetween(const Point& u, const Point& v){
    long double nu = sqrtl(dot(u,u));
    long double nv = sqrtl(dot(v,v));
    if(nu < 1e-18L || nv < 1e-18L) return 0;
    long double c = dot(u,v)/(nu*nv);
    if(c > 1) c = 1;
    if(c < -1) c = -1;
    return acosl(c);
}

static bool inArc(long double ang, long double start, long double end){
    ang = normAngle(ang);
    start = normAngle(start);
    end = normAngle(end);
    long double span = end - start;
    span = fmodl(span, 2*PI);
    if(span < 0) span += 2*PI;
    long double t = ang - start;
    t = fmodl(t, 2*PI);
    if(t < 0) t += 2*PI;
    return t <= span + 1e-18L;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X,Y,R;
    while(cin >> X >> Y >> R){
        long long P,Q,Adeg,Tdeg;
        if(!(cin >> P >> Q >> Adeg >> Tdeg)) break;

        if(X==0 && Y==0 && R==0 && P==0 && Q==0 && Adeg==0 && Tdeg==0) break;

        Point C{(long double)X,(long double)Y};
        Point P0{(long double)P,(long double)Q};
        long double r = (long double)R;

        Point v = {C.x - P0.x, C.y - P0.y};
        long double d = sqrtl(dot(v,v));

        long double base = angleOfVec(v);
        long double half = acosl(r/d);
        long double thLeft = base + half;
        long double thRight = base - half;
        thLeft = normAngle(thLeft);
        thRight = normAngle(thRight);

        long double dir = deg2rad((long double)Adeg);
        long double spread = deg2rad((long double)Tdeg);
        long double t1 = normAngle(dir);
        long double t2 = normAngle(dir + spread);

        long double u = angleOfVec({P0.x - C.x, P0.y - C.y});
        (void)u;

        vector<pair<long double,long double>> arcs;
        if(spread >= 2*PI - 1e-12L){
            arcs.push_back({0,2*PI});
        }else{
            long double start = t1;
            long double end = t2;
            long double span = end - start;
            span = fmodl(span, 2*PI);
            if(span < 0) span += 2*PI;
            arcs.push_back({start,end});
        }

        long double theta = 0.0L;
        (void)theta;

        auto computeWedgeArea = [&](long double aStart, long double aEnd)->long double{
            aStart = normAngle(aStart);
            aEnd = normAngle(aEnd);
            if(fabsl(aStart-aEnd) < 1e-18L){
                return 0.0L;
            }
            long double span = aEnd - aStart;
            span = fmodl(span, 2*PI);
            if(span < 0) span += 2*PI;
            if(span < 1e-18L) return 0.0L;
            if(span > 2*PI - 1e-10L) span = 2*PI;

            long double ans = 0.0L;
            long double area1 = 0.0L;

            Point dirStart = polarLineDir(aStart);
            Point dirEnd = polarLineDir(aEnd);

            long double t;
            bool hitStart = intersectRayCircle(P0, dirStart, C, r, t);
            bool hitEnd = intersectRayCircle(P0, dirEnd, C, r, t);
            if(!hitStart || !hitEnd){
                return 0.0L;
            }
            long double area = areaWedgeCircle(C, r, P0, aStart, aEnd);
            return area;
        };

        auto intersectAngleInterval = [&](long double s1, long double e1, long double s2, long double e2)->vector<pair<long double,long double>>{
            s1 = normAngle(s1); e1 = normAngle(e1); s2 = normAngle(s2); e2 = normAngle(e2);
            vector<pair<long double,long double>> res;

            auto toIntervals = [&](long double s, long double e){
                long double span = e - s;
                span = fmodl(span, 2*PI);
                if(span < 0) span += 2*PI;
                if(span >= 2*PI - 1e-12L) return vector<pair<long double,long double>>{{0,2*PI}};
                if(e >= s) return vector<pair<long double,long double>>{{s,e}};
                return vector<pair<long double,long double>>{{s,2*PI},{0,e}};
            };

            auto I1 = toIntervals(s1,e1);
            auto I2 = toIntervals(s2,e2);

            for(auto [a,b]: I1){
                for(auto [c,d2]: I2){
                    long double L = max(a,c);
                    long double Rr = min(b,d2);
                    if(Rr - L > 1e-12L){
                        res.push_back({L,Rr});
                    }
                }
            }
            for(auto &pr: res){
                pr.first = normAngle(pr.first);
                pr.second = normAngle(pr.second);
            }
            return res;
        };

        long double wallStart = thRight;
        long double wallEnd = thLeft;
        wallStart = normAngle(wallStart);
        wallEnd = normAngle(wallEnd);

        long double attackStart = t1;
        long double attackEnd = t2;
        attackStart = normAngle(attackStart);
        attackEnd = normAngle(attackEnd);

        vector<pair<long double,long double>> inter = intersectAngleInterval(attackStart, attackEnd, wallStart, wallEnd);

        long double area = 0.0L;
        for(auto [s,e]: inter){
            area += computeWedgeArea(s,e);
        }

        cout.setf(std::ios::fixed); 
        cout << setprecision(1) << (double)area << "\n";
    }
    return 0;
}