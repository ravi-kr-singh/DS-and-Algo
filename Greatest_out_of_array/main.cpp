#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int num){
  int rev_num=0;
  while(num!=0){
    rev_num=rev_num*10 +num%10;
    num/=10;
  }
  return rev_num;
}

int tobefirst(int a,int b,int i,int j){
  a=reverse(a);
  b=reverse(b);
  while(a!=0 && b!=0){
    if(a%10>b%10)
      return i;
    else if(a%10<b%10)
      return j;
    a/=10;
    b/=10;
  }
  if(a!=0)
    return i;
  else
    return j;
}

int find_first_num(int* arr,int n){
  int first_index=0;
  for (size_t i = 1; i < n; i++) {
    int temp_index=tobefirst(arr[i],arr[first_index],i,first_index);
    if(temp_index!=first_index)
      first_index=temp_index;
  }
  return first_index;
}

void Greatest_out_of_arr(int *arr,int n){
  if(n>1){
    int first_index=find_first_num(arr,n);
    if(first_index!=0)
      swap(arr[0],arr[first_index]);
    Greatest_out_of_arr(arr+1,n-1);
  }
}

int main() {
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  cout<<"Enter array : ";
  int arr[n];
  for (size_t i = 0; i < n; i++) {
    cin>>arr[i];
  }
  Greatest_out_of_arr(arr,n);
  cout<<"Greatest possible number is....";
  for (size_t i = 0; i < n; i++) {
    cout<<arr[i];
  }
  return 0;
}
