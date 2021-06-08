#include<iostream>
#include<stack>

using namespace std;

int balanced_paran(string x, int start, int end) {

    int n = x.length();

    int i = start+1;
    int j = end-1;
    int sum = 0;
    stack<int> s;
    
    if(i>j) return 1;
    int opening_br;
    int closing_br = i;

    while(closing_br<j) {
        if(x[i]=='(') {
            if(s.size()==0) {
                opening_br = i;
            }
            s.push(x[i]);
        }
        else if(x[i]==')') {
            if(s.top()=='(') {
                if(s.size()==1) {
                    closing_br = i;
                    sum += balanced_paran(x, opening_br, closing_br);
                }
                s.pop();
            }
        }
        i++;
    }

    
    if(sum>0) {
        return 2*sum;
    }
    else
        return 1;

}

int main() {

    string ip = "((()(())))";
    cout<<"final output: "<<balanced_paran(ip, 0,ip.length()-1);
    return 0;
}