/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>

struct ItemInput {
    std::string name;
    long long weight;
    double price;
};

struct Item {
    std::string name;
    double price;
    int center_id;
};

struct Point {
    double x, y;
};

bool compareItems(const ItemInput& a, const ItemInput& b) {
    return a.name < b.name;
}

double distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, P;
    std::cin >> N >> P;

    std::vector<Point> centers(P);
    for (int i = 0; i < P; ++i) {
        std::cin >> centers[i].x >> centers[i].y;
    }

    std::vector<ItemInput> items_input(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> items_input[i].name >> items_input[i].weight >> items_input[i].price;
    }

    std::sort(items_input.begin(), items_input.end(), compareItems);

    std::vector<Item> inventory(N);
    std::vector<bool> serial_used(N, false);

    for (int i = 0; i < N; ++i) {
        long long alpha_pos = i;
        long long weight = items_input[i].weight;
        double price = items_input[i].price;

        long long base_calc = static_cast<long long>(ceil(price)) + alpha_pos + weight;
        long long k = 0;
        
        while (true) {
            int sn = (base_calc + k) % N;
            if (!serial_used[sn]) {
                serial_used[sn] = true;
                inventory[sn].name = items_input[i].name;
                inventory[sn].price = items_input[i].price;
                break;
            }
            k++;
        }
    }

    int items_per_center = N / P;
    for (int sn = 0; sn < N; ++sn) {
        inventory[sn].center_id = sn / items_per_center;
    }

    std::vector<Point> vehicle_pos = centers;
    
    int ordered_serial;
    while (std::cin >> ordered_serial && ordered_serial != -1) {
        double delivery_x, delivery_y;
        std::cin >> delivery_x >> delivery_y;
        Point delivery_point = {delivery_x, delivery_y};

        int item_center_id = inventory[ordered_serial].center_id;
        Point item_center_loc = centers[item_center_id];

        double min_dist_sq = std::numeric_limits<double>::max();
        int chosen_vehicle_id = -1;

        for (int i = 0; i < P; ++i) {
            double d_sq = distSq(vehicle_pos[i], item_center_loc);
            if (d_sq < min_dist_sq) {
                min_dist_sq = d_sq;
                chosen_vehicle_id = i;
            }
        }

        vehicle_pos[chosen_vehicle_id] = delivery_point;

        std::cout << "delivered " << inventory[ordered_serial].name 
                  << " s. " << ordered_serial 
                  << " by vehicle " << chosen_vehicle_id + 1 << "\n";
    }

    std::cout << "Thank you for using this service. Bye!\n";

    return 0;
}
