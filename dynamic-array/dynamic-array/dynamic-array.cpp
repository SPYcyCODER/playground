//
//  main.cpp
//  dynamic-array
//
//  Created by Phanindra Saggurthi on 10/06/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXPKT 3
struct packet{
    int aTime,pktLen;
    packet(int time,int len):aTime(time),pktLen(len){
    }
};
class queue{
private:
    packet **ptr;
public:
    queue(){
        ptr=new packet*[MAXPKT];
        int t=0,l=0;
        for(int in=0;in<MAXPKT;in++){
            ptr[in]=new packet(t++,l++);
            cout<<"allocating :"<<ptr[in]->aTime<<" "<<ptr[in]->pktLen<<endl;
        }
    }
    
    ~queue(){
        for(int in=0;in<MAXPKT;in++){
            cout<<"deallocating :"<<ptr[in]->aTime<<" "<<ptr[in]->pktLen<<endl;
            delete ptr[in];
        }
    }
};
void printPackets(packet* ptr){
   // for(int pos=0;pos<MAXPKT;pos++){
        cout<<ptr->aTime<<" "<<ptr->pktLen<<endl;
     //   ptr++;
    //}
}
int main(int argc, const char * argv[]) {
    queue _qObj;
    packet** ptr;
    ptr=new packet*[2];
    ptr[0]=new packet(2,4);
    ptr[1]=new packet(5,6);
    ptr[2]=new packet(7,8);
    for(int pos=0;pos<MAXPKT;pos++){
        printPackets(*ptr);
        ptr++;
    }
    return 0;
}
