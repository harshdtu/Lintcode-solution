class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> prod(nums.size());

        if(nums.empty())
            return prod;
        prod[0] = 1;
        long long temp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prod[i] = temp;
            temp *= nums[i];
        }

        temp = nums.back();

        for(int i = nums.size() - 2; i >= 0; i--){
            prod[i] *= temp;
            temp *= nums[i];
        }

        return prod;
    }
};
