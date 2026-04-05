/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<int> mergeStable(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    res.reserve(a.size() + b.size());
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    return res;
}

static vector<int> mergeSort(const vector<int>& v) {
    if (v.size() <= 1) return v;
    size_t mid = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeStable(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    string line;
    getline(cin, line);

    for (int k = 0; k < N; k++) {
        vector<int> arr;
        while (true) {
            if (!getline(cin, line)) line.clear();
            bool hasNumber = false;
            string s = line;
            size_t pos = 0;
            while (pos < s.size()) {
                while (pos < s.size() && isspace((unsigned char)s[pos])) pos++;
                if (pos >= s.size()) break;
                bool neg = false;
                if (s[pos] == '-') { neg = true; pos++; }
                if (pos >= s.size() || !isdigit((unsigned char)s[pos])) break;
                long long val = 0;
                while (pos < s.size() && isdigit((unsigned char)s[pos])) {
                    val = val * 10 + (s[pos] - '0');
                    pos++;
                }
                if (neg) val = -val;
                arr.push_back((int)val);
                hasNumber = true;
                while (pos < s.size() && !isdigit((unsigned char)s[pos]) && s[pos] != '-') {
                    if (!isspace((unsigned char)s[pos])) break;
                    pos++;
                }
                if (pos < s.size() && (s[pos] == ',')) pos++;
                if (pos < s.size() && s[pos] == ',') pos++;
            }
            if (hasNumber) break;
            if (k + 1 <= N && cin.eof()) break;
        }

        arr = mergeSort(arr);

        for (size_t i = 0; i < arr.size(); i++) {
            if (i) cout << ' ';
            cout << arr[i];
        }
        if (k + 1 < N) cout << '\n';
    }

    return 0;
}