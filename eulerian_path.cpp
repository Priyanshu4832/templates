class Solution {
public:

    vector<string> ans;
    unordered_map<string, priority_queue<string , vector<string> , greater<string>>> adj;

    void dfs(string start ){

        auto& heap = adj[start];
        while(!heap.empty()){
            string next = heap.top();
            heap.pop();
            dfs(next);
        }
        ans.push_back(start);
        
    }



    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
       
        for(auto it : tickets){
            adj[it[0]].push(it[1]);
        }

        
        
        dfs("JFK" );
        reverse(ans.begin(), ans.end());

        return ans;

    }
};
