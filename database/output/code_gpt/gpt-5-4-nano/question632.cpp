/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FaceCube {
    array<int,6> f; // faces: 0=U,1=D,2=L,3=R,4=F,5=B
};

struct Vec { int x,y,z; };

static Vec addVec(const Vec&a,const Vec&b){ return {a.x+b.x,a.y+b.y,a.z+b.z}; }
static Vec negVec(const Vec&a){ return {-a.x,-a.y,-a.z}; }
static bool eqVec(const Vec&a,const Vec&b){ return a.x==b.x && a.y==b.y && a.z==b.z; }

static Vec rotateVec(const Vec&v, const array<int,3>&perm, const array<int,3>&sign){
    int c[3] = {v.x,v.y,v.z};
    return { sign[0]*c[perm[0]], sign[1]*c[perm[1]], sign[2]*c[perm[2]] };
}

static array<int,6> buildFaceOrderForRotation(const array<int,3>&perm, const array<int,3>&sign,
                                               const array<Vec,6>&dirs){
    array<int,6> rotIndex{};
    for(int i=0;i<6;i++){
        Vec nd = rotateVec(dirs[i], perm, sign);
        for(int j=0;j<6;j++){
            if(eqVec(nd, dirs[j])){ rotIndex[i]=j; break; }
        }
    }
    return rotIndex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<Vec,6> dirs = {Vec{0,1,0}, Vec{0,-1,0}, Vec{-1,0,0}, Vec{1,0,0}, Vec{0,0,1}, Vec{0,0,-1}};
    vector<array<int,6>> rots;

    vector<array<int,3>> perms;
    array<int,3> p = {0,1,2};
    do perms.push_back(p); while(next_permutation(p.begin(), p.end()));

    for(auto &perm : perms){
        for(int sx : {-1,1}){
            for(int sy : {-1,1}){
                for(int sz : {-1,1}){
                    int det = perm[0]*(sy*sz - 0) + perm[1]*(sx*sz - 0) + perm[2]*(sx*sy - 0);
                    (void)det;
                }
            }
        }
    }

    for(auto &perm : perms){
        for(int sx : {-1,1}){
            for(int sy : {-1,1}){
                for(int sz : {-1,1}){
                    int det;
                    {
                        int m[3][3] = {};
                        m[0][perm[0]] = sx;
                        m[1][perm[1]] = sy;
                        m[2][perm[2]] = sz;
                        det = m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]) - m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]) + m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
                    }
                    if(det != 1) continue;
                    array<int,3> sign = {sx,sy,sz};
                    rots.push_back(buildFaceOrderForRotation(perm, sign, dirs));
                }
            }
        }
    }

    sort(rots.begin(), rots.end());
    rots.erase(unique(rots.begin(), rots.end()), rots.end());

    int N;
    while ( (cin >> N) ){
        if(N==0) break;
        unordered_set<string> seen;
        seen.reserve((size_t)N*2+1);

        for(int i=0;i<N;i++){
            int a; // first line color of top-left? but read full structure from input spec
            // Input format: each cube described in 3 lines of 4 numbers.
            // The example shows: "1 2 4 5" on first line? Actually in text: "1 2 4 5 6 3" but likely layout:
            // Common known problem: represent cube net as:
            // line1: c4 c0 c1 c5? Let's decode precisely by standard UVa/ICPC "Colored Cubes" problem:
            // Format: first line has two numbers: top row of 4 face: left and right? Not possible.
            // Given statement: "In three lines showing the colors of six open faces, in the given format below example:
            // 1 2 4 5 6 3". That implies first row contains 2 numbers: "1 2 4"?? Hmm.
            // But sample input: N=3, then:
            // 0
            // 0 7 2 3
            // 1
            // 0
            // 1 2 3 7
            // 0
            // 3
            // 0 0 2 1
            // 7
            // 2
            // ...
            // Observing, each cube description seems to be:
            // first line: single int (one face)
            // second line: four ints
            // third line: single int
            // That's 1 + 4 + 1 = 6 faces, matches "three lines" wording.
            int top, bottom, leftTop, rightTop, leftBottom, rightBottom;
            // Actually second line has 4 numbers: x1 x2 x3 x4
            // first line: color of one face adjacent to x2 and x3? Let's map using example in statement:
            // "1 2 4 5 6 3" corresponds to faces:
            // - face with color 1 is opposite color 3
            // - face with color 2 is neighbor of 1,3,4,6 and opposite color 5
            // If we denote cube net as:
            // first line: 1
            // second line: 2 4 5 6
            // third line: 3
            // then colors are [1][2 4 5 6][3] -> order: 1,2,4,5,6,3.
            // Great: then first line is U(=1), third line is D(=3), and middle four represent around a vertical axis: L,F,R,B in some order.
            // We know: color 2 neighbors {1,3,4,6} and opposite 5.
            // In this net, 2 is left adjacent to 4 and also adjacent to outer faces 1 and 3.
            // So 2 corresponds to left face (L). 5 is opposite it, so 5 corresponds to right face (R).
            // Then remaining: 4 and 6 are front/back. Since 2 neighbors 4 and 6, those are adjacent to left, i.e., front and back.
            // Determine which is front: not needed for equivalence when using full rotations, but must be consistent.
            // Use mapping: second line numbers: [2,4,5,6] as [L,F,R,B]. Then opposite pairs: L vs R -> 2 vs 5 ok.
            // U vs D -> 1 vs 3 ok.
            // Great.
            // Read format:
            // line1: top face (U) single int
            // line2: four ints: L F R B
            // line3: bottom face (D) single int
            cin >> top;
            cin >> leftTop >> leftBottom >> rightTop >> rightBottom;
            cin >> bottom;
            FaceCube c;
            c.f[0]=top;
            c.f[1]=bottom;
            c.f[2]=leftTop;
            c.f[4]=leftBottom;
            c.f[3]=rightTop;
            c.f[5]=rightBottom;

            array<int,6> best = {};
            bool first = true;
            for(auto &ord : rots){
                array<int,6> arr{};
                for(int k=0;k<6;k++) arr[k]=c.f[ord[k]];
                if(first){
                    best=arr; first=false;
                }else{
                    if(arr<best) best=arr;
                }
            }
            string key;
            key.reserve(6*2);
            for(int k=0;k<6;k++){
                key.push_back(char('0'+best[k]));
                key.push_back('#');
            }
            seen.insert(key);
        }

        cout << seen.size() << "\n";
    }
    return 0;
}