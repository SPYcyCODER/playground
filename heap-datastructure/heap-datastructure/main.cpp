//
//  main.cpp
//  heap-datastructure
//
//  Created by Phanindra Saggurthi on 30/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
// Operations :
//              find MAX
//              extract-max[delete]
//              replace/increase the key val
//              Insert into heap

#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& A,int pos){
    int left=2*pos+1;
    int right=2*pos+2;
    int largest=pos;
    if(left < A.size() && A[left] > A[pos])
        largest=left;
    if(right < A.size() && A[right] > A[largest])
        largest=right;
    if(largest != pos){
        swap(A[pos],A[largest]);
        /*cout<<"In max heapify : ";
        for(auto val:A)
            cout<<val<<" ";
        cout<<endl;*/
        maxHeapify(A,largest);
    }

}
void buildHeap(vector<int>& A){
    size_t len=A.size();
    for(auto val:A)
        cout<<val<<" ";
    cout<<endl;
    for(int pos=(int)len/2-1;pos>=0;pos--)
        maxHeapify(A,pos);
}
int extractMax(vector<int>& A){
    if(A.size() == 0)
        return INT_MIN;
    int maxElem=A[0];
    A[0]=A[A.size()-1];
    A.pop_back();
    maxHeapify(A, 0);
    return maxElem;
}
int getMax(vector<int>& A){
    return A[0];
}

void increaseVal(vector<int>& A,int pos,int val){
    if(val < A[pos]){
        cout<<"ERROR\n";
        return;
    }
    pos--;
    A[pos]=val;
    while(pos > -1 && A[pos/2] < A[pos]){
        swap(A[pos],A[pos/2]);
        pos/=2;
    }
    
}
void insert(vector<int>& A,int new_val){
    A.push_back(new_val);
    increaseVal(A,(int)A.size(), new_val);
}
int main(void) {
    vector<int> vals={1,2,3,4,5,6,7,8,9};
    //Build Heap
    buildHeap(vals);
    cout<<"After building heap : ";
    for(auto val:vals)
        cout<<val<<" ";
    cout<<endl;
    cout<<extractMax(vals)<<endl;
    cout<<getMax(vals)<<endl;
    increaseVal(vals, 4, 25);
    cout<<"After Increasing value in heap : ";
    for(auto val:vals)
        cout<<val<<" ";
    cout<<endl;
    insert(vals,32);
    cout<<"After Inserting value in heap : ";
    for(auto val:vals)
        cout<<val<<" ";
    cout<<endl;
    return 0;
}
