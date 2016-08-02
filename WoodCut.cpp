class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        if(L.size() == 0)
            return 0;
        long maxElement = *(max_element(L.begin(), L.end()));
        //lb != 0, to avoid divide by zero error
        long lb = 1;
        //We set ub = maxElement and not minElement, because it's possible to get >= k number of logs of length greater than minElement.
        long ub = maxElement;
        long result = 0;
        while(lb <= ub){

            long mid = (lb + ub) >> 1;
            if(countK(L, mid) >= k){
                result = mid;
                lb = mid + 1;
            }
            else
                ub = mid - 1;

        }

        return result;
    }

    long countK(vector<int> & L, long lenOfWood){
        long res = 0;
        for(auto i : L){
            res += i/lenOfWood;
        }

        return res;
    }
};
