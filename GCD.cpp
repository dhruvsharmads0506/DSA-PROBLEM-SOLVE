#include<iostream>
using namespace std;

int gcd(int a, int b) {
if(a==0)
return b;
if(b==0)
return a;

while(a!=b) {
if(a>b) {
    a = a-b;
}

else {
    b=b-a;
}
}
return a;
}

int main() {

int a;
int b;
cout<<"Enter first number \n";
cin>>a;
cout<<"Enter second number \n";
cin>>b;

int ans = gcd(a, b);

cout<<"GCD of given number is : "<<ans;

return 0;

}