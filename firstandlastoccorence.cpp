#include<iostream>
using namespace std;

//Function to find first occurrence of element 
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
//Function to find last occurrence of element
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
//main function
int main() {
int arr[]={1,2,3,3,3,3,5};
//to initialise the pair
pair<int,int>p;
p.first= firstOccurence(arr, 7, 3);
p.second=lastOccurence(arr, 7, 3);
cout<<p.first<<" \t"<<p.second;


return 0;
}
