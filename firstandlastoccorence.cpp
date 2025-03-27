#include<iostream>
//#include <utility>
using namespace std;

int firstOccurence(int arr[], int n, int key) {
int s=0;
int e=n-1;
int ans= 0;
int mid = s+(e-s)/2;
while(s<=e) {
if(arr[mid]==key) {
    ans=mid;
    e = mid-1;
}
else if (arr[mid]<key) {
    s=mid+1;

}
else {
    e = mid-1;
    
}

mid = s+(e-s)/2;


}
return ans;
}

int lastOccurence(int arr[], int n, int key) {
int s=0;
int e=n-1;
int ans= 0;
int mid = s+(e-s)/2;
while(s<=e) {
if(arr[mid]==key) {
    ans=mid;
    s=mid+1;
}
else if(arr[mid]<key) {
    s=mid+1;
}
else {
    e=mid-1;
}
mid = s+(e-s)/2;
} 
return ans;
}
int main() {
int arr[]={1,2,3,3,3,3,5};
//int a= firstOccurence(arr, 5, 3);
//int b=lastOccurence(arr, 5, 3);
pair<int,int>p;
p.first= firstOccurence(arr, 7, 3);
p.second=lastOccurence(arr, 7, 3);
cout<<p.first<<" \t"<<p.second;


return 0;
}