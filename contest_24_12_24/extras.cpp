#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

int main() {
    long long x=1000000000000000000;
    int i=0;
    while(x!=0){
        x/=4;
        i++;
    }
    i--;
    cout<<pow(2,i)<<endl;
    return 0;
}


