class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> result(2,-1);
        if(A.size() == 0)
            return result;

        long lb = 0;
        long ub = A.size() - 1;
        long startIndex = -1;
        long endIndex = -1;
        while( lb <= ub ){
            long mid = ( lb + ub ) >> 1;

            if( A[mid] >= target ){
                startIndex = mid;
                ub = mid - 1;
            } else {
                lb = mid + 1;
            }
        }
        if(A[startIndex] == target)
            result[0] = startIndex;
        lb = 0;
        ub = A.size() - 1;
        while( lb <= ub ){
            long mid = ( lb + ub ) >> 1;

            if( A[mid] <= target ){
                endIndex = mid;
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
        if(A[endIndex] == target)
            result[1] = endIndex;

        return result;
    }
};
