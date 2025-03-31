#include<iostream>
using namespace std;
int Pivotelement(int arr[], int size) {
int s=0;
int e=size-1;
int mid = s+(e-s)/2;
while(s<e) {
if(arr[mid]>=arr[0]) {
    s=mid+1;
}
else 
{
    e=mid;
}
mid = s+(e-s)/2;
}
return s;

}

int main() {
int arr[]={7,9,1,2,3};
int pivot = Pivotelement(arr, 5);
cout<<pivot;
return 0;
}