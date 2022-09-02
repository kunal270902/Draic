#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int>v;vector<pair<int,int>>ans;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        v.push_back(z);
    }
    int sum=accumulate(v.begin(),v.end(),0);
    for(int i=0;i<n;i++){
        for(int  j=i+1;j<n;j++){
            if(v[i]+v[j]>sum){
                ans.push_back({v[i],v[j]});
            }
        }
    }
    vector<pair<int,int>>::iterator it;
    cout<<'[';
    for(it=ans.begin();it!=ans.end()-1;it++){
        cout<<'['<<it->first<<", "<<it->second<<"], ";
    }
    
    cout<<'['<<ans[ans.size()-1].first<<", "<<ans[ans.size()-1].second<<']';
    cout<<']';
    return 0;
}
