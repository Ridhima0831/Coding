class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int tempMax = max({x, x * currentMax, x * currentMin});
            int tempMin = min({x, x * currentMax, x * currentMin});

            currentMax = tempMax;
            currentMin = tempMin;

            answer = max(answer, currentMax);
        }

        return answer;
    }
};