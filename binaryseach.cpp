#include<iostream>
using namespace std;

int Binarysearch(int arr[], int n, int key) {
int start=0;
int end=n-1;
int mid= start+(end-start)/2;
while(start<=end) {
if(arr[mid]==key) {
    return mid;
}
else if(arr[mid]>key) {
end=mid-1;    
}
else {
     start=mid+1;
}
 mid= start+(end-start)/2;

}
return -1;
}


void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
int main() {
    int even[6]={2,4,5,6,7,8};
    int odd[5]={1,2,3,4,5};
    printarray(even, 6);
    printarray(odd, 5);
    int indexodd =Binarysearch(odd , 5, 4);
    int indexeven= Binarysearch(even , 6, 19);
    cout<<indexodd <<"\n";
    cout<<indexeven;

    

    return 0;
}