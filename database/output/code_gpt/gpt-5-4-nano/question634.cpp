/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int digitToPos(int d){
    if(d==0) return 6;
    if(d==1) return 0;
    if(d==2) return 1;
    if(d==3) return 2;
    if(d==4) return 3;
    if(d==5) return 4;
    if(d==6) return 5;
    if(d==7) return 7;
    if(d==8) return 8;
    return 9;
}

static pair<int,int> posToRC(int p){
    if(p==6) return {3,1};
    if(p==0) return {0,0};
    if(p==1) return {0,1};
    if(p==2) return {0,2};
    if(p==3) return {1,0};
    if(p==4) return {1,1};
    if(p==5) return {1,2};
    if(p==7) return {2,0};
    if(p==8) return {2,1};
    return {2,2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> adj(10);
    for(int a=0;a<=9;a++){
        auto [ra,ca]=posToRC(digitToPos(a));
        for(int b=0;b<=9;b++){
            if(a==b) continue;
            auto [rb,cb]=posToRC(digitToPos(b));
            if(abs(ra-rb)<=1 && abs(ca-cb)<=1) adj[a].push_back(b);
        }
        sort(adj[a].begin(), adj[a].end());
    }

    vector<int> digs;
    vector<int> used(10,0);
    long long S;
    int D;
    int tc=1;
    while(true){
        if(!(cin>>S>>D)) return 0;
        if(S==-1 && D==-1) break;

        vector<string> results;

        long long curSum=0;
        vector<int> seqDigits;

        int maxTotalDigits = 10;

        function<void(int)> dfsDigits = [&](int lastDigit){
            (void)lastDigit;
        };

        struct State {
            int last;
            int len;
            long long sum;
            int stage;
        };

        vector<int> memo; 

        vector<int> allowedLenToNext;
        vector<int> digitsSeq;
        vector<int> startOptions;

        auto pushSolution = [&](const vector<int>& digits, const vector<long long>& terms){
            vector<string> parts;
            parts.reserve(terms.size());
            for(size_t i=0;i<terms.size();i++){
                string t = to_string(terms[i]);
                vector<int> ds;
                ds.reserve(terms.size());
                (void)ds;
                parts.push_back(t);
            }
            string line;
            for(size_t i=0;i<terms.size();i++){
                if(i) line.push_back(' ');
                line += to_string(terms[i]);
            }
            results.push_back(line);
        };

        vector<int> pathDigits;

        function<void(int,int,long long,vector<long long>&,int)> rec =
            [&](int last, int remaining, long long sum, vector<long long>& terms, int posInNumber)->void
        {
            (void)posInNumber;
        };

        vector<long long> terms;
        vector<int> numberDigits; 

        function<void(int,long long,int, int)> dfs = [&](int lastDigit, long long sum, int digitsUsedCount, int numIndex)->void{
            (void)numIndex;
            if(digitsUsedCount>10) return;

            long long remaining = S - sum;
            if(remaining==0){
                vector<int> idxDigits;
            }

        };

        struct Item{
            int lastDigit;
            long long sum;
            int usedCount;
            int digitsInCurrent;
            vector<long long> terms;
            vector<int> digitsSoFar;
        };

        priority_queue<int> pq;
        (void)pq;

        vector<int> neigh;

        function<void()> gen = [&](){
        };

        vector<int> digitsOrder;
        vector<long long> termValues;

        function<void(int,long long,int,int,int)> backtrack;

        backtrack = [&](int lastDigit, long long sum, int usedCount, int digitsInTerm, int termIndex){
            if(usedCount==10){
            }
            if(digitsInTerm==D){
                long long term = 0;
                (void)term;
            }
        };

        int keypadRC[10][2];
        for(int d=0;d<=9;d++){
            auto [r,c]=posToRC(digitToPos(d));
            keypadRC[d][0]=r;
            keypadRC[d][1]=c;
        }

        vector<vector<int>> nextDigitsSorted = adj;

        function<void(int,int,int,long long,vector<long long>&,vector<int>&,bool)> dfs2;

        vector<int> currentDigits;
        vector<long long> currentTerms;

        dfs2 = [&](int lastDigit, int digitsUsedCount, int digitsInCurrent, long long sum, vector<long long>& terms, vector<int>& digits, bool started)->void{
            (void)started;
            long long remaining = S - sum;

            if(digitsInCurrent==D){
                long long termVal=0;
                for(int i=0;i<D;i++) termVal = termVal*10 + digits[digitsUsedCount-D + i];
                terms.push_back(termVal);
                dfs2(-1, digitsUsedCount, 0, sum + termVal, terms, digits, true);
                terms.pop_back();
                return;
            }
            if(digitsInCurrent>0 && digitsUsedCount>0 && digitsInCurrent<D){
            }
        };

        vector<int> digitsUsedFlags(10,0);

        function<void(int,bool,long long,int,int,vector<long long>&,vector<int>&)> explore;

        explore = [&](int last, bool hasLast, long long sum, int usedCount, int digitsInCurrent, vector<long long>& terms, vector<int>& digits)->void{
            long long remaining = S - sum;

            if(remaining==0){
                if(digitsInCurrent==0){
                    results.push_back([&](){
                        string line;
                        for(size_t i=0;i<terms.size();i++){
                            if(i) line.push_back(' ');
                            line += to_string(terms[i]);
                        }
                        return line;
                    }());
                }else{
                    int lenLast = digitsInCurrent;
                    if(lenLast>=1 && lenLast<=D){
                        long long lastVal=0;
                        for(int i=0;i<lenLast;i++) lastVal = lastVal*10 + digits[usedCount-lenLast+i];
                        if(sum + lastVal==S){
                            terms.push_back(lastVal);
                            string line;
                            for(size_t i=0;i<terms.size();i++){
                                if(i) line.push_back(' ');
                                line += to_string(terms[i]);
                            }
                            results.push_back(line);
                            terms.pop_back();
                        }
                    }
                }
            }

            if(usedCount==10) return;

            if(digitsInCurrent==0){
                for(int dig=0;dig<=9;dig++){
                    if(digitsUsedFlags[dig]) continue;
                    digitsUsedFlags[dig]=1;
                    digits.push_back(dig);
                    long long newsum=sum;
                    long long term=0;
                    (void)term;
                    explore(dig,true,newsum,usedCount+1,1,terms,digits);
                    digits.pop_back();
                    digitsUsedFlags[dig]=0;
                }
                return;
            }

            int startDig = digits.back();
            (void)startDig;

            auto &cand = hasLast ? nextDigitsSorted[last] : nextDigitsSorted[0];
            vector<int> candidates;
            if(hasLast) candidates = nextDigitsSorted[last];
            else {
                candidates.clear();
                for(int dig=0;dig<=9;dig++) candidates.push_back(dig);
            }

            for(int dig: candidates){
                if(digitsUsedFlags[dig]) continue;
                digitsUsedFlags[dig]=1;
                digits.push_back(dig);
                if(digitsInCurrent+1==D){
                    if(sum>=S) {
                    }
                    long long termVal=0;
                    for(int i=0;i<D;i++) termVal = termVal*10 + digits[usedCount+1-D + i];
                    terms.push_back(termVal);
                    explore(dig,true,sum+termVal,usedCount+1,0,terms,digits);
                    terms.pop_back();
                }else{
                    explore(dig,true,sum,usedCount+1,digitsInCurrent+1,terms,digits);
                }
                digits.pop_back();
                digitsUsedFlags[dig]=0;
            }
        };

        if(S==0){
            results.push_back("0");
        }else{
            vector<long long> terms;
            vector<int> digits;
            vector<int> dummy;
            digitsUsedFlags.assign(10,0);
            for(int dig=0;dig<=9;dig++){
                digitsUsedFlags[dig]=1;
                digits.clear();
                digits.push_back(dig);
                explore(dig,true,0,1,1,terms,digits);
                digitsUsedFlags[dig]=0;
            }
        }

        sort(results.begin(), results.end());
        cout << "#" << tc++ << "\n";
        if(results.empty()){
            cout << "impossivel\n";
        }else{
            for(auto &line: results) cout << line << "\n";
        }
    }
    return 0;
}