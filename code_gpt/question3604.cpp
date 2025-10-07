/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    
    vector<int> arr;
    int num;
    istringstream iss(line);
    while (iss >> num) {
        arr.push_back(num);
    }
    
    int n = arr.size();
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    double mean = (min_val + max_val) / 2.0;
    
    int median_index = -1;
    double min_diff = numeric_limits<double>::max();
    
    for (int i = 0; i < n; i++) {
        double diff = abs(arr[i] - mean);
        if (diff < min_diff) {
            min_diff = diff;
            median_index = i;
        }
    }
    
    int pivot = arr[median_index];
    vector<int> left, right;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) {
            left.push_back(arr[i]);
        } else if (arr[i] > pivot) {
            right.push_back(arr[i]);
        }
    }
    
    cout << pivot << endl;
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    
    for (int i = 0; i < left.size(); i++) {
        cout << left[i] << (i < left.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}
