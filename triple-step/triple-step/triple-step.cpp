//
//  main.cpp
//  triple-step
//
//  Created by Phanindra Saggurthi on 07/06/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
// CTCI 8.1

#include <iostream>
#include <vector>
void getStepCount(int stepCnt,int n,int& cnt){
    if(stepCnt == n){
        cnt++;
        return;
    }
    for(int step=1;step<=3;step++){
        if(stepCnt+step > n)
            break;
        getStepCount(stepCnt+step, n, cnt);
    }
}
int countWays(int n,std::vector<int> memo){
    if(n < 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(memo[n] > -1)
        return memo[n];
    memo[n]=countWays(n-1, memo)+countWays(n-2, memo)+countWays(n-3, memo);
    return memo[n];
}
int main(int argc, const char * argv[]) {
    int cnt=0;
    getStepCount(0, 5, cnt);
    std::cout<<"To reach 5 , number of ways are : "<<cnt<<std::endl;
    std::vector<int> memo(6,-1);
    std::cout<<"To reach 5, using memoisation : "<<countWays(5, memo)<<std::endl;
    return 0;
}
