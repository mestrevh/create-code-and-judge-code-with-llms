/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (!getline(cin, s1)) return 0;
    if (!getline(cin, s2)) s2.clear();

    auto parseNums = [&](const string& line) -> vector<long long> {
        vector<long long> nums;
        long long sign = 1, val = 0;
        bool inNum = false;
        bool neg = false;
        for (size_t i = 0; i < line.size(); i++) {
            char c = line[i];
            if (c == '-') {
                if (!inNum) {
                    inNum = true;
                    neg = true;
                    val = 0;
                    sign = -1;
                }
            } else if (c >= '0' && c <= '9') {
                if (!inNum) {
                    inNum = true;
                    neg = false;
                    val = 0;
                    sign = 1;
                }
                val = val * 10 + (c - '0');
            } else {
                if (inNum) {
                    nums.push_back(sign * val);
                    inNum = false;
                    val = 0;
                    sign = 1;
                }
            }
        }
        if (inNum) nums.push_back(sign * val);
        return nums;
    };

    vector<long long> nums = parseNums(s1);

    long long target = 0;
    {
        string tmp = s2;
        if (tmp.find_first_of("0123456789-") != string::npos) {
            size_t pos = tmp.find_first_of("0123456789-");
            size_t i = pos;
            long long sign = 1;
            if (tmp[i] == '-') { sign = -1; i++; }
            long long val = 0;
            while (i < tmp.size() && isdigit((unsigned char)tmp[i])) {
                val = val * 10 + (tmp[i] - '0');
                i++;
            }
            target = sign * val;
        } else {
            size_t pos = s1.find_first_of("0123456789-");
            if (pos != string::npos) {
                string all = s1 + " " + s2;
                pos = all.find_last_of("0123456789-");
            }
        }
    }

    unordered_map<long long, int> pos;
    for (int i = 0; i < (int)nums.size(); i++) {
        long long need = target - nums[i];
        auto it = pos.find(need);
        if (it != pos.end()) {
            cout << "[" << it->second << ", " << i << "]";
            return 0;
        }
        pos[nums[i]] = i;
    }

    return 0;
}