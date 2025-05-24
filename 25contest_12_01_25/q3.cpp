#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<unordered_map>
#include<algorithm>
#define INT32_MIN -2147483648

using namespace std;

int main(){
    int t;
    cin>>t;
    int m,n;
    string s;
    long long temp;
    int tempRow,tempColumn;
    unordered_map<int,long long> rowSum,columnSum;
    unordered_map<int,vector<int>> missingRow,missingColumn;
    while(t--){
        cin>>m>>n;
        cin>>s;
        vector<vector<long long>> vec(m);
        for(int i=0;i<m;i++){
            rowSum[i]=0;
            for(int j=0;j<n;j++){
                if(i==0){
                    columnSum[j]=0;
                }
                cin>>temp;
                rowSum[i]+=temp;
                columnSum[j]+=temp;
                vec[i].emplace_back(temp);
            }
        }
        tempRow=0,tempColumn=0;
        missingRow[0]={0};
        missingColumn[0]={0};
        for(char ch:s){
            if(ch=='D'){
                tempRow++;
                if(missingColumn.find(tempRow)!=missingColumn.end()){
                    missingRow[tempRow].emplace_back(tempColumn);
                }
                else{
                    missingRow[tempRow]={tempColumn};
                }
                if(missingColumn.find(tempRow)!=missingColumn.end()){
                    missingRow[tempColumn].emplace_back(tempRow);
                }
                else{
                    missingColumn[tempColumn]={tempRow};
                }
            }
            else{
                tempColumn++;
                if(missingColumn.find(tempRow)!=missingColumn.end()){
                    missingRow[tempRow].emplace_back(tempColumn);
                }
                else{
                    missingRow[tempRow]={tempColumn};
                }
                if(missingColumn.find(tempRow)!=missingColumn.end()){
                    missingRow[tempColumn].emplace_back(tempRow);
                }
                else{
                    missingColumn[tempColumn]={tempRow};
                }
            }
        }
        vector<vector<long long>> b=vec;
        while(missingRow.size()!=0 && missingColumn.size()!=0){
            bool flag=false;
            tempRow=INT32_MIN;
            for (const auto& pair : missingRow) {
                if (pair.second.size() == 1) {  
                    tempRow=pair.first;
                    tempColumn=pair.second[0];
                    cout<<"1temp row:"<<tempRow<<endl<<"temp column:"<<tempColumn<<endl;
                    b[pair.first][pair.second[0]]=-rowSum[pair.first];
                    flag=true;
                    break;
                }
            }
            if(tempRow!=INT32_MIN){
                auto it1 = find(missingRow[tempRow].begin(), missingRow[tempRow].end(), tempColumn);
                if (it1 != missingRow[tempRow].end()) {
                    missingRow[tempRow].erase(it1);
                }
                if(missingRow[tempRow].size()==0){
                    missingRow.erase(tempRow);
                }
                columnSum[tempColumn]-=rowSum[tempRow];
                rowSum[tempRow]=0;
                auto it2 = find(missingColumn[tempColumn].begin(), missingColumn[tempColumn].end(), tempRow);
                if (it2 != missingColumn[tempColumn].end()) {
                    missingColumn[tempColumn].erase(it2);
                }
                if(missingColumn[tempColumn].size()==0){
                    missingColumn.erase(tempColumn);
                }
            }
            if(flag){
                continue;
            }
            tempRow=INT32_MIN;
            for (const auto& pair : missingColumn) {
                if (pair.second.size() == 1) {  
                    tempColumn=pair.first;
                    tempRow=pair.second[0];
                    cout<<"2temp row:"<<tempRow<<endl<<"temp column:"<<tempColumn<<endl;
                    b[pair.first][pair.second[0]]=-columnSum[pair.first];
                    flag=true;
                    break;
                }
            }
            if(tempRow!=INT32_MIN){
                auto it1 = find(missingRow[tempRow].begin(), missingRow[tempRow].end(), tempColumn);
                if (it1 != missingRow[tempRow].end()) {
                    missingRow[tempRow].erase(it1);
                }
                if(missingRow[tempRow].size()==0){
                    missingRow.erase(tempRow);
                }
                columnSum[tempColumn]-=rowSum[tempRow];
                rowSum[tempRow]=0;
                auto it2 = find(missingColumn[tempColumn].begin(), missingColumn[tempColumn].end(), tempRow);
                if (it2 != missingColumn[tempColumn].end()) {
                    missingColumn[tempColumn].erase(it2);
                }
                if(missingColumn[tempColumn].size()==0){
                    missingColumn.erase(tempColumn);
                }
            }
        }
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    }

    return 0;
}