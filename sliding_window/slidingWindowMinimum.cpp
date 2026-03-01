#include<bits/stdc++.h>
using namespace std;

vector<long long> slidingWindowMinimum(vector<long long>& nums, int n, int k){
    vector<long long> ans;
    deque<int> dq;

    for(int i = 0; i < n; i++){

        // Remove elements out of the window
        if(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }

        // Maintain increasing order deque
        while(!dq.empty() && nums[dq.back()] > nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        // Collect minimum once window is formed
        if(i >= k - 1){
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> nums(n);
    nums[0] = x;

    for(int i = 1; i < n; i++){
        nums[i] = ((nums[i - 1] * a) + b) % c;
    }

    vector<long long> mins = slidingWindowMinimum(nums, n, k);

    long long ans = mins[0];
    for(int i = 1; i < (int)mins.size(); i++){
        ans ^= mins[i];
    }

    cout << ans << "\n";

    return 0;
}
