class Solution {
public:
    int lower_bound(vector<int>& arr, int find) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (arr[mid] == find) return mid;
            else if (arr[mid] > find) high = mid - 1;
            else low = mid;
        }
        return low;
    }
    int upper_bound(vector<int>& arr, int find) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == find) return mid;
            else if (arr[mid] > find) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int start = lower_bound(arr, x);
        int end = upper_bound(arr, x);
        int n = arr.size();
        while (end - start - 1 < k) {
            if (start < 0) {
                end += 1;
            } else if (end >= n || abs(arr[start] - x) <= abs(arr[end] -x)) {
                start -= 1;
            } else {
                end += 1;
            }
        }
        for (int i=start+1; i<end; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
