#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    map<int,int> remove;
    int temp1,temp2;
    set<int> specialIndexes1;
    vector<int> l,r;
    int count=0;
    while(t--){
        cin>>n;
        string s(n,'1');
        remove=map<int,int>();
        specialIndexes1=set<int>();
        l=vector<int>();
        r=vector<int>();
        for(int i=0;i<n;i++){
            cin>>temp1>>temp2;
            l.emplace_back(temp1);
            r.emplace_back(temp2);
            if(temp1==temp2){
                if(remove.find(temp1)!=remove.end()){
                    specialIndexes1.insert(i);
                    specialIndexes1.insert(remove[temp1]);
                }
                else{
                    remove[temp1]=i;
                }
            }
        }
        for(int i=0;i<n;i++){
            count=0;
            temp1=l[i],temp2=r[i];
            for(auto element:remove){
                if(element.first>=temp1 && element.first<=temp2 && temp1!=temp2){
                    count++;
                }
            }
            if(count==temp2-temp1+1){
                specialIndexes1.insert(i);
            }
        }
        for(auto index:specialIndexes1){
            s[index]='0';
        }
        cout<<s<<endl;
    }
    return 0;
}