#include <bits/stdc++.h>

using namespace std;

vector<int> add_arr(vector<int> arr1,vector<int> arr2){
    vector<int> result;
    int k=min(arr1.size(),arr2.size()),temp=0;
    for(int i=0;i<k;i++){
        temp+=arr1[i]+arr2[i];
        result.push_back(temp%10);
        temp/=10;
    }
    if(arr1.size()>arr2.size()){
        for(int i=arr2.size();i<arr1.size();i++){
            temp+=arr1[i];
            result.push_back(temp%10);
            temp/=10;
        }
    }
    else{
        for(int i=arr1.size();i<arr2.size();i++){
            temp+=arr2[i];
            result.push_back(temp%10);
            temp/=10;
        }
    }
    while(temp!=0){
            result.push_back(temp%10);
            temp/=10;
        }
    return result;
}


vector<int> Multiplying(vector<int> given,int n){
    vector<int> temp,temp2={0};
    int t=0,k=0;
    while(n!=0){
        for(int i=0;i<given.size();i++){
            t+=(n%10)*given[i];
            temp.push_back(t%10);
            t/=10;
        }
        while(t!=0){
            temp.push_back(t%10);
            t/=10;
        }
        if(k>0){
            int r=k;
            while(r!=0){
                temp.insert(temp.begin(),0);
                r--;
            }
        }
        temp2=add_arr(temp2,temp);
        temp.clear();
        k++;
        n/=10;
    }
    return temp2;
}

void extraLongFactorials(int n) {
    vector<int> ans={1};
    int temp=1;
    while(n>1){
        ans=Multiplying(ans,n);
        n--;
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<endl;
    extraLongFactorials(n);

    return 0;
}
