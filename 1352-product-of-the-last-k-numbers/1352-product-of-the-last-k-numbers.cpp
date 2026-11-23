class ProductOfNumbers {

    vector<int>dp;
public:
    ProductOfNumbers() {
        dp.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            dp.clear();
            dp.push_back(1);
        }else{
            dp.push_back(dp.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n = dp.size();
        if(k>=n)return 0;
        return dp[n-1]/dp[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */