class Solution {
public:
    // void AdjustDown(vector<int>& a, int n, int root){
    //     int parent = root;
    //     int child = parent*2+1;
    //     while(child<n){
    //         if(child+1<n && a[child+1] > a[child]){
    //             ++child;
    //         }
    //         if(a[child] > a[parent]){
    //             int tmp = a[child];
    //             a[child] = a[parent];
    //             a[parent] = tmp;
    //             parent = child;
    //             child = 2*parent+1;
    //         }else{ 
    //             break;
    //         }
    //     }
    // }
    vector<int> smallestK(vector<int>& arr, int k) {
        // sort(arr.begin(),arr.end());
        // vector<int> ret(k);
        // for(int i=0; i<k; ++i){
        //     ret[i] = arr[i];
        // }
        // return ret;
        vector<int> ans;
        if (k == 0) {
            return ans;
        }
        priority_queue<int> q;
        for (int i = 0; i < k; ++i) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }

        return ans;


    }
};