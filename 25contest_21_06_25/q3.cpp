#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long n, m;
        cin>>n>>m;
        long long minsum=n;
        long long maxsum=(long long)n*(n+1)/2;
        if(m<minsum || m>maxsum) {
            cout<<-1<<endl;
            continue;
        }
        int root=1;
        for(int r=1; r<=n; ++r) {
            long long low=n+(long long)r*(r-1)/2;
            long long high=(long long)r*n-(long long)r*(r-1)/2;
            if(m>=low && m<=high) {
                root=r;
                break;
            }
        }
        long long current=(long long)root*n-(long long)root*(root-1)/2;
        long long remaining=current-m;
        vector<pair<int,int>> edges;
        edges.reserve(n-1);
        for(int i=1; i<root; ++i) edges.emplace_back(root,i);
        for(int v=root+1; v<=n; ++v) {
            if(remaining>0) {
                long long take=min((long long)root-1,remaining);
                int parent=root-(int)take;
                edges.emplace_back(parent,v);
                remaining-=take;
            } else {
                edges.emplace_back(root,v);
            }
        }

        cout<<root<<endl;
        for(auto &e : edges) cout<<e.first<<" "<<e.second<<endl;
    }

    return 0;
}
