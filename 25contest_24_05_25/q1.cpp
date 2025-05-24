#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        sort(arr,arr+n);
        int mini=arr[0],maxi=arr[n-1];
        int part1=0,part2=0; //initialise
        if((mini%2==0 && maxi%2==0)||(mini%2==1 && maxi%2==1)){
            cout<<0<<endl;
            continue;
        }
        else if(mini%2==1 && maxi%2==0){
            for(int i=1;i<n-1;i++){
                if(arr[i]%2==0){
                    part1=i;
                    break;
                }
            }
            for(int i=n-2;i>0;i--){
                if(arr[i]%2==1){
                    part2=n-i-1;
                    break;
                }
            }
            if(part1==0 && part2==0){
                cout<<n-1<<endl;
                continue;
            }
            else if(part1==0 && part2!=0){
                cout<<part2<<endl;
                continue;
            }
            else if(part1!=0 && part2==0){
                cout<<part1<<endl;
                continue;
            }
            else{
                cout<<min(part1,part2)<<endl;
                continue;
            }
        }
        else{ //if(mini%2==0 && maxi%2==1)
            for(int i=1;i<n-1;i++){
                if(arr[i]%2==1){
                    part1=i;
                    break;
                }
            }
            for(int i=n-2;i>0;i--){
                if(arr[i]%2==0){
                    part2=n-i-1;
                    break;
                }
            }
            if(part1==0 && part2==0){
                cout<<n-1<<endl;
                continue;
            }
            else if(part1==0 && part2!=0){
                cout<<part2<<endl;
                continue;
            }
            else if(part1!=0 && part2==0){
                cout<<part1<<endl;
                continue;
            }
            else{
                cout<<min(part1,part2)<<endl;
                continue;
            }
        }
    }
    return 0;
}