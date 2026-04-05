/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    while ( (cin >> N >> P) ) {
        if (N == 0 && P == 0) break;

        vector<vector<int>> piles(P);
        vector<int> posBox(N + 1, -1), depth(N + 1, -1);
        for (int i = 0; i < P; i++) {
            int Qi; cin >> Qi;
            piles[i].resize(Qi);
            for (int j = 0; j < Qi; j++) {
                int x; cin >> x;
                piles[i][j] = x;
                posBox[x] = i;
                depth[x] = j;
            }
        }

        int b = posBox[1];
        int d = depth[1];

        vector<int> topHeight(P, 0);
        for (int i = 0; i < P; i++) topHeight[i] = (int)piles[i].size() - 1;

        vector<int> need(P, 0), doneNeed(P, 0);

        auto computeNeededForSide = [&](int dir)->int{
            int ans = 0;
            int idx = b + dir;
            int current = topHeight[b];
            while (0 <= idx && idx < P) {
                if (topHeight[idx] < d + (int)ans + 1) {
                    // still can remove without blocking, nothing required here
                }
                int localTop = topHeight[idx];
                int needAbove = max(0, (d - 1) - depth[1]); // always negative; ignore
                idx += dir;
            }
            return ans;
        };

        // Brute force greedy with state only on how many boxes removed above 1 in its pile:
        // Optimal strategy: remove boxes above 1 in pile b. Then 1 becomes top at level d.
        // However, to remove those above, each must have at least one free side.
        // Similarly, removing boxes in adjacent piles may be required to provide free side for the box currently on top.
        // This can be solved with dynamic programming on intervals around pile b.
        // Since N,P <= 1000, we can do O(P^2) per test.

        // Determine for each pile i the highest index of box that must remain (relative to 1's level d).
        // But boxes are unique, so we can reason by heights only.
        // Consider removing boxes from some piles down to certain heights.
        // To remove a box from pile i at height h (0-based), it is removable iff at least one side adjacent pile j
        // has height < h (no box adjacent at that height).
        // Since only removing from tops, pile heights only decrease.
        // For box 1: its height is d. It is removable iff after operations, at least one adjacent pile height < d.
        // For boxes above 1 in pile b at heights d+1..topHeight[b], when each becomes top in sequence,
        // at height k it is removable iff at least one of its adjacent pile heights < k at that time.
        // This implies we may need to decrease left/right piles below each k.
        // Optimal can be seen as choosing a direction to provide the free side at each k, leading to interval reduction.
        // We can model as follows:
        // Let hb = topHeight[b]. We need to remove boxes from hb down to d (inclusive? excluding 1).
        // When removing box at height k (k> d), we need min(height_left, height_right) < k.
        // Equivalently, it's enough that either left pile height < k or right pile height < k.
        // Since heights monotonically decrease, once a side is decreased below some threshold, it stays.
        // Therefore, for each side, we only need to reduce its height below some levels.
        // But reducing a side below level L might itself require further reductions further outward.
        // This forms propagation similar to clearing a "staircase" to create a free side.

        // DP on how far cleared on left/right at each required height level.
        // Key observation: to make pile x height < H, we must remove all boxes above H-1 in that pile.
        // But each removed box requires at least one side free, so clearance can propagate outward.
        // However, this propagation is identical to ensuring that along a chain, heights are strictly decreased.
        // We can simulate minimal boxes to clear each pile down to each possible height using BFS-like propagation.

        // We'll compute minimal removals for ensuring that for some side, all piles in an interval near b
        // are reduced to heights such that a "path" of free side exists.
        // For removing from pile b, we only need one side (left or right) to be free at each height k.
        // It is always optimal to commit to one side for all k? Not necessarily.
        // But we can allow switching: at some k, left becomes free, at higher k maybe right, etc.
        // With monotonic decrease, switching can only happen when we already lowered both sides enough for previous k.
        // Hence overall strategy corresponds to choosing a sequence of thresholds, but can be captured by DP over which side provides clearance at each stage.

        // We'll implement DP over interval [l,r] representing piles whose outer boundary provides a free side for current top removal.
        // Use known approach for 1D stacks with removable rule: minimal removals equals minimal number of boxes to make
        // either leftmost pile height < current or rightmost pile height < current, with propagation.
        // Given constraints, we can solve by shortest path on "frontier heights" using Dijkstra on piles boundaries.
        // Yet simpler: since only need retrieve inventory (box 1) and only removes count besides box 1,
        // and all boxes same format, minimal removals equals minimal number of boxes removed to make box 1 removable.
        // But boxes above 1 must also be removed, so those are included.

        // Model configuration by current heights after removals. Equivalent to we choose for each pile i a remaining height ri (-1 means empty).
        // Removability is possible iff there exists an order of removing from tops to reach those heights with rule.
        // For 1D with monotonic removal, reachability condition equals:
        // For every pile i, for each removed layer h > ri, the box at (i,h) must have adjacent at least one side with remaining height < h at time.
        // Since time can be scheduled, the condition reduces to existence of at least one direction from each removed layer to an empty space.
        // This is equivalent to graph reachability in "layer adjacency":
        // Build nodes (i,h) for each box originally at that layer; edges to adjacent layers (i-1,h) and (i+1,h).
        // A layer is removable if it has a free side, meaning path to boundary (outside interval) at same h through removed boxes.
        // The optimal reachability to remove a set of layers corresponds to making a connected region of removed boxes reaching outside at each relevant h.
        // For our goal, we only need removed boxes along a monotone frontier from pile b to some boundary at heights >= d.

        // Therefore minimal removals equals minimal number of boxes in a "staircase" region removed that connects the layers above 1 in pile b to outside,
        // counting all boxes in that region (excluding box 1).

        // We'll compute minimal cost to create a connection from (b,k) for all k in [d+1..hb] to outside by removing boxes.
        // Connection property in 2D grid (pile index vs height) with adjacency horizontally at same height, and removals allow deleting a cell if
        // there's a path from that cell to outside consisting of removed cells at same height. Since removal happens from top, it means removed cells
        // in each pile form a prefix from top downward (i.e., a set of highest layers removed).
        // That means for each pile i, if we remove down to height ri, all layers h > ri are removed, and layers h <= ri remain.
        // Connectivity from above requires that for each height level h we removed at (b,h), there exists a path across piles at that level
        // through piles where remaining height < h (so those cells are removed) to an outside boundary.

        // For a fixed remaining height array ri, box at (b,h) exists for h<=hb. It is removed if ri[b] < h.
        // For box layers above 1 in pile b to be removed: we need ri[b] = d (after removals, height of pile b becomes d, with box at d (=1) remaining).
        // So ri[b]=d. For any h> d, at level h, removed region includes all piles i with ri[i] < h.
        // Connectivity to outside for each h> d is required to be able to remove those layers.
        // But once for the highest layers, it implies for lower layers too? Connectivity to outside for all h> d is equivalent to
        // for each h> d, at level h, there must be a continuous gap to outside where ri[i] < h.
        // With monotonic heights, it's sufficient to ensure connectivity at level hb down to d+1; this implies for lower levels automatically because sets expand.
        // Specifically, if at level h the removed set includes piles with ri[i] < h. As h decreases, condition becomes easier (more piles satisfy ri[i]<h),
        // so connectivity persists. Thus we only need ensure connectivity for the highest level hb.
        // Also, to remove the box at height d+1 (the lowest above 1), connectivity at that level should hold; but since that's easier than at hb, it's implied.
        // Hence requirement reduces to: the cell (b,hb) must be removable, and all above are then removed with same region.
        // Additionally, after removing down to d, box 1 itself at height d must be removable: needs at least one adjacent pile remaining height < d.
        // That is also covered by outside connectivity at level d? Actually box 1 at height d needs free side from adjacent remaining heights < d.
        // That corresponds to level d+1 for its removal order? No. We'll handle separately: require min(remaining heights of neighbors) < d at final state.

        // So: find minimal number of boxes removed to achieve:
        // (1) Remaining height of pile b is exactly d.
        // (2) At level hb, there is a path from pile b to outside such that all piles along path have remaining height < hb.
        // Given piles are in a line, a path to outside means: either all piles from some boundary up to b have remaining height < hb,
        // i.e., either left side is cleared to < hb continuously until boundary, or right side, or combination via outside at ends.
        // In a line, to connect to outside at level hb, you need to choose either:
        // - clear a contiguous segment [L..b-1] with remaining height < hb up to left end (or until a pile not cleared breaks it).
        // Actually to reach outside, need a cleared contiguous region from b to an end: either go left all the way to pile 0, or go right all the way to pile P-1.
        // Because outside is beyond ends, only way is monotone in index. Therefore path exists iff either:
        // there exists t < b such that for all i in [t..b] remaining height < hb, with t=0 (end) because outside at left end means pile -1.
        // Similarly on right with end P-1.
        // But in 1D, a connection to outside at same height requires reaching end without crossing a remaining box.
        // That means all piles from some end up to b must satisfy remaining height < hb.
        // Specifically, either all piles i in [0..b-1] have remaining height < hb (go left to boundary), or all piles i in [b+1..P-1] have remaining height < hb (go right).
        // Or both if choose farther.
        // To minimize removals, choose the cheaper side to clear at level hb.

        // Then condition (2) for removing box 1: need at least one neighbor pile remaining height < d.
        // If we cleared left at level hb, that implies left piles have remaining heights < hb, but may still be >= d.
        // We'll compute minimal removals by considering clearance level needed on the chosen side to also free box 1.

        auto removedCost = [&](int side)->long long{
            // side = -1 means clear to left end, +1 clear to right end.
            // We'll set remaining height for piles on that side to be < hb, but can leave them down to some height >= d as long as connectivity at level hb holds.
            // For connectivity at level hb, each pile along path must have remaining height < hb => remaining height <= hb-1.
            // Minimal boxes removed for that is remove top layers above hb-1: i.e., reduce pile i to height hb-1 or lower, but can't be lower? cost increases if lower.
            // So set remaining heights for cleared side to exactly min(originalTopHeight, hb-1).
            // Also need box 1 removable: at least one neighbor (b-1 or b+1) has remaining height < d.
            // If cleared side is left, ensure pile b-1 remaining < d by possibly lowering it further.
            // Similar for right.

            long long cost = 0;
            int hb_local = hb;
            for (int i = 0; i < P; i++) {
                int keep = topHeight[i];
                if (i == b) keep = d; // keep box 1 at height d
                if (i == b) continue;
                if ((side==-1 && i < b) || (side==1 && i > b)) {
                    int target = min(topHeight[i], hb_local - 1);
                    // if need free for box 1 on neighbor
                    if (side==-1 && i == b-1) target = min(target, d-1);
                    if (side==1 && i == b+1) target = min(target, d-1);
                    if (target < 0) target = -1;
                    // boxes removed from pile i: those above target
                    cost += (long long)(topHeight[i] - target);
                } else {
                    // piles not on path remain unchanged
                    // but if i is on the other side of b, they don't need to be lowered for connectivity at hb.
                    // However, boxes above them might still be removed as part of process? We can avoid by not lowering.
                }
            }
            // But above formula doesn't remove boxes above 1 in pile b: those are topHeight[b]-d
            cost += (long long)(topHeight[b] - d);
            return cost;
        };

        long long best = (1LL<<60);

        // Option 1: connect via left end.
        if (b > 0) best = min(best, removedCost(-1));
        // Option 2: connect via right end.
        if (b < P-1) best = min(best, removedCost(1));

        // Edge case: if P==1, then no sides; but then box 1 is at some pile b=0 and can be removed only if no adjacent boxes exist:
        // With only one pile, both sides are free, so only need remove above it.
        if (P == 1) {
            best = topHeight[0] - d;
        }

        cout << best << "\n";
    }
    return 0;
}