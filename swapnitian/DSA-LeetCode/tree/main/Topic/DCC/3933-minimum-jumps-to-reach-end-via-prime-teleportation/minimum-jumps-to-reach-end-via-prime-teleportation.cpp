class Solution {
private:
    void Make_prime(vector<bool> &isprime , int n){
        isprime[0] = isprime[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(isprime[i]){ 
                for(int j = i*i ; j <= n; j = j+i){
                    isprime[j] = false;
                }
            }
        }
    }
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);

            maxi = max(maxi , nums[i]);
        }

        vector<bool> isprime(maxi+1 , true);
        Make_prime(isprime , maxi);

        queue<int> q;
        vector<int> vis(n , 0);

        q.push(0); // starting source
        vis[0] = 1;
        int steps = 0;
        set<int> seen;
        // Applyinf BFS--

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int i = q.front();
                q.pop();

                if(i == n-1){
                    return steps;
                }

                // check where it can go -- left or right 

                // for (i-1)-

                if(i > 0 && vis[i-1] == 0){
                    q.push(i-1);
                    vis[i-1] = 1;
                }
                
                // for (i+1)
                if(i < n-1 && vis[i+1] == 0){
                    q.push(i+1);
                    vis[i+1] = 1;
                }

                // check if the nums[i] is prime or not;

                if(!isprime[nums[i]] || seen.count(nums[i])){
                    continue;
                }

                for(int multiple = nums[i] ; multiple <= maxi ; multiple += nums[i]){

                    if(!mp.contains(multiple)){
                        continue;
                    }

                    for(int j : mp[multiple]){
                        if(vis[j] == 0){
                            q.push(j);
                            vis[j] = 1;
                        }else{
                            continue;
                        }
                    }
                    
                }
                seen.insert(nums[i]);
            }
            steps++;
        }

        return steps;
    }
};