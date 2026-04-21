/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }
    
    int total = 0;
    int max_height = *max_element(heights.begin(), heights.end());
    
    for (int h = 1; h <= max_height; ++h) {
        bool in_water = false;
        for (int i = 0; i < N; ++i) {
            if (heights[i] < h) {
                in_water = true;
            } else if (in_water) {
                total++;
                in_water = false;
            }
        }
    }
    
    cout << total << endl;
    return 0;
}