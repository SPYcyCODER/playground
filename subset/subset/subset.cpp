//
//  main.cpp
//  subset
//
//  Created by Phanindra Saggurthi on 11/06/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
// CTCI 8.4 PowerSet

#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int>& A){
    int n=A.size();
    for(int i=0;i<(1<<n);i++){
        cout<<"(";
        for(int j=0;j<n;j++){
            if((i&(1<<j)) > 0)
                cout<<A[j]<<" ";
        }
        cout<<")\n";
    }
}
int main(int argc, const char * argv[]) {
    vector<int> A{1,2,3};
    subsets(A);
    return 0;
}
