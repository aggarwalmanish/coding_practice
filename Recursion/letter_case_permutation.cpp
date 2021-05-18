#include<iostream>
#include<string>
using namespace std;

void solve(string ip, string op) {
    if(ip.length() == 0) {
        cout<<op<<endl;
        return;
    }
    
    if(ip[0] >=48 && ip[0] <=57) {
        
        op.push_back(ip[0]);
        ip.erase(ip.begin() + 0);

        solve(ip, op);
    }
    else {
        string op2 = op;
        op.push_back(ip[0]);
        op2.push_back(ip[0]-32);
        
        ip.erase(ip.begin()+0);

        solve(ip, op);
        solve(ip, op2);
    }
    
    return;
}

int main() {

    string ip = "a123";
    string op = "";
    solve(ip, op);

    return 0;
}