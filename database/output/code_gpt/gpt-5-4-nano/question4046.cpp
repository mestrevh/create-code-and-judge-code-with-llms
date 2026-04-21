/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<long long> extractNumbers(const string& s) {
    vector<long long> nums;
    long long cur = 0;
    bool in = false;
    for(char c : s){
        if(c >= '0' && c <= '9'){
            cur = cur * 10 + (c - '0');
            in = true;
        }else{
            if(in){
                nums.push_back(cur);
                cur = 0;
                in = false;
            }
        }
    }
    if(in) nums.push_back(cur);
    return nums;
}

static long long extractTotalSum(const string& s){
    long long sum = 0;
    long long cur = 0;
    bool in = false;
    for(char c : s){
        if(c >= '0' && c <= '9'){
            cur = cur * 10 + (c - '0');
            in = true;
        }else{
            if(in){
                sum += cur;
                cur = 0;
                in = false;
            }
        }
    }
    if(in) sum += cur;
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    long long totalSum = 0;

    long long cnt[26] = {0};
    bool seenLetter[26] = {false};

    while(true){
        if(!std::getline(cin, line)) break;
        totalSum += extractTotalSum(line);
        for(char c : line){
            if(c >= 'a' && c <= 'z'){
                cnt[c - 'a']++;
                seenLetter[c - 'a'] = true;
            }else if(c >= 'A' && c <= 'Z'){
                cnt[c - 'A']++;
                seenLetter[c - 'A'] = true;
            }
        }
    }

    string first;
    for(int i=0;i<26;i++){
        if(cnt[i] > 0){
            for(int j=0;j<26;j++){
                if(cnt[j] > 0){
                    for(int k=0;k<26;k++){
                        if(cnt[k] > 0){
                            first.push_back(char('a' + i));
                            first.push_back(char('a' + j));
                            first.push_back(char('a' + k));
                        }
                    }
                }
            }
        }
    }

    cout << "eh... parece que Rebeka continua pobre e atras das grades\n";
    cout << "Rebeka agora esta livre! A senha da cela eh " << totalSum << "\n";
    return 0;
}