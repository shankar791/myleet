class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        stack<int> s;
        vector<int> rightMin(n);

        rightMin[n - 1] = nums[n - 1];
        s.push(nums[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < s.top()) {
                s.push(nums[i]);
            }

            rightMin[i] = s.top();
        }

        int leftMax = nums[0];

        for (int i = 0; i < n; i++) {

            if (nums[i] > leftMax) {
                leftMax = nums[i];
            }

            int score = leftMax - rightMin[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};