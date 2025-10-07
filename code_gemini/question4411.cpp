/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    string nums_str = input.substr(1, input.find("]") - 1);
    string target_str = input.substr(input.find("]") + 2);

    int target = stoi(target_str);

    vector<int> nums;
    string delimiter = ", ";
    size_t pos = 0;
    string token;
    while ((pos = nums_str.find(delimiter)) != string::npos) {
        token = nums_str.substr(0, pos);
        nums.push_back(stoi(token));
        nums_str.erase(0, pos + delimiter.length());
    }
    nums.push_back(stoi(nums_str));

    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            cout << "[" << numMap[complement] << ", " << i << "]" << endl;
            return 0;
        }
        numMap[nums[i]] = i;
    }

    return 0;
}
