vector<int> factorial(int N){
        // code here
        vector<int> res;
        
        if(N==1) {
            res.push_back(N);
            return res;
        }
        
        
        vector<int> next_fact = factorial(N-1);
        int digits = 0;
        int curr = N;
        while(curr>0) {
            curr = curr/10;
            digits++;
        }
        int curr_number = N;
        int curr_digit = 0;
        int carry = 0;
        int curr_ans = 0;
        
        vector<vector<int>> multi_res(digits);
        for(int i=0;i<digits;i++) {
            carry = 0;
            curr_digit = curr_number%10;
            curr_number = curr_number/10;
            int zeros = i;
            while(zeros>0) {
                multi_res[i].push_back(0);
                zeros--;
            }
            for(int j=next_fact.size()-1; j>=0;j--) {
                curr_ans = next_fact[j]*curr_digit + carry;
                if(curr_ans > 9) {
                    carry = curr_ans/10;
                    curr_ans = curr_ans%10;
                }
                else {
                    carry = 0;
                }
                // cout<<"curr_digit: "<<curr_digit<<endl;
                // cout<<"curr_ans: "<<curr_ans<<endl;
                // cout<<endl;
                multi_res[i].push_back(curr_ans);
            }
            if(carry!=0) {
                // cout<<"carry added: "<<carry<<endl;
                multi_res[i].push_back(carry);
            }
        }
        
        
        int max_size = multi_res[digits-1].size();
        carry = 0;
        int sum = 0;
        for(int i=0;i<max_size;i++) {
            // int curr_vec_size = multi_res[i].size();
            sum = carry;
            int ans = 0;
            for(int j=0;j<digits;j++) {
                sum = sum + multi_res[j][i];
            }
            if(sum>9) {
                carry = sum/10;
                ans = sum%10;
            }
            else {
                ans = sum;
                carry = 0;
            }
            // cout<<"ans: "<<ans<<endl;
            res.push_back(ans);
        }
        if(carry!=0)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        
        return res;
        
    }