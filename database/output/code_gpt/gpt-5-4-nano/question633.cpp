/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FileInfo {
    long long sizeKb;
};

static long long parseSizeToKb(const string& s) {
    string t = s;
    long long x = 0;
    int i = 0;
    while (i < (int)t.size() && isdigit((unsigned char)t[i])) {
        x = x * 10 + (t[i] - '0');
        i++;
    }
    string unit = t.substr(i);
    long long mult = 1;
    if (unit == "Kb") mult = 1;
    else if (unit == "Mb") mult = 1024;
    else if (unit == "Gb") mult = 1024LL * 1024LL;
    else mult = 1;
    return x * mult;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ) {
        if (N == 0) break;

        string discStr;
        cin >> discStr;
        long long D = parseSizeToKb(discStr);

        map<string, FileInfo> files;
        vector<long long> freeSegs; 
        vector<long long> fileSegs; 
        // We'll represent disk as ordered segments: file sizes in order, then one free at end.
        // But optimization compacts, so after each optimize we can rebuild as all files in order and free at end.
        // For allocation, we must place in beginning of smallest free block that fits; free blocks exist only after removals.
        // We'll maintain list of segments with free/file status and sizes in Kb, in order.
        // N up to 10000, fragmentation can grow; but optimize can merge.
        // We'll use deque-like vector and do linear scans which should be ok in practice with constraints.
        struct Seg { long long len; bool free; };
        vector<Seg> segs;
        segs.push_back({D, true});

        bool error = false;

        auto normalizeAfterOptimize = [&]() {
            // Merge adjacent free segments already possible; but we'll actually compact files to start preserving order.
            vector<long long> sizes;
            for (auto &sg : segs) if (!sg.free) sizes.push_back(sg.len);
            segs.clear();
            long long used = 0;
            for (auto len : sizes) { segs.push_back({len, false}); used += len; }
            segs.push_back({D - used, true});
        };

        auto mergeAdjacent = [&]() {
            vector<Seg> ns;
            for (auto &sg : segs) {
                if (!ns.empty() && ns.back().free == sg.free) ns.back().len += sg.len;
                else ns.push_back(sg);
            }
            segs.swap(ns);
        };

        auto removeFile = [&](const string& name) {
            auto it = files.find(name);
            if (it == files.end()) return;
            long long sz = it->second.sizeKb;
            files.erase(it);
            for (int idx = 0; idx < (int)segs.size(); idx++) {
                if (!segs[idx].free && segs[idx].len == sz) {
                    // Need ensure it is the correct file block, but if multiple equal sizes exist, ambiguous.
                    // We'll locate by comparing sizes might remove wrong one. So we must track positions.
                    break;
                }
            }
        };

        // Better: maintain mapping from filename to segment index and size (since segment indices shift on inserts/removes/optimize).
        // We'll use list of segments and update indices via pointers? too heavy.
        // Simpler: each file block is unique and we can store its current segment position via an iterator in list.
        // Use std::list for stable iterators.
        struct Node { long long len; bool free; string name; };
        list<Node> disk;
        for (int i=0;i<1;i++) disk.push_back({D,true,""});

        map<string, list<Node>::iterator> pos;

        auto tryInsert = [&](const string& name, long long sz) -> bool {
            if (pos.find(name) != pos.end()) return true;
            // find blocks of free with len>=sz; choose smallest len then earliest position
            long long bestLen = (1LL<<62);
            auto bestIt = disk.end();
            for (auto it = disk.begin(); it != disk.end(); ++it) {
                if (it->free && it->len >= sz) {
                    if (it->len < bestLen) {
                        bestLen = it->len;
                        bestIt = it;
                    } else if (it->len == bestLen) {
                        if (bestIt == disk.end()) bestIt = it;
                    }
                }
            }
            if (bestIt == disk.end()) return false;

            // allocate at beginning of best free block
            long long remaining = bestIt->len - sz;
            auto insertIt = disk.insert(bestIt, Node{sz,false,name});
            pos[name] = insertIt;
            bestIt->len = remaining;
            if (bestIt->len == 0) {
                // remove empty free node
                pos.erase(name); // will be overwritten below
                auto toErase = bestIt;
                // inserted node is still valid
                pos[name] = insertIt;
                disk.erase(toErase);
            }
            // merge adjacent free nodes just in case
            if (insertIt != disk.begin()) {
                auto prev = prev(insertIt);
                if (prev->free && insertIt->free) { /* won't happen */ }
            }
            mergeAdjacent in list
            if (insertIt != disk.begin()) {
                auto prev = prev(insertIt);
                if (prev->free && prev->len==0) {}
            }
            return true;
        };

        auto listMergeAdjacent = [&]() {
            for (auto it = disk.begin(); it != disk.end();) {
                if (it->free) {
                    auto nx = next(it);
                    while (nx != disk.end() && nx->free) {
                        it->len += nx->len;
                        nx = disk.erase(nx);
                    }
                }
                ++it;
            }
        };

        auto removeFile2 = [&](const string& name) {
            auto it = pos.find(name);
            if (it == pos.end()) return;
            auto nodeIt = it->second;
            long long sz = nodeIt->len;
            disk.erase(nodeIt);
            pos.erase(it);
            // Need insert free block in its place; since erased, we lost size; add as free at same position by using iterator returned by erase.
            // But erase returns iterator to next. We'll handle by finding where to insert.
        };

        // rewrite with proper operations using list with stable iterators
        pos.clear();
        disk.clear();
        disk.push_back({D,true,""});
        files.clear();
        error = false;

        auto insertFile = [&](const string& name, long long sz) -> void {
            if (pos.find(name) != pos.end()) return;

            auto findBest = [&]() -> pair<list<Node>::iterator,long long> {
                long long bestLen = (1LL<<62);
                list<Node>::iterator bestIt = disk.end();
                for (auto it = disk.begin(); it != disk.end(); ++it) {
                    if (it->free && it->len >= sz) {
                        if (it->len < bestLen) {
                            bestLen = it->len;
                            bestIt = it;
                        }
                    }
                }
                return {bestIt,bestLen};
            };

            auto [bestIt, bestLen] = findBest();
            if (bestIt == disk.end()) {
                // optimize then try again
                vector<pair<string,long long>> order;
                for (auto it = disk.begin(); it != disk.end(); ++it) {
                    if (!it->free) order.push_back({it->name, it->len});
                }
                disk.clear();
                long long used = 0;
                for (auto &p : order) { disk.push_back({p.second,false,p.first}); used += p.second; }
                disk.push_back({D-used,true,""});
                pos.clear();
                for (auto it = disk.begin(); it != disk.end(); ++it) if (!it->free) pos[it->name]=it;

                tie(bestIt, bestLen) = findBest();
                if (bestIt == disk.end()) {
                    error = true;
                    return;
                }
            }

            long long remaining = bestIt->len - sz;
            auto inserted = disk.insert(bestIt, Node{sz,false,name});
            bestIt->len = remaining;
            bestIt->free = true;
            bestIt->name = "";
            bestIt->free = true;
            bestIt->name.clear();

            pos[name] = inserted;
            listMergeAdjacent();
        };

        auto removeOp = [&](const string& name) -> void {
            auto it = pos.find(name);
            if (it == pos.end()) return;
            auto nodeIt = it->second;
            long long sz = nodeIt->len;
            auto nextIt = next(nodeIt);
            auto prevIt = (nodeIt==disk.begin()? disk.end() : prev(nodeIt));
            disk.erase(nodeIt);
            pos.erase(it);
            // Insert free block at position of erase; easiest: insert before nextIt
            auto freeIt = disk.insert(nextIt, Node{sz,true,""});
            // merge adjacent frees
            if (prevIt != disk.end() && prevIt->free) {
                prevIt->len += freeIt->len;
                disk.erase(freeIt);
                freeIt = prevIt;
            }
            nextIt = next(freeIt);
            if (nextIt != disk.end() && nextIt->free) {
                freeIt->len += nextIt->len;
                disk.erase(nextIt);
            }
        };

        auto optimizeOp = [&]() -> void {
            vector<pair<string,long long>> order;
            for (auto it = disk.begin(); it != disk.end(); ++it) {
                if (!it->free) order.push_back({it->name, it->len});
            }
            disk.clear();
            long long used = 0;
            for (auto &p : order) { disk.push_back({p.second,false,p.first}); used += p.second; }
            disk.push_back({D-used,true,""});
            pos.clear();
            for (auto it = disk.begin(); it != disk.end(); ++it) if (!it->free) pos[it->name]=it;
        };

        for (int i = 0; i < N; i++) {
            string op;
            cin >> op;
            if (error) {
                if (op == "insere") {
                    string name, sz; cin >> name >> sz;
                } else if (op == "remove") {
                    string name; cin >> name;
                } else {
                    // otimiza
                }
                continue;
            }

            if (op == "insere") {
                string name, szS;
                cin >> name >> szS;
                long long sz = parseSizeToKb(szS);
                insertFile(name, sz);
            } else if (op == "remove") {
                string name;
                cin >> name;
                removeOp(name);
            } else { // otimiza
                optimizeOp();
            }
        }

        if (error) {
            cout << "ERRO: disco cheio\n";
            continue;
        }

        // produce approximation
        // divide disk bytes in eight contiguous blocks of equal size
        long long totalBytes = D * 1024LL; // since D is in Kb (Kb = 1024 bytes)
        // each of 8 blocks is bytesPerBlock = totalBytes/8
        long long bytesPerBlock = totalBytes / 8;
        long long kbPerBlock = bytesPerBlock / 1024LL;
        // But need handle potential remainder; D is multiple of 8Kb so totalBytes divisible by 8, kbPerBlock exact.
        vector<long long> freeInBlock(8,0);

        // traverse disk segments and add free overlaps with each block in Kb.
        // Represent position along disk in Kb.
        long long posKb = 0;
        vector<long long> startKb(8), endKb(8);
        for (int b=0;b<8;b++){
            startKb[b]=b*kbPerBlock;
            endKb[b]=(b+1)*kbPerBlock;
        }
        for (auto &nd : disk) {
            long long L = nd.len;
            long long segL = posKb;
            long long segR = posKb + L;
            if (nd.free) {
                for (int b=0;b<8;b++) {
                    long long l = max(segL, startKb[b]);
                    long long r = min(segR, endKb[b]);
                    if (l < r) freeInBlock[b] += (r - l);
                }
            }
            posKb += L;
        }

        string out;
        for (int b=0;b<8;b++) {
            long double P = (long double)freeInBlock[b] * 100.0L / (long double)kbPerBlock;
            char c;
            if (P > 75.0L && P <= 100.0L) c = '#';
            else if (P > 25.0L && P <= 75.0L) c = '-';
            else c = ' ';
            out.push_back(c);
        }
        cout << out << "\n";
    }
    return 0;
}