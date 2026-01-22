/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int weight;
    float price;
    int serial_number;
};

int main() {
    int N, P;
    while (cin >> N >> P, N != -1) {
        vector<Product> products(N);
        vector<float> centers(P * 2);
        vector<vector<int>> deliveries(P);
        unordered_set<int> serials;
        
        for (int i = 0; i < P; i++) {
            cin >> centers[i * 2] >> centers[i * 2 + 1];
        }

        for (int i = 0; i < N; i++) {
            cin >> products[i].name >> products[i].weight >> products[i].price;
            int k = 0;
            while (true) {
                float rounded_price = ceil(products[i].price);
                products[i].serial_number = (rounded_price + i + products[i].weight + k) % N;
                if (serials.count(products[i].serial_number) == 0) {
                    serials.insert(products[i].serial_number);
                    break;
                }
                k++;
            }
        }

        sort(products.begin(), products.end(), [](const Product &a, const Product &b) {
            return a.name < b.name;
        });

        for (int i = 0; i < N; i++) {
            deliveries[products[i].serial_number].push_back(i);
        }

        float total_money = 0;
        int vehicle_position[P] = {0};

        int serial, x, y;
        while (cin >> serial && serial != -1) {
            cin >> x >> y;

            int closest_vehicle = -1;
            float min_distance = numeric_limits<float>::max();
            int product_index = -1;

            for (int i = 0; i < deliveries[serial].size(); i++) {
                int index = deliveries[serial][i];
                float distance = sqrt(pow(x - centers[i * 2], 2) + pow(y - centers[i * 2 + 1], 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_vehicle = i;
                    product_index = index;
                }
            }

            total_money += products[closest_vehicle].price;
            vehicle_position[closest_vehicle] = closest_vehicle;

            cout << "delivered " << products[product_index].name << " s. " 
                 << products[product_index].serial_number << " by vehicle " << (closest_vehicle + 1) << endl;
        }

        cout << "Thank you for using this service. Bye!" << endl;
    }
    return 0;
}
