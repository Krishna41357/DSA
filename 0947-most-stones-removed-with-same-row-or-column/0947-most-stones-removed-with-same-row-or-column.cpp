class DSU{
public: 
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();
        DSU ds(n);
        unordered_map<int,vector<int>>rows;
        unordered_map<int,vector<int>>cols;
        for(int i = 0 ; i < stones.size() ; i++){
            int row = stones[i][0];
            int col = stones[i][1];
            rows[row].push_back(i);
            cols[col].push_back(i);
        }

        for(auto it : rows){
            for(int i = 1 ; i < it.second.size(); i++){
                ds.Union(it.second[i] , it.second[i-1]);
            }
        }

        for(auto it : cols){
            for(int i = 1 ; i < it.second.size(); i++){
                ds.Union(it.second[i] , it.second[i-1]);
            }
        }
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i) {
                components++;
            }
        }

        return n - components;
    }
};