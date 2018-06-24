#include <iostream>
#include <vector>

int main(void){
    std::vector<int> v1={2,1,7,3,5,6,2,9,2,1,5,2,3};
    
    int pivot=v1[1];
    int small=0,equal=0,larger=(int)v1.size();
    for(auto val:v1)
        std::cout<<val<<" ";
    std::cout<<"\n";
    while(equal < larger){
        if(v1[equal] < pivot){
            std::swap(v1[small++],v1[equal++]);
        }else if(v1[equal] == pivot){
            ++equal;
        }else{
            std::swap(v1[--larger],v1[equal]);
        }
    }
    for(auto val:v1)
        std::cout<<val<<" ";
    std::cout<<"\n";
    pivot=2;
    small=0;
    for(int ind=0;ind<v1.size();ind++){
        if(v1[ind] == pivot){
            std::swap(v1[small++],v1[ind]);
        }
    }
    for(auto val:v1)
        std::cout<<val<<" ";
    std::cout<<"\n";
}
