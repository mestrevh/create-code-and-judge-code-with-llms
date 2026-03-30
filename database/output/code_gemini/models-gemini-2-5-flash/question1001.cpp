/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility> // For std::pair

// Function to calculate wrap-around coordinates for a toroidal grid.
// Handles negative results from the % operator in C++ for negative `coord`.
int wrap(int coord, int dim) {
    return (coord % dim + dim) % dim;
}

// Function to print the current state of the grid.
// '1' indicates a ship, '0' indicates an empty cell.
void print_grid(int N, int M, const std::vector<std::pair<int, int>>& ships) {
    // Initialize a 2D grid with all cells empty (0)
    std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));

    // Place '1' at each ship's position
    for (const auto& p : ships) {
        // The coordinates should already be wrapped, but this check ensures they are within bounds
        if (p.first >= 0 && p.first < N && p.second >= 0 && p.second < M) {
            grid[p.first][p.second] = 1;
        }
    }

    // Print the grid
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << grid[i][j] << (j == M - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M; // Dimensions of the matrix (N rows, M columns)
    std::cin >> N >> M;

    int K; // Initial number of ships
    std::cin >> K;

    // Vector to store the current positions of all active ships.
    // Each position is a pair {row, column}.
    std::vector<std::pair<int, int>> ships;
    ships.reserve(K); // Pre-allocate memory for efficiency

    // Read initial ship coordinates
    for (int i = 0; i < K; ++i) {
        int r, c;
        std::cin >> r >> c;
        ships.push_back({r, c});
    }

    // Print the initial state of the fleet
    print_grid(N, M, ships);

    int H, B; // H = number of hours (attacks), B = number of bombs per attack
    std::cin >> H >> B;

    // Define relative coordinates for the 5 cells affected by a bomb:
    // {0, 0}   -> The bomb's direct target (x, y)
    // {1, 1}   -> Diagonal: (x+1, y+1)
    // {1, -1}  -> Diagonal: (x+1, y-1)
    // {-1, -1} -> Diagonal: (x-1, y-1)
    // {-1, 1}  -> Diagonal: (x-1, y+1)
    int d_bomb_x[] = {0, 1, 1, -1, -1};
    int d_bomb_y[] = {0, 1, -1, -1, 1};

    // Simulate each hour of attacks and movements
    for (int hour = 0; hour < H; ++hour) {
        std::cout << "\n"; // Print a separator newline before each hour's output grid

        // Step 1: Determine all cells that will be destroyed by bombs in this hour.
        // This is a temporary grid to mark destroyed locations, reset each hour.
        std::vector<std::vector<bool>> destroyed_this_hour(N, std::vector<bool>(M, false));

        for (int b_idx = 0; b_idx < B; ++b_idx) {
            int bx, by; // Read current bomb's coordinate
            std::cin >> bx >> by;
            
            // Apply the bomb's destruction pattern to the `destroyed_this_hour` grid
            for (int i = 0; i < 5; ++i) {
                int affected_x = wrap(bx + d_bomb_x[i], N);
                int affected_y = wrap(by + d_bomb_y[i], M);
                destroyed_this_hour[affected_x][affected_y] = true;
            }
        }

        // Step 2: Process ships based on bombardment and then move surviving ships.
        std::vector<std::pair<int, int>> next_hour_ships;
        next_hour_ships.reserve(ships.size()); // Pre-allocate memory for efficiency

        for (const auto& ship_current_pos : ships) {
            int sx = ship_current_pos.first;
            int sy = ship_current_pos.second;

            // Check if the ship's current position was hit by any bomb
            if (!destroyed_this_hour[sx][sy]) {
                // The ship survived the bombardment. Now calculate its new position due to movement.
                // Ships move to their "diagonal superior direita" (top-right diagonal): (x-1, y+1)
                int new_sx = wrap(sx - 1, N);
                int new_sy = wrap(sy + 1, M);
                next_hour_ships.push_back({new_sx, new_sy});
            }
        }
        
        // Update the main `ships` vector with the new state for the next hour's simulation.
        ships = next_hour_ships;

        // Print the grid showing the fleet's state after this hour's attacks and movements.
        print_grid(N, M, ships);
    }

    return 0;
}