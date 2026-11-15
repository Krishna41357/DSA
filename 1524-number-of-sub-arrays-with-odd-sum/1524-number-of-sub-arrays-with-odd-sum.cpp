class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int evenCount = 1 , oddCount = 0;
        int prefixSum = 0;
        long long result = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            prefixSum += arr[i];
            if(prefixSum%2==0){
                evenCount+=1;
                result=(result+oddCount)%MOD;
            }
            else {
                oddCount +=1;
                result=(result+evenCount)%MOD;
            }
        }
        return result;
    }
};