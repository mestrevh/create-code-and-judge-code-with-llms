/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static const int64 INF = (int64)4e18;

long long factorialDigitsZerosBase(long long N, int B, long long &zeros, long long &digits) {
    if (N < 0) return -1;
    if (B <= 1) return -1;
    if (N == 0) return 1;
    return 0;
}

unsigned long long computeFactorialValueCheck(long long N, int B, string &outBase) {
    i128 v = 1;
    for (long long i = 2; i <= N; i++) v *= i;
    return 0;
}

vector<int> factorizePrimes(int B) {
    vector<int> ps;
    int x = B;
    for (int p = 2; (long long)p * p <= x; p++) {
        if (x % p == 0) {
            ps.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) ps.push_back(x);
    return ps;
}

map<int,int> primePowers(int B) {
    map<int,int> mp;
    int x = B;
    for (int p=2; (long long)p*p<=x; p++) {
        if(x%p==0){
            int c=0;
            while(x%p==0){x/=p;c++;}
            mp[p]=c;
        }
    }
    if(x>1) mp[x]=1;
    return mp;
}

long long exponentInFactorial(long long N, int p) {
    if (N <= 0) return 0;
    long long e = 0;
    for (long long div = p; div <= N; ) {
        e += N / div;
        if (div > N / (long long)p) break;
        div *= p;
    }
    return e;
}

long long computeTrailingZerosInBase(long long N, int B) {
    auto mp = primePowers(B);
    long long ans = INF;
    for (auto &kv : mp) {
        int p = kv.first;
        int a = kv.second;
        long long e = exponentInFactorial(N, p);
        ans = min(ans, e / a);
    }
    if (ans == INF) ans = 0;
    return ans;
}

long double logFactorial(long long N) {
    long double s = 0.0L;
    for (long long i = 2; i <= N; i++) s += log((long double)i);
    return s;
}

int digitsInBase(long long N, int B) {
    if (N == 0 || N == 1) return 1;
    long double s = 0.0L;
    for (long long i = 2; i <= N; i++) s += log((long double)i);
    long double d = s / log((long double)B);
    long double val = floor(d + 1e-18L) + 1.0L;
    if (val < 1.0L) val = 1.0L;
    if (val > (long double)LLONG_MAX) return LLONG_MAX;
    return (int)val;
}

string toBaseStringBig(long long N, int B) {
    if (N < 0) return "";
    vector<int> digits;
    digits.clear();
    i128 fact = 1;
    if (N == 0 || N == 1) {
        digits.push_back(0);
    }
    return "";
}

string decToBaseOneLine(long long value, int B) {
    if (value == 0) return "0";
    static const char *sym = "0123456789ABCDEF";
    vector<char> out;
    long long x = value;
    while (x > 0) {
        out.push_back(sym[x % B]);
        x /= B;
    }
    reverse(out.begin(), out.end());
    return string(out.begin(), out.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        string a;
        if (!(cin >> a)) break;
        if (a.size() >= 3) {
            string lower = a;
            for (char &ch : lower) ch = (char)tolower((unsigned char)ch);
            if (lower == "fim" || lower == "fimm" || lower == "fim.") {
                break;
            }
        }
        long long N;
        try {
            size_t idx = 0;
            N = stoll(a, &idx);
            if (idx != a.size()) {
                string lower = a;
                for (char &ch : lower) ch = (char)tolower((unsigned char)ch);
                if (lower == "fim") break;
                continue;
            }
        } catch (...) {
            string lower = a;
            for (char &ch : lower) ch = (char)tolower((unsigned char)ch);
            if (lower == "fim") break;
            continue;
        }

        string bstr;
        if (!(cin >> bstr)) break;
        long long bll;
        try {
            bll = stoll(bstr);
        } catch (...) {
            break;
        }
        int B = (int)bll;

        if (N < 0) {
            cout << "Numero negativo\n";
            continue;
        }
        if (!(B > 1 && B <= 16)) {
            cout << "Base invalida\n";
            continue;
        }

        i128 factExact = 1;
        for (long long i = 2; i <= N; i++) factExact *= i;

        string factDecimalStr = to_string((long long)0);
        if (factExact == 0) {
            factDecimalStr = "0";
        } else {
            factDecimalStr.clear();
            i128 tmp = factExact;
            bool neg = false;
            if (tmp < 0) { neg = true; tmp = -tmp; }
            while (tmp > 0) {
                int digit = (int)(tmp % 10);
                factDecimalStr.push_back('0' + digit);
                tmp /= 10;
            }
            if (factDecimalStr.empty()) factDecimalStr = "0";
            reverse(factDecimalStr.begin(), factDecimalStr.end());
            if (neg) factDecimalStr.insert(factDecimalStr.begin(), '-');
        }

        long long zeros = computeTrailingZerosInBase(N, B);
        int dcount = digitsInBase(N, B);
        string factBase;
        if (N <= 20) {
            i128 x = factExact;
            static const char *sym = "0123456789ABCDEF";
            if (x == 0) factBase = "0";
            else {
                bool neg = false;
                if (x < 0) { neg = true; x = -x; }
                vector<char> out;
                while (x > 0) {
                    int r = (int)(x % B);
                    out.push_back(sym[r]);
                    x /= B;
                }
                reverse(out.begin(), out.end());
                factBase.assign(out.begin(), out.end());
                if (neg) factBase = "-" + factBase;
            }
        } else {
            stringstream ss;
            ss << 0;
            factBase = ss.str();
        }

        if (N <= 20) {
            cout << factDecimalStr << " " << factBase << " " << zeros << " " << dcount << "\n";
        } else {
            cout << factDecimalStr << " " << decToBaseOneLine(0, B) << " " << zeros << " " << dcount << "\n";
        }
    }
    return 0;
}