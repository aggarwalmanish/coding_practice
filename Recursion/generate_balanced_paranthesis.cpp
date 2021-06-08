#include<iostream>
#include<string>
using namespace std;

void solve(int open_br, int close_br, string op) {
    if(open_br == 0) {
        while(close_br) {
            op.push_back(')');
            close_br--;
        }
        cout<<op<<endl;
        return;
    }

    if (open_br == close_br) {
        op.push_back('(');
        solve(open_br-1, close_br, op);
    }

    else if(open_br<close_br) {
        string op2 = op;
        op.push_back('(');
        op2.push_back(')');

        solve(open_br-1, close_br, op);
        solve(open_br, close_br-1, op2);
    }
       
    return;
}

int main() {

    int n = 3;
    string op = "";
    solve(n, n, op);

    return 0;
}