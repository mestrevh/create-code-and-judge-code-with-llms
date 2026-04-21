/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long digitSum(long long x){
    long long s = 0;
    while(x > 0){
        s += x % 10;
        x /= 10;
    }
    return s;
}

static bool isPrime(long long x){
    if(x < 2) return false;
    if(x % 2 == 0) return x == 2;
    for(long long i = 3; i*i <= x; i += 2)
        if(x % i == 0) return false;
    return true;
}

static int scoreFromValue(long long value){
    long long ds = digitSum(llabs(value));
    long long c = 0;
    long long n = llabs(value);
    for(long long i = 1; i*i <= n; i++){
        if(n % i == 0){
            c++;
            if(i*i != n) c++;
        }
    }
    long long x = c + ds;
    return (x % 2 == 0) ? 1 : 0;
}

static long long teamAdjustment(long long sumScore){
    if(isPrime(sumScore + 0) && (sumScore % 2 == 0)){
        return -4;
    }
    if(isPrime(sumScore + 0) && (sumScore % 2 != 0)){
        return 3;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;

    long long teamA = 0, teamB = 0;

    for(int i = 0; i < N; i++){
        long long A, B;
        cin >> A >> B;
        teamA += scoreFromValue(A);
        teamB += scoreFromValue(B);
    }

    teamA += teamAdjustment(teamA);
    teamB += teamAdjustment(teamB);

    if(teamA == teamB){
        teamA += 1;
    }

    cout << "Quem ganhou foi aquele time.\n";
    cout << llabs(teamA - teamB) << "\n";
    return 0;
}