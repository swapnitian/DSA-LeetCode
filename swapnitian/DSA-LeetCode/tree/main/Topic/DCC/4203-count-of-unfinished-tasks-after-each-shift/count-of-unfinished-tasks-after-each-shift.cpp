class Solution {
    using ll = long long;
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();
        // create the pref_sum of tasks
        vector<ll> pref_tasks(n);
        pref_tasks[0] = tasks[0];

        for(int i = 1; i < n; i++){
            pref_tasks[i] = pref_tasks[i-1] + tasks[i];
        }

        // will use the lower_bound on the pref_tasks 
        vector<int> ans(m);
        ll carry = 0;
        for(int i = 0; i < m; i++){
            auto it = lower_bound(pref_tasks.begin(), pref_tasks.end(), carry+shifts[i]);

            if(it == pref_tasks.end()){
                ans[i] = 0;
                carry = 0;
            }else{
                int idx = it - pref_tasks.begin();

                idx = (pref_tasks[idx] == 1LL*shifts[i]+carry) ? idx : idx-1;

                if(idx == n-1){
                    ans[i] = 0;
                    carry = 0;
                }else{
                    ans[i] = n-idx-1;
                    if(i + 1 < m) carry += 1LL*shifts[i];
                }
            }
        }
        return ans;
    }
};