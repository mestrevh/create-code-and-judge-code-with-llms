/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line, all;
    while (getline(cin, line)) {
        all += line + " ";
    }
    if (all.empty()) return 0;

    vector<int> nums;
    int target = 0;
    size_t i = 0;
    size_t n = all.size();
    size_t bracket_end = 0;

    while (i < n) {
        if (all[i] == '[') {
            i++;
            while (i < n && all[i] != ']') {
                if (isdigit(all[i]) || all[i] == '-') {
                    string s;
                    s += all[i++];
                    while (i < n && isdigit(all[i])) {
                        s += all[i++];
                    }
                    nums.push_back(stoi(s));
                } else {
                    i++;
                }
            }
            bracket_end = i;
            break;
        }
        i++;
    }

    size_t comma_pos = all.find(',', bracket_end);
    if (comma_pos != string::npos) {
        for (size_t j = comma_pos + 1; j < n; ++j) {
            if (isdigit(all[j]) || all[j] == '-') {
                string s;
                s += all[j++];
                while (j < n && isdigit(all[j])) {
                    s += all[j++];
                }
                target = stoi(s);
                break;
            }
        }
    }

    unordered_map<int, int> seen;
    for (int idx = 0; idx < (int)nums.size(); ++idx) {
        int complement = target - nums[idx];
        if (seen.find(complement) != seen.end()) {
            cout << "[" << seen[complement] << ", " << idx << "]" << endl;
            return 0;
        }
        seen[nums[idx]] = idx;
    }

    return 0;
}