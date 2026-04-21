/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long sumFloors = 0;
    for (long long i = 0; i < N; i++) {
        long long x;
        while (cin >> x) {
            if (x == 0) break;
            long long n = x;
            long long total = 0;
            while (cin >> x) {
                if (x == 0) break;
                total += x;
            }
            n = n; 
        }
    }

    cin.clear();
    cin.seekg(0);
    long long x, n;
    cin >> N;
    for (long long i = 0; i < N; i++) {
        long long first;
        cin >> first;
        if (first == 0) {
            continue;
        }
        vector<long long> nums;
        nums.push_back(first);
        while (cin >> x) {
            if (x == 0) break;
            nums.push_back(x);
        }
        long long sum = 0;
        for (long long v : nums) sum += v;
        long long count = (long long)nums.size();
        long long nlocal = nums[0];
        long long avg_floor = sum / nlocal;
        sumFloors += avg_floor;
    }

    cout << "Elas beberam " << sumFloors << " taças!" << "\n";
    return 0;
}