#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    int n;

    SegmentTree(vector<int>& baskets) {
        n = baskets.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, baskets);
    }





    void build(int ind, int low, int high, vector<int>& baskets) {
        if (low == high) {
            seg[ind] = baskets[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, baskets);
        build(2 * ind + 2, mid + 1, high, baskets);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }






    // Point update: set baskets[i] = val
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }






    // Query max in [l, r]
    int query(int ind, int low, int high, int l, int r) {
        if (high < l || low > r) return INT_MIN;
        if (low >= l && high <= r) return seg[ind];
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }






    // Find the leftmost index >= target capacity
    int findIndex(int ind, int low, int high, int target) {
        if (seg[ind] < target) return -1;
        if (low == high) return low;

        int mid = (low + high) / 2;
        int left = seg[2 * ind + 1];

        if (left >= target) return findIndex(2 * ind + 1, low, mid, target);
        else return findIndex(2 * ind + 2, mid + 1, high, target);
    }
};








int unplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    SegmentTree tree(baskets);

    int unplaced = 0;

    for (int i = 0; i < n; i++) {
        int fruitAmount = fruits[i];
        int index = tree.findIndex(0, 0, n - 1, fruitAmount);
        if (index == -1) {
            unplaced++;
        } else {
            tree.update(0, 0, n - 1, index, -1); // Mark basket used
        }
    }

    return unplaced;
}
int main() {
    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};

    cout << unplacedFruits(fruits, baskets) << "\n"; // Output: 1
    return 0;
}

