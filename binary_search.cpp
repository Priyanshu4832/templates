Absolutely! Here's a complete set of the **binary search templates in C++**, correctly written and commented.

---

## 🧭 **1. Classic Binary Search (Find Target in Sorted Array)**

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {  // inclusive search
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;  // not found
}
```

---

## 🔽 **2. Lower Bound (First Element ≥ Target)**

```cpp
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();  // notice: right is size, not size-1
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;  // may return nums.size() if target is too big
}
```

---

## 🔼 **3. Upper Bound (First Element > Target)**

```cpp
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}
```

---

## ✅ **4. Binary Search on Answer (Find Min Valid Value)**

Use this when trying to **minimize** a value that satisfies a `condition()`.

```cpp
int binarySearchMinAnswer(int left, int right, function<bool(int)> condition) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (condition(mid)) {
            right = mid;  // mid might be the answer
        } else {
            left = mid + 1;
        }
    }
    return left;  // first value where condition is true
}
```

---

## ✅ **5. Binary Search on Answer (Find Max Valid Value)**

Use this when trying to **maximize** a value that satisfies a `condition()`.

```cpp
int binarySearchMaxAnswer(int left, int right, function<bool(int)> condition) {
    while (left < right) {
        int mid = left + (right - left + 1) / 2;  // bias to right
        if (condition(mid)) {
            left = mid;  // mid might be the answer
        } else {
            right = mid - 1;
        }
    }
    return left;  // last value where condition is true
}
```

---

## 🌌 **6. Infinite Binary Search (Unknown Right Bound)**

Used when the upper bound is not known, so we first expand it.

```cpp
int infiniteBinarySearch(function<bool(int)> condition) {
    int left = 0, right = 1;
    while (!condition(right)) {
        left = right;
        right *= 2;  // expand
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (condition(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

---

## 📈 **7. Ternary Search (Unimodal Function Max/Min)**

For finding min/max of a convex or concave function.

```cpp
int ternarySearch(int left, int right, function<long long(int)> f) {
    while (right - left > 2) {
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;
        if (f(m1) < f(m2)) left = m1;
        else right = m2;
    }

    long long best = f(left);
    for (int i = left + 1; i <= right; ++i)
        best = min(best, f(i));  // or max() for maximizing
    return best;
}
```

---

## 🧠 Summary Table

| Purpose                                | Template                      | Mid Bias     | Common Use                    |
| -------------------------------------- | ----------------------------- | ------------ | ----------------------------- |
| Find exact in sorted array             | Classic                       | center       | Exact match                   |
| First ≥ target                         | Lower bound                   | center       | Insert position               |
| First > target                         | Upper bound                   | center       | Count occurrences             |
| Min value that satisfies `condition()` | Binary Search on Answer (Min) | center       | Scheduling, minimum speed     |
| Max value that satisfies `condition()` | Binary Search on Answer (Max) | right-biased | Max side length, max feasible |
| Unbounded space                        | Infinite Binary Search        | center       | Streams or unknown limits     |
| Peak/min of unimodal                   | Ternary Search                | both sides   | Optimization problems         |

---

Let me know if you want real C++ examples on LeetCode or problems to practice each one.
