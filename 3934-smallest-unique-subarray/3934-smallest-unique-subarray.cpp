class Solution {
public:
    using ull = unsigned long long;
    const ull base = 1000000007;

    bool check(vector<int>& nums, int k) {
        unordered_map<ull, int> mp;

        ull hash = 0;
        ull power = 1;
        int n = nums.size();

        // Calculate hash of first window
        for(int i = 0; i < k; i++) {
            hash = hash * base + nums[i];
            if(i < k - 1)
                power *= base;
        }

        mp[hash]++;

        // Slide the window
        for(int i = k; i < n; i++) {
            hash -= nums[i - k] * power;
            hash = hash * base + nums[i];

            mp[hash]++;
        }

        // Check for a unique subarray
        for(auto& it : mp) {
            if(it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};