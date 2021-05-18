#include<iostream>
using namespace std;

void solve(string ip, string op) {
    if(ip.length() == 1) {
        op.push_back(ip[0]);
        cout<<op<<endl;
        return;
    }

    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    string op2 = op;
    op2.push_back(' ');

    solve(ip, op);
    solve(ip, op2);
    return;
}

int main() {

    string ip = "ABC";
    string op = "";
    solve(ip, op);

    return 0;
}