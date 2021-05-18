
        vector <int> max_of_subarrays(int *arr, int n, int k){
        // your code here
        
        vector <int> sol;
        
        priority_queue<int> pq;
        for(int i=0;i<k;i++) {
            pq.push(arr[i]);
        }
        int index = 0;
        priority_queue<int> gq;
        bool found = false;
        
        for(int i=k;i<n-k+1;i++) {
            cout<<"pq.top: "<<pq.top()<<endl;
            sol.push_back(pq.top());
            gq = pq;
            found = false;
            while(!gq.empty() && found = true) {
                if(gq.top()==arr[index++]) {
                    gq.pop;
                    pq.pop;
                }
            }
            whi
            pq.pop();
            pq.push(arr[i]);
            cout<<"after: "<<pq.top()<<endl;
        }
        return sol;
        
    }