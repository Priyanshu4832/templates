#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];          // Input array
int seg[4 * N];    // Segment tree array

// Build the segment tree
void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

// Query the maximum in range [l, r]
int query(int ind, int low, int high, int l, int r) {
    // Complete overlap
    if (low >= l && high <= r) {
        return seg[ind];
    }

    // No overlap
    if (high < l || low > r) {
        return INT_MIN;
    }

    // Partial overlap
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

// Update the value at index i to val
void update(int ind, int low, int high, int i, int val) {
    if (low == high) {
        //a[i] = val; //this just reflects the val in original array
        seg[ind] = val;
        return;
    }

    int mid = (low + high) / 2;
    if (i <= mid) {
        update(2 * ind + 1, low, mid, i, val);
    } else {
        update(2 * ind + 2, mid + 1, high, i, val);
    }

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main() {
    int n;
    cin >> n;
    
    // Input array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Build the segment tree
    build(0, 0, n - 1);

    // Example queries
    cout << "Max in range [1, 4]: " << query(0, 0, n - 1, 1, 4) << "\n";

    // Update a[2] = 100
    update(0, 0, n - 1, 2, 100);
    cout << "After update, max in range [1, 4]: " << query(0, 0, n - 1, 1, 4) << "\n";

    return 0;
}
