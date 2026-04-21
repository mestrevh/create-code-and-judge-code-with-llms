/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A1, A2, A3, A4;
    if (!(cin >> A1 >> A2 >> A3 >> A4)) return 0;
    vector<long long> a = {A1, A2, A3, A4};
    sort(a.begin(), a.end());
    
    long long maxA = a[3];
    bool ok = false;
    
    auto check = [&](long long x, long long y, long long z, long long w) -> bool {
        vector<long long> v = {x, y, z, w};
        sort(v.begin(), v.end());
        long long r = v[3];
        long long s = v[2];
        long long p = v[0];
        long long q = v[1];
        
        long long det = p * r;
        long long sum = s + q;
        if (sum == 0) return false;
        if (det % sum != 0) return false;
        long long b = det / sum;
        long long a1 = r - b;
        if (a1 <= 0 || b <= 0) return false;
        
        auto prodCheck = [&](long long left, long long right) -> bool {
            if (left <= 0 || right <= 0) return false;
            long long d1 = p;
            long long d2 = q;
            long long e1 = left * a1;
            long long e2 = right * b;
            return (e1 == d1 || e1 == d2) && (e2 == d1 || e2 == d2);
        };
        
        return true;
    };
    
    for (int i = 0; i < 4 && !ok; i++) {
        for (int j = 0; j < 4 && !ok; j++) if (j != i) {
            for (int k = 0; k < 4 && !ok; k++) if (k != i && k != j) {
                int l = 6 - i - j - k;
                long long A = a[i], B = a[j], C = a[k], D = a[l];
                
                long long S = A + D;
                if (S == 0) continue;
                
                long long det = A * D;
                if (det % S != 0) continue;
                long long b = det / S;
                long long aSide = A - b;
                if (aSide <= 0 || b <= 0) continue;
                
                if (B % b != 0) continue;
                if (C % aSide != 0) continue;
                long long y = B / b;
                long long x = C / aSide;
                
                if (x <= 0 || y <= 0) continue;
                if (aSide * b != A + D - (aSide + b) ? 0 : 0) {}
                
                long long total = aSide * x + b * y;
                (void)total;
                
                if (A == x * aSide && B == y * b && C == x * b && D == y * aSide) {
                    ok = true;
                } else {
                    if (A == x * aSide && B == x * b && C == y * b && D == y * aSide) {
                        ok = true;
                    }
                }
                
                if (ok) break;
            }
        }
    }
    
    vector<long long> perm = a;
    do {
        long long A = perm[0], B = perm[1], C = perm[2], D = perm[3];
        vector<long long> used = {A,B,C,D};
        sort(used.begin(), used.end());
        long long big = used[3];
        long long med = used[2];
        
        vector<long long> all = {A,B,C,D};
        for (int idx = 0; idx < 4 && !ok; idx++) {
            for (int jdx = 0; jdx < 4 && !ok; jdx++) if (jdx != idx) {
                for (int kdx = 0; kdx < 4 && !ok; kdx++) if (kdx != idx && kdx != jdx) {
                    int ldx = 6 - idx - jdx - kdx;
                    long long TL = all[idx], TR = all[jdx], BL = all[kdx], BR = all[ldx];
                    long long Sx = TL + BR;
                    long long Sy = TR + BL;
                    long long denom = Sx;
                    if (denom == 0) continue;
                    long long detx = TL * BR;
                    if (detx % Sx != 0) continue;
                    long long topWidth = detx / Sx;
                    long long heightLeft = TL / topWidth;
                    if (topWidth <= 0 || heightLeft <= 0) continue;
                    if (TL % topWidth != 0) continue;
                    
                    long long heightRight = BR / topWidth;
                    if (BR % topWidth != 0) continue;
                    
                    if (TR % heightRight != 0) continue;
                    if (BL % heightLeft != 0) continue;
                    long long topRightWidth = TR / heightRight;
                    long long bottomLeftWidth = BL / heightLeft;
                    if (topRightWidth <= 0 || bottomLeftWidth <= 0) continue;
                    
                    if (topRightWidth == bottomLeftWidth) {
                        ok = true;
                    }
                }
            }
        }
    } while (next_permutation(perm.begin(), perm.end()) && !ok);
    
    cout << (ok ? 'S' : 'N') << "\n";
    return 0;
}