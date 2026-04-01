/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int path_count = 0;
    int best_path = -1;
    double max_dist = -1.0;

    while (cin >> s) {
        if (s == "[") {
            path_count++;
            double current_dist = 20.0;
            double total_time = 0.0;
            bool is_caught = false;

            while (cin >> s && s != "]") {
                if (is_caught) continue;

                if (s == "C") {
                    current_dist += 15.0;
                } else if (s == "T") {
                    current_dist += 30.0;
                } else {
                    try {
                        double t = stod(s);
                        
                        // Phase 1: speed is 1 m/s up to total_time = 20s
                        if (total_time < 20.0) {
                            double dt = min(t, 20.0 - total_time);
                            current_dist -= dt * 1.0;
                            if (current_dist <= 0.0) {
                                is_caught = true;
                            }
                            total_time += dt;
                            t -= dt;
                        }
                        
                        // Phase 2: speed is 3 m/s after total_time = 20s
                        if (!is_caught && t > 0.0) {
                            current_dist -= t * 3.0;
                            if (current_dist <= 0.0) {
                                is_caught = true;
                            }
                            total_time += t;
                        }
                    } catch (...) {
                        // Skip any non-numeric and non-action tokens
                    }
                }
            }

            // Path is only valid if Tarzan was never caught and distance ends > 0
            if (!is_caught && current_dist > 0.0) {
                // If this path's final distance is greater than the previous best, update
                if (current_dist > max_dist) {
                    max_dist = current_dist;
                    best_path = path_count;
                }
            }
        }
    }

    if (best_path != -1) {
        cout << "Tarzan fugir caminho " << best_path << endl;
    } else {
        cout << "UoooooOOooOOooooo UooooOOooOOooo" << endl;
    }

    return 0;
}