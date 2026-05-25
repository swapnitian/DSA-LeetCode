class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();        
        vector<int>vis(n+1,0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int right_most = 0;    

        // in this we try BFS + Sliding window as we don''t have to visit the indices again

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(idx == n-1) return true;

            int left = max(right_most + 1, idx + minJump);
            int right = min(idx + maxJump, n-1);

            for(left ; left <= right; left++){
                if(s[left] == '0' && vis[left] == 0){
                    vis[left] = 1;
                    q.push(left);
                    
                }
            }
            right_most = right;
        }

        return false;
    }
};