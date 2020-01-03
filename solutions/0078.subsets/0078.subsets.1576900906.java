class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        Deque<Integer> current = new ArrayDeque<>(nums.length);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(nums, 0, current, res);
        return res;
    }
    
    void backtrack(int[] nums, int k, Deque<Integer> current, List<List<Integer>> res) {
        if (k == nums.length) {
            res.add(new ArrayList<>(current));
            return;
        }
        
        backtrack(nums, k+1, current, res);
        
        current.addLast(nums[k]);
        backtrack(nums, k+1, current, res);
        current.removeLast();
    }
}
