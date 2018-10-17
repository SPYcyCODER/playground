//
//  main.cpp
//  Arrays
//
//  Created by Phanindra Saggurthi on 17/10/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
using std::cout;
using std::endl;

//Kadane's Algorithm
int getSum(std::vector<int>& A){
    int result=INT_MIN;
    int sum=0;
    for(auto val:A){
        sum += val;
        result=std::max(result,std::max(sum,val));
        if(sum < 0)
            sum=0;
    }
    return result;
}

//Missing number
int missingNumber(std::vector<int>& A){
    int result=1;
    sort(A.begin(),A.end());
    for(auto val:A){
        if(val != result)
            return result;
        result++;
    }
    return result;
}

//subarray with given sum
std::tuple<int,int> getSubArray(std::vector<int>& A,int k){
    std::map<int,std::vector<int>> _mp; // we uses [int,int] for just returning indices
    std::tuple<int,int> result;
    int preSum=0;
    std::vector<int> tmp;
    tmp.push_back(-1);
    _mp[0]=tmp;
    for(int index=0;index<A.size();index++){
        int val=A[index];
        preSum += val;
        if(_mp.find(preSum-k) != _mp.end()){
            //vector<int> startIndices=_mp[preSum-k];
            result=std::make_tuple(_mp[preSum-k][0]+1,index);
            break;
        }
        
        std::vector<int> _tmp;
        if(_mp.find(preSum) != _mp.end())
            _tmp=_mp[preSum];
        _tmp.push_back(index);
        _mp[preSum]=_tmp;
    }
    return result;
}

//sort 0,1,2 -Dutch Flag problem
void dutchFlag(std::vector<int>& A){
    int ind1=0,ind0=0,ind2=(int)A.size()-1;
    while(ind1 <= ind2){
        switch(A[ind1]){
            case 0:
                std::swap(A[ind0++],A[ind1++]);
                break;
            case 1:
                ind1++;
                break;
            case 2:
                std::swap(A[ind1],A[ind2--]);
                break;
        }
    }
}

//Equilibrium point
int equilPoint(std::vector<int>& A){
    int pos=0;
    int totalSum=0;
    for(auto val:A)
        totalSum += val;
    int prevSum = 0;
    for(auto val:A){
        int aSum=(totalSum-(prevSum+val));
        if(aSum == prevSum)
            return pos+1;
        pos++;
        prevSum+=val;
    }
    return -1;
}
//maximum sum increasing subsequence
int getMaxLISSum(std::vector<int>& A){
    int n=static_cast<int>(A.size());
    if(!n)
        return n;
    std::vector<int> aux=A;
    for(int end=1;end<n;end++){
        for(int start=0;start<end;start++){
            if(A[end] > A[start] && aux[end] < aux[start]+A[end])
                aux[end] = aux[start]+A[end];
        }
    }
    int maxVal=0;
    for(auto val:aux)
        maxVal=std::max(maxVal,val);
    return maxVal;
}

//leader elements in the array
void printLeaders(std::vector<int>& A){
    int max_so_far=0;
    int n=static_cast<int>(A.size());
    for(int ind=n-1;ind>=0;ind--){
        if(A[ind] > max_so_far){
            max_so_far=A[ind];
            cout<<max_so_far<<endl;
        }
    }
}

//Minimum Platforms
int minPlatforms(std::vector<int>& arr,std::vector<int>& dep){
    int platCnt=0,maxCnt=0;
    int aSize=static_cast<int>(arr.size());
    int dSize=static_cast<int>(dep.size());
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    
    int a=0,d=0;
    while(a <aSize && d < dSize){
        if(arr[a] <= dep[d]){
            platCnt++;
            a++;
        }else if(dep[d] < arr[a]){
            platCnt--;
            d++;
        }
        maxCnt=std::max(maxCnt,platCnt);
    }
    return maxCnt;
}
//Maximum of all subarrays of size k
std::vector<int> getSubarrayMax(std::vector<int>& A,int k){
    std::vector<int> result;
    int ind=0;
    std::deque<int> dq;
    while(ind < k){
        if(!dq.empty() && A[ind] >= A[dq.back()])
            dq.pop_back();
        
        dq.push_back(ind);
        ind++;
    }
    for(;ind < A.size();ind++){
        result.push_back(A[dq.front()]);
        while(!dq.empty() && A[ind] >= A[dq.back()]){
            dq.pop_back();
        }
        while(!dq.empty() && dq.front() <= ind-k)
            dq.pop_front();
        dq.push_back(ind);
    }
    result.push_back(A[dq.front()]);
    return result;
}
void reverseGroups(std::vector<int>& A,int k){
    int n=static_cast<int>(A.size());
    if(k > n)
        k %= n;
    if(k <= 1)
        return;
    for(int ind=0;ind<n;){
        int start=ind,end=(ind+k)-1;
        if(end >= n)
            end =n-1;
        while(start < end){
            std::swap(A[start++],A[end--]);
        }
        ind+=k;
    }  
}
int main(int argc, const char * argv[]) {
    /*
    --Kadane's Algorithm
    std::vector<int> vals={-2,1,-3,4,-1,2,1,-5,4};
    cout<<getSum(vals)<<endl;
    
    --Missing Number in array
    std::vector<int> vals={1,3,2,4,0};
    cout<<missingNumber(vals)<<endl;
    
     --subarray with given sum
    int ind1,ind2;
    std::vector<int> A={5, 6, 1, -2, -4, 3, 1, 5};
    std::tie(ind1,ind2)=getSubArray(A, 4);
    cout<<ind1<<" "<<ind2<<endl;
    
    --Dutch Flag problem
    std::vector<int> vals{0,2,1,0,1,1,0};
    dutchFlag(vals);
    for(auto val:vals)
        cout<<val<<" ";
    cout<<endl;
    
    --Equillibrium point
    std::vector<int> vals{1,3,5,2,2};//{ -7, 1, 5, 2, -4, 3, 0 };
    cout<<equilPoint(vals)<<endl;
    
     --maximum sum of increasing subsequence
    std::vector<int> vals{1, 101, 2, 3, 100, 4, 5};
    cout<<getMaxLISSum(vals)<<endl;
    
    --Leaders in the array
    std::vector<int> vals{4,11,7,2,0,9,12,3,6,8,1};
    printLeaders(vals);
     
    --Minimum platforms needed for trains
    std::vector<int> arrivals{900,940,950,1100,1500,1800};
    std::vector<int> departures{1900,2000,1120,910,1200,1130};
    cout<<minPlatforms(arrivals, departures)<<endl;
    
     --maximum of all subarrays
    std::vector<int> vals{1,2,3,1,4,5,2,3,6};
    std::vector<int> tmp=getSubarrayMax(vals, 3);
    for(auto val:tmp){
        cout<<val<<" ";
    }
    cout<<endl;
    */
    std::vector<int> vals{1,2,3,4,5,6,7,8};
    reverseGroups(vals,3);
    for(auto val:vals)
        cout<<val<<" ";
    cout<<endl;
}
