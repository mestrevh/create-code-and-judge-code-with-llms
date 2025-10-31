/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <limits>

struct Point {
    double x, y;
    char name;
};

double distSq(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Point robot;
    std::cin >> robot.x >> robot.y;

    std::vector<Point> targets(3);
    char current_name = 'A';
    for (int i = 0; i < 3; ++i) {
        std::cin >> targets[i].x >> targets[i].y;
        targets[i].name = current_name++;
    }

    for (int i = 0; i < 3; ++i) {
        int best_index = 0;
        for (int j = 1; j < targets.size(); ++j) {
            double dist_best = distSq(robot, targets[best_index]);
            double dist_curr = distSq(robot, targets[j]);
            
            const double epsilon = 1e-9;

            if (dist_curr < dist_best - epsilon) {
                best_index = j;
            } else if (std::abs(dist_curr - dist_best) < epsilon) {
                if (targets[j].name < targets[best_index].name) {
                    best_index = j;
                }
            }
        }

        std::cout << targets[best_index].name << (i == 2 ? "" : " ");
        robot = targets[best_index];
        targets.erase(targets.begin() + best_index);
    }

    std::cout << std::endl;

    return 0;
}
