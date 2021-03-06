class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        return quickselect(nums, 0, N-1, N-k);
    }
    
    int quickselect(vector<int>& a, int lo, int hi, int k) {
        if (lo >= hi) {
            return a[lo];
        }
        int v = partition(a, lo, hi);
        if (k < v) {
            return quickselect(a, lo, v-1, k);
        } else if (k > v) {
            return quickselect(a, v+1, hi, k);
        } else {
            return a[v];
        }
    }
    
    int partition(vector<int>& a, int lo, int hi) {
        int pivot = a[lo];
        int i = lo;
        int j = hi + 1;
        while (true) {
            while (a[++i] < pivot) {
                if (i == hi) {
                    break;
                }
            }
            while (a[--j] > pivot) {
                if (j == lo) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            swap(a[i], a[j]);
        }
        swap(a[lo], a[j]);
        return j;
    }
};
