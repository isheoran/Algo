#include<bits/stdc++.h>
using namespace std;

int make_string_length_equal(string &x,string &y) {
    int n = (int)(x.size())-(int)(y.size());
    if(n>0) {
        reverse(y.begin(),y.end());
        while(n>0) {
            n--;
            y.push_back('0');
        }
        reverse(y.begin(),y.end());
    }
    else if(n<0) {
        reverse(x.begin(),x.end());
        while(n<0) {
            n++;
            x.push_back('0');
        }
        reverse(x.begin(),x.end());
    }
    return (int)(x.size());
}

char multiply_single_bit(char x,char y) {
    int res = (int)(x-'0')*(int)(y-'0');
    return (char)(res+'0');
}

string add_zeroes(string x,int n) {
    while(n>0) {
        x.push_back('0');
        n--;
    }
    return x;
}

string add_strings(string x,string y) {
    string res;
    int n = make_string_length_equal(x,y);
    int carry = 0;
    for(int i=n-1;i>=0;i--) {
        int num = (int)(x[i]-'0')+(int)(y[i]-'0')+carry;
        if(num>1) carry = 1;
        else carry = 0;
        num%=2;
        res.push_back((char)(num+'0')); 
    }
    if(carry) res.push_back((char)(carry+'0'));
    while(!res.empty() and res.back()=='0') res.pop_back();
    reverse(res.begin(),res.end());
    if(res.empty()) res = "0";
    return res;
}

string subtract_strings(string x,string y) {
    string res;
    int n = make_string_length_equal(x,y);
    int carry = 0;
    for(int i=n-1;i>=0;i--) {
        int num = (int)(x[i]-'0')-(int)(y[i]-'0')-carry;
        if(num<0) {
            num += 2;
            carry = 1;
        }
        else carry = 0;
        res.push_back((char)(num+'0'));
    }
    while(!res.empty() and res.back()=='0') res.pop_back();
    reverse(res.begin(),res.end());
    if(res.empty()) res = "0";
    return res;
}

string multiply(string x,string y) {
    int n =  make_string_length_equal(x,y);
    string ans = "0";
    if(n==0) return ans;
    if(n==1) {
        ans = multiply_single_bit(x[0],y[0]);
        return ans;
    }
    //Lets divide these strings into half i.e. Xl,Xr,Yl,Yr;
    string Xl = x.substr(0,n/2);
    string Xr = x.substr(n/2);
    string Yl = y.substr(0,n/2);
    string Yr = y.substr(n/2);
    string XlYl = multiply(Xl,Yl);
    string XrYr = multiply(Xr,Yr);
    string middle = subtract_strings(multiply(add_strings(Xl,Xr),add_strings(Yl,Yr)),XlYl);
    middle = subtract_strings(middle,XrYr);
    ans = add_strings(add_zeroes(XlYl,2*(n-n/2)),XrYr);
    ans = add_strings(ans,add_zeroes(middle,n-n/2));
    return ans;
}

int main() {
    string x,y;
    cin>>x>>y;
    cout<<multiply(x,y);
    return 0;
}