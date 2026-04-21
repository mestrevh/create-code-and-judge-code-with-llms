/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    int time;
    string cat;
    int order;
    Item* prevExtra = nullptr;
    bool hasTimeCat = false;
};

static int catRank(const string& c){
    if(c=="Bebida") return 0;
    if(c=="Acompanhamento") return 1;
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if(!(cin >> M)) return 0;

    vector<vector<Item>> actual(M+1);
    vector<int> totalOrders(M+1,0);
    vector<int> correctOrders(M+1,0);
    vector<vector<string>> extraNames(M+1);

    int globalOrder = 0;

    vector<deque<string>> pendingPrev; 
    pendingPrev.resize(M+1);

    vector<vector<string>> deliveredNames(M+1);

    for(int i=1;i<=M;i++){
        int P;
        cin >> P;
        totalOrders[i]=P;
        vector<Item> items;
        items.reserve(P);

        for(int k=1;k<=P;k++){
            string Pi;
            cin >> ws;
            getline(cin, Pi, '\n');
            while(Pi.size()==0){
                if(!cin) break;
                getline(cin, Pi, '\n');
            }
            if(Pi.empty()) { k--; continue; }

            string name = Pi;
            if(k<=P){
                bool hasExtra = false;
                if(k%3==0){
                    pendingPrev[i].push_back(name);
                    hasExtra = true;
                }

                if(hasExtra){
                    Item it;
                    it.name = name;
                    it.order = globalOrder++;
                    it.hasTimeCat = false;
                    items.push_back(it);
                } else {
                    int Ti; string Ci;
                    {
                        cin.clear();
                        if(!(cin >> ws)) {}
                    }
                    cin >> Ti >> Ci;
                    Item it;
                    it.name = name;
                    it.time = Ti;
                    it.cat = Ci;
                    it.order = globalOrder++;
                    it.hasTimeCat = true;
                    items.push_back(it);
                }
            }
        }
        actual[i] = items;
    }

    vector<deque<string>> stolenFromNext(M+2);
    vector<deque<string>> pendingForThis(M+2);

    for(int i=1;i<=M;i++){
        int P = totalOrders[i];
        vector<string> prevExtra;
        prevExtra.clear();
        if(i==1){
            ;
        }
        int stealCount = 0;
        for(int k=1;k<=P;k++){
            if(k%3==0){
                stealCount++;
            }
        }
        if(stealCount>0){
            deque<string> dq;
            for(int k=1;k<=P;k++){
                if(k%3==0){
                    dq.push_back(actual[i][k-1].name);
                }
            }
            stolenFromNext[i+1] = dq;
        }
    }

    vector<vector<string>> prevExtras(M+1);
    for(int i=1;i<=M;i++){
        if(i>1){
            prevExtras[i] = stolenFromNext[i];
        }
    }

    int totalDeliveredCorrect = 0;
    int totalDeliveredAll = 0;

    for(int i=1;i<=M;i++){
        vector<string> currentExtraPrev = prevExtras[i];

        vector<Item> known;
        vector<Item> unknown;
        for(auto &it : actual[i]){
            if(it.hasTimeCat) known.push_back(it);
            else unknown.push_back(it);
        }

        vector<Item> beverages, acomp, dessert;
        for(auto &it : known){
            int r = catRank(it.cat);
            if(r==0) beverages.push_back(it);
            else if(r==1) acomp.push_back(it);
            else dessert.push_back(it);
        }

        auto comp = [&](const Item& a, const Item& b){
            if(a.time != b.time) return a.time < b.time;
            return a.order < b.order;
        };
        sort(beverages.begin(), beverages.end(), comp);
        sort(acomp.begin(), acomp.end(), comp);
        sort(dessert.begin(), dessert.end(), comp);

        vector<string> delivered;
        vector<string> orderPrev;
        orderPrev = currentExtraPrev;

        for(auto &it : beverages) delivered.push_back(it.name);
        for(auto &it : acomp) delivered.push_back(it.name);
        for(auto &it : dessert) delivered.push_back(it.name);
        for(auto &s : orderPrev) delivered.push_back(s);

        deliveredNames[i]=delivered;

        int n = (int)delivered.size();
        totalDeliveredAll += n;

        unordered_map<string,int> countInOrder;
        for(int j=0;j<(int)actual[i].size();j++){
            if(actual[i][j].hasTimeCat) countInOrder[actual[i][j].name]++;
            else countInOrder[actual[i][j].name]++;
        }

        int correct = 0;
        vector<string> originalNames;
        originalNames.reserve(totalOrders[i]);
        for(int j=0;j<(int)actual[i].size();j++){
            originalNames.push_back(actual[i][j].name);
        }

        unordered_map<string,int> freqOriginal;
        for(auto &s: originalNames) freqOriginal[s]++;

        for(auto &s: delivered){
            auto it = freqOriginal.find(s);
            if(it!=freqOriginal.end() && it->second>0){
                correct++;
                it->second--;
            }
        }

        totalDeliveredCorrect += correct;
        correctOrders[i]=correct;
    }

    double p = 0.0;
    if(totalDeliveredAll>0) p = 100.0 * (double)totalDeliveredCorrect / (double)totalDeliveredAll;

    for(int i=1;i<=M;i++){
        cout << "Mesa " << i << ":";
        for(int j=0;j<(int)deliveredNames[i].size();j++){
            cout << (j==0 ? " " : ", ");
            cout << deliveredNames[i][j];
        }
        cout << "\n";
    }

    if(p < 70.0){
        cout << "Eu preciso esquecer o Ross, vou ligar pra ele e falar que eu o superei.\n";
    } else if(p < 85.0){
        cout << "Not bad, e so um trabalho temporario mesmo.\n";
    } else {
        cout << "That's what I call closure, Ross!\n";
    }

    return 0;
}