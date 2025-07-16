
1. Classic Binary Search (Find Target in Sorted Array)

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










2. Lower Bound (First Element ≥ Target)


int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();  // notice: right is size, not size-1
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;  // may return nums.size() if target is too big
}










3. Upper Bound (First Element > Target)


int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}









4. Binary Search on Answer (Find Min Valid Value)

Use this when trying to **minimize** a value that satisfies a `condition()`.


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












5. Binary Search on Answer (Find Max Valid Value)**

Use this when trying to **maximize** a value that satisfies a `condition()`.


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













6. Infinite Binary Search (Unknown Right Bound)**

Used when the upper bound is not known, so we first expand it.


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

