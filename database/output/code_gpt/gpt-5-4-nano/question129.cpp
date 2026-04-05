/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Vec3 {
    double x,y,z;
    Vec3() : x(0),y(0),z(0) {}
    Vec3(double a,double b,double c):x(a),y(b),z(c){}
    Vec3 operator+(const Vec3& o) const { return Vec3(x+o.x,y+o.y,z+o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x-o.x,y-o.y,z-o.z); }
    Vec3 operator*(double k) const { return Vec3(x*k,y*k,z*k); }
    Vec3 operator/(double k) const { return Vec3(x/k,y/k,z/k); }
};

static inline double dot(const Vec3& a,const Vec3& b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
static inline Vec3 cross(const Vec3& a,const Vec3& b){
    return Vec3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
static inline double norm2(const Vec3& a){ return dot(a,a); }
static inline double norm(const Vec3& a){ return sqrt(norm2(a)); }

static inline bool feasibleByPlanes(const Vec3& p, const array<Vec3,4>& v, const array<Vec3,4>& n, const array<double,4>& d, double eps=1e-10){
    for(int i=0;i<4;i++){
        if(dot(n[i], p) - d[i] > eps) return false;
    }
    return true;
}

static inline Vec3 closestPointOnSegment(const Vec3& a, const Vec3& b, const Vec3& p){
    Vec3 ab = b-a;
    double t = dot(p-a, ab)/max(1e-30, dot(ab,ab));
    t = max(0.0, min(1.0, t));
    return a + ab*t;
}

static Vec3 closestPointBetweenTriangles(const Vec3& A, const Vec3& B, const Vec3& C,
                                         const Vec3& D, const Vec3& E, const Vec3& F){
    auto pointInTriangle = [&](const Vec3& X, const Vec3& P0, const Vec3& P1, const Vec3& P2)->bool{
        Vec3 n = cross(P1-P0, P2-P0);
        double area2 = norm2(n);
        if(area2 < 1e-18){
            return false;
        }
        Vec3 c0 = cross(P1-P0, X-P0);
        Vec3 c1 = cross(P2-P1, X-P1);
        Vec3 c2 = cross(P0-P2, X-P2);
        double s0 = dot(n, c0);
        double s1 = dot(n, c1);
        double s2 = dot(n, c2);
        double eps = 1e-9;
        if((s0>=-eps && s1>=-eps && s2>=-eps) || (s0<=eps && s1<=eps && s2<=eps)) return true;
        return false;
    };

    Vec3 n1 = cross(B-A, C-A);
    Vec3 n2 = cross(E-D, F-D);

    auto projectPointOntoPlane = [&](const Vec3& P, const Vec3& P0, const Vec3& n)->Vec3{
        double nn = dot(n,n);
        if(nn < 1e-18) return P0;
        double t = dot(n, P0-P)/nn;
        return P + n*t;
    };

    vector<pair<Vec3,Vec3>> candidates;
    auto addCandidate = [&](const Vec3& p1, const Vec3& p2){
        candidates.push_back({p1,p2});
    };

    Vec3 n = n1;
    if(norm2(n) < 1e-18) n = n2;

    auto collectFromEdges = [&](const Vec3& P0,const Vec3& P1,const Vec3& Q0,const Vec3& Q1){
        Vec3 c = closestPointOnSegment(P0,P1,Q0);
        addCandidate(c, closestPointOnSegment(Q0,Q1,c));
        c = closestPointOnSegment(P0,P1,Q1);
        addCandidate(c, closestPointOnSegment(Q0,Q1,c));
        Vec3 d = closestPointOnSegment(Q0,Q1,P0);
        addCandidate(closestPointOnSegment(P0,P1,d), d);
        d = closestPointOnSegment(Q0,Q1,P1);
        addCandidate(closestPointOnSegment(P0,P1,d), d);
    };

    addCandidate(closestPointOnSegment(A,B,D), closestPointOnSegment(D,E,closestPointOnSegment(A,B,D)));
    addCandidate(closestPointOnSegment(A,C,E), closestPointOnSegment(D,E,closestPointOnSegment(A,C,E)));
    addCandidate(closestPointOnSegment(B,C,F), closestPointOnSegment(E,F,closestPointOnSegment(B,C,F)));

    collectFromEdges(A,B,D,E);
    collectFromEdges(A,B,E,F);
    collectFromEdges(A,B,F,D);
    collectFromEdges(B,C,D,E);
    collectFromEdges(B,C,E,F);
    collectFromEdges(B,C,F,D);
    collectFromEdges(C,A,D,E);
    collectFromEdges(C,A,E,F);
    collectFromEdges(C,A,F,D);

    Vec3 centroid1 = (A+B+C)/3.0;
    Vec3 centroid2 = (D+E+F)/3.0;

    if(norm2(n1) >= 1e-18){
        Vec3 P = centroid2;
        Vec3 proj = projectPointOntoPlane(P,A,n1);
        if(pointInTriangle(proj,A,B,C)) addCandidate(proj, closestPointOnSegment(D,E,proj));
        if(pointInTriangle(proj,D,E,F)) addCandidate(proj, proj);
    }
    if(norm2(n2) >= 1e-18){
        Vec3 P = centroid1;
        Vec3 proj = projectPointOntoPlane(P,D,n2);
        if(pointInTriangle(proj,D,E,F)) addCandidate(closestPointOnSegment(A,B,proj), proj);
        if(pointInTriangle(proj,A,B,C)) addCandidate(proj, proj);
    }

    double best = 1e100;
    Vec3 bestP;
    for(auto &cand : candidates){
        Vec3 p1 = cand.first;
        Vec3 p2 = cand.second;
        double dist2 = norm2(p1-p2);
        if(dist2 < best){
            best = dist2;
            bestP = p1;
        }
    }
    return bestP;
}

static Vec3 closestPointOnTetra(const array<Vec3,4>& v, const array<Vec3,4>& faceN, const array<double,4>& faceD, const Vec3& p){
    Vec3 best = v[0];
    double bestDist2 = 1e300;

    auto consider = [&](const Vec3& q){
        Vec3 diff = q - p;
        double d2 = norm2(diff);
        if(d2 < bestDist2){
            bestDist2 = d2;
            best = q;
        }
    };

    for(int i=0;i<4;i++) consider(v[i]);

    for(int i=0;i<4;i++){
        int i2 = (i+1)&3;
        int i3 = (i+2)&3;
        int i4 = (i+3)&3;
    }

    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            Vec3 q = closestPointOnSegment(v[i], v[j], p);
            if(feasibleByPlanes(q, v, faceN, faceD)) consider(q);
        }
    }

    for(int f=0;f<4;f++){
        int a = (f+1)&3;
        int b = (f+2)&3;
        int c = (f+3)&3;
        while(true){
            if(a==f){ a=(a+1)&3; continue;}
            break;
        }
        Vec3 A=v[(f+1)&3], B=v[(f+2)&3], C=v[(f+3)&3];
        Vec3 n = faceN[f];
        double nn = dot(n,n);
        if(nn < 1e-18) continue;
        Vec3 proj = p - n*( (dot(n,p) - faceD[f]) / nn );
        Vec3 v0=A, v1=B, v2=C;
        Vec3 ntri = cross(v1-v0, v2-v0);
        if(norm2(ntri) < 1e-18) continue;

        Vec3 c0 = cross(v1-v0, proj-v0);
        Vec3 c1 = cross(v2-v1, proj-v1);
        Vec3 c2 = cross(v0-v2, proj-v2);

        double s0 = dot(ntri, c0);
        double s1 = dot(ntri, c1);
        double s2 = dot(ntri, c2);
        double eps=1e-9;
        if((s0>=-eps && s1>=-eps && s2>=-eps) || (s0<=eps && s1<=eps && s2<=eps)){
            if(feasibleByPlanes(proj, v, faceN, faceD)) consider(proj);
        }
    }

    return best;
}

static double tetraDistance(const array<Vec3,4>& A, const array<Vec3,4>& B){
    auto buildPlanes = [&](const array<Vec3,4>& V, array<Vec3,4>& n, array<double,4>& d){
        for(int f=0;f<4;f++){
            int i0 = f;
            int i1 = (f+1)&3;
            int i2 = (f+2)&3;
            int i3 = (f+3)&3;
            Vec3 p0 = V[i1], p1 = V[i2], p2 = V[i3];
            Vec3 nn = cross(p1-p0, p2-p0);
            double nd = dot(nn, p0);
            Vec3 pOpp = V[i0];
            if(dot(nn, pOpp) > nd) {
                nn = nn * (-1.0);
                nd = -nd;
            }
            n[f]=nn;
            d[f]=nd;
        }
    };

    array<Vec3,4> nA, nB;
    array<double,4> dA, dB;
    buildPlanes(A, nA, dA);
    buildPlanes(B, nB, dB);

    double best2 = 1e300;

    for(int i=0;i<4;i++){
        Vec3 p = closestPointOnTetra(B, nB, dB, A[i]);
        best2 = min(best2, norm2(p - A[i]));
    }
    for(int i=0;i<4;i++){
        Vec3 p = closestPointOnTetra(A, nA, dA, B[i]);
        best2 = min(best2, norm2(p - B[i]));
    }

    auto faceVerts = [&](const array<Vec3,4>& T, int f)->array<Vec3,3>{
        int a=(f+1)&3,b=(f+2)&3,c=(f+3)&3;
        return {T[a],T[b],T[c]};
    };

    for(int f1=0;f1<4;f1++){
        auto tri1 = faceVerts(A,f1);
        for(int f2=0;f2<4;f2++){
            auto tri2 = faceVerts(B,f2);
            Vec3 p = closestPointBetweenTriangles(tri1[0],tri1[1],tri1[2], tri2[0],tri2[1],tri2[2]);
            Vec3 q = closestPointOnTetra(A,nA,dA,p);
            Vec3 qq = closestPointOnTetra(B,nB,dB,q);
            best2 = min(best2, norm2(qq - q));
        }
    }

    return sqrt(best2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin>>T)) return 0;
    cout.setf(std::ios::fixed); 
    cout<<setprecision(2);
    for(int tc=0; tc<T; tc++){
        array<Vec3,4> R, I;
        for(int i=0;i<4;i++){
            long long x,y,z; cin>>x>>y>>z;
            R[i]=Vec3((double)x,(double)y,(double)z);
        }
        for(int i=0;i<4;i++){
            long long x,y,z; cin>>x>>y>>z;
            I[i]=Vec3((double)x,(double)y,(double)z);
        }
        double ans = tetraDistance(R,I);
        cout<<ans+1e-9<<"\n";
    }
    return 0;
}