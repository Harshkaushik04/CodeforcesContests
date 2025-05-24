#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,t;
    int temp,temp1;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> d;
        vector<pair<int,int>> LandR;
        vector<int*> dynamic;
        int dil=0;
        vector<int> dynamic_indexes;
        vector<int> h;
        int hi=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp==-1){
                int* dyn=new int[3];
                dyn[2]=dil;
                dynamic_indexes.emplace_back(i);
                dynamic.emplace_back(dyn);
                dil++;
            }
            else{
                hi++;
            }
            h.emplace_back(hi);
            d.emplace_back(temp);
        }
        int j=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            cin>>temp1;
            if(h[i]>temp1){
                cout<<"-1"<<endl;
                flag=true;
                break;
            }
            if(i==dynamic_indexes[j]){
                dynamic[j][1]=temp1-h[i];
                dynamic[j][1]=h[i]-temp;
            }
            pair<int,int> p={temp,temp1}; //LandR doing nothing for now
            LandR.emplace_back(p);
        }
        int dynamicSize=dynamic.size();
        if(!flag){
            for(int i=0;i<dynamicSize;i++){
                if(dynamic[i][0]<0){ //hi below li
                    if(i+1<(-dynamic[i][0])){
                        flag=true;
                        cout<<"-1"<<endl;
                        break;
                    }
                    else{
                        for(int j=i;j>=i+dynamic[i][0]+1;j--){
                            //????
                        }
                    }
                }
            }
        }
    }
    return 0;
}