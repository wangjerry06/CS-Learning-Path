//gas station
#include<iostream>
#include<vector>
int cancompleteCircuit(std::vector<int>& gas,std::vector<int>& cost){
    int n=(int)gas.size();
    int start=0;
    int res=0;
    int ow=0;
    for(int i=0;i<n;++i){
        int store=gas[i]-cost[i];
        if(res+store<0){
            ow+=res+store;
            res=0;
            if(i<n-1){
                start=n+1;
            }
            else return -1;
            continue;
        }
        else{
            res+=store;
        }
    }
    return (res+ow>=0)?start:-1;
}
int main(){
    int n;
    std::cin>>n;
    std::vector<int> gas(n),cost(n);
    for(int i=0;i<n;++i) std::cin>>gas[i];
    for(int i=0;i<n;++i) std::cin>>cost[i];
    std::cout<<cancompleteCircuit(gas,cost)<<std::endl;
    return 0;
}