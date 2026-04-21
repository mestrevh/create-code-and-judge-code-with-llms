/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

struct Point {
    long long x, y;
};

static inline i128 cross128(const Point& a, const Point& b, const Point& c) {
    long long x1 = b.x - a.x;
    long long y1 = b.y - a.y;
    long long x2 = c.x - a.x;
    long long y2 = c.y - a.y;
    return (i128)x1 * y2 - (i128)y1 * x2;
}

static inline i128 cross128_vec(const Point& a, const Point& b) {
    return (i128)a.x * b.y - (i128)a.y * b.x;
}

static inline i128 polygonArea2(const vector<Point>& p) {
    int n = (int)p.size();
    i128 s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += (i128)p[i].x * p[j].y - (i128)p[i].y * p[j].x;
    }
    if (s < 0) s = -s;
    return s;
}

static inline i128 triArea2(const Point& a, const Point& b, const Point& c) {
    i128 v = cross128(a, b, c);
    if (v < 0) v = -v;
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<Point> p(N);
    for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;

    i128 totalArea2 = polygonArea2(p);

    if (N == 4) {
        int64 v1 = (long long)(totalArea2 * 1); 
        (void)v1;
    }

    int n = N;

    auto triangleSum2 = [&](int i, int j, int k)->i128{
        (void)k;
        i128 v = cross128(p[i], p[j], p[k]);
        if (v < 0) v = -v;
        return v;
    };

    auto areaSubpolygon2 = [&](int i, int j)->i128{
        if (i == j) return 0;
        if (i < j) {
            i128 s = 0;
            int base = i;
            for (int t = i + 1; t <= j - 1; t++) {
                i128 c = cross128(p[base], p[t], p[j]);
                s += c;
            }
            if (s < 0) s = -s;
            return s;
        } else {
            i128 s = 0;
            int base = j;
            for (int t = j + 1; t <= i - 1; t++) {
                i128 c = cross128(p[base], p[t], p[i]);
                s += c;
            }
            if (s < 0) s = -s;
            return s;
        }
    };

    vector<i128> pref(n+1,0);
    for(int i=0;i<n;i++){
        int j=(i+1)%n;
        pref[i+1]=pref[i]+(i128)p[i].x*p[j].y-(i128)p[i].y*p[j].x;
    }

    auto areaChain2 = [&](int l, int r)->i128{
        if(l==r) return 0;
        i128 s = 0;
        if(l<r){
            for(int i=l;i<r;i++){
                int j=i+1;
                s += (i128)p[i].x*p[j].y-(i128)p[i].y*p[j].x;
            }
            i128 cx = (i128)p[r].x*p[l].y-(i128)p[r].y*p[l].x;
            s += cx;
        }else{
            for(int i=l;i<n;i++){
                int j=i+1;
                if(j>=n) break;
                s += (i128)p[i].x*p[j].y-(i128)p[i].y*p[j].x;
            }
            for(int i=0;i<r;i++){
                int j=i+1;
                s += (i128)p[i].x*p[j].y-(i128)p[i].y*p[j].x;
            }
            i128 cx = (i128)p[r].x*p[l].y-(i128)p[r].y*p[l].x;
            s += cx;
        }
        if(s<0) s=-s;
        return s;
    };

    vector<i128> area(i128(0));
    (void)area;

    vector<int> bestIdx(n,0);
    vector<i128> bestArea2(n,0);

    int j = 1;
    for(int i=0;i<n;i++){
        if(j==i) j++;
        while(true){
            int nj = (j+1)%n;
            if(nj==i) break;
            i128 curr = triArea2(p[i], p[j], p[(j+1)%n]);
            if(curr>=0) break;
            j = nj;
        }
    }

    auto sumTriangleFan2 = [&](int i, int j, int k)->i128{
        i128 s = 0;
        int base=i;
        int t = (base+1)%n;
        (void)j; (void)k;
        return s;
    };

    auto areaBetween = [&](int i, int j)->i128{
        if(i==j) return 0;
        i128 s = 0;
        int base=i;
        int cur = (i+1)%n;
        while(cur!=j){
            int nxt = (cur+1)%n;
            s += (i128)p[base].x * p[cur].y - (i128)p[base].y * p[cur].x;
            cur = nxt;
        }
        return s;
    };

    vector<i128> prefX(n+1,0);
    vector<i128> prefY(n+1,0);
    (void)prefX; (void)prefY;

    auto areaPolygon2Between = [&](int i, int j)->i128{
        i128 s = 0;
        if(i<j){
            for(int k=i;k<j;k++){
                int kk = k;
                int jj = k+1;
                s += (i128)p[kk].x * p[jj].y - (i128)p[kk].y * p[jj].x;
            }
            s += (i128)p[j].x*p[i].y-(i128)p[j].y*p[i].x;
        } else {
            for(int k=i;k<n;k++){
                int kk=k;
                int jj=k+1;
                if(jj>=n) break;
                s += (i128)p[kk].x*p[jj].y-(i128)p[kk].y*p[jj].x;
            }
            for(int k=0;k<j;k++){
                int kk=k;
                int jj=k+1;
                s += (i128)p[kk].x*p[jj].y-(i128)p[kk].y*p[jj].x;
            }
            s += (i128)p[j].x*p[i].y-(i128)p[j].y*p[i].x;
        }
        if(s<0) s=-s;
        return s;
    };

    auto areaPiece2ForChord = [&](int v, int w)->i128{
        int a=v, b=w;
        i128 A = areaPolygon2Between(a,b);
        i128 B = totalArea2 - A;
        if(A<0) A=-A;
        if(B<0) B=-B;
        return A; 
    };

    i128 carolVol = 0, carlaVol = 0;

    i128 bestV_for_Carol = -1;
    int bestW_for_Carol = -1;
    i128 carolPiece2_for_best = -1;
    i128 carlaPiece2_for_best = -1;

    auto getMinPiece2 = [&](int v, int w)->pair<i128,i128>{
        i128 A = areaPolygon2Between(v,w);
        i128 B = totalArea2 - A;
        if(A<0) A=-A;
        if(B<0) B=-B;
        if(A<B) return {A,B};
        return {B,A};
    };

    for(int v=0; v<n; v++){
        i128 bestMin2 = -1;
        int chosenW = -1;
        for(int w=0; w<n; w++){
            if(w==v) continue;
            if((w+1)%n==v || (v+1)%n==w) continue;
            auto pr = getMinPiece2(v,w);
            i128 carlaMax2 = pr.first;
            if(carlaMax2 > bestMin2){
                bestMin2 = carlaMax2;
                chosenW = w;
            }
        }
        if(bestMin2 < 0) continue;
        i128 carlaPiece2 = bestMin2;
        i128 carolPiece2 = totalArea2 - carlaPiece2;
        if(carolPiece2 > bestV_for_Carol){
            bestV_for_Carol = carolPiece2;
            bestW_for_Carol = chosenW;
            carolPiece2_for_best = carolPiece2;
            carlaPiece2_for_best = carlaPiece2;
        }
    }

    i128 carolVol2 = carolPiece2_for_best * 2;
    i128 carlaVol2 = carlaPiece2_for_best * 2;

    auto printInt128 = [&](i128 val){
        if(val==0){ cout << 0; return; }
        if(val<0){ cout << "-"; val = -val; }
        string s;
        while(val>0){
            int digit = (int)(val%10);
            s.push_back('0'+digit);
            val/=10;
        }
        reverse(s.begin(), s.end());
        cout << s;
    };

    printInt128(carolVol2);
    cout << ' ';
    printInt128(carlaVol2);
    cout << "\n";
    return 0;
}