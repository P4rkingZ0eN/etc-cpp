#include <bits/stdc++.h>
using namespace std;
using str=string;
using pid=pair<int,double>;
#include "atomic-weight.h"
int main(){
    SET_DIC();
    while(1){
        string s;cin>>s;
        if(s=="exit")break;
        element_finder(s);
    }
    return 0;
}
