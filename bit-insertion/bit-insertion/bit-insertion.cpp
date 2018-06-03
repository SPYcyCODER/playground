//
//  main.cpp
//  bit-insertion
//
//  Created by Phanindra Saggurthi on 03/06/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}
int clearAndUpdateBit(int n,int m,int j,int i){
    bin(n);
    bin(m);
    int allOnes=~0;
    int left=(allOnes<<(j+1));
    printf("LEFT : \n");
    bin(left);
    int right=((allOnes<<i)-1);
    printf("RIGHT : \n");
    bin(right);
    int mask=right|left;
    printf("MASK : \n");
    bin(mask);
    int n_cleared=n&mask;
    printf("CLEARED : \n");
    bin(n_cleared);
    int m_shifted=m<<i;
    printf("M_SHIFTED : \n");
    bin(m_shifted);
    return n_cleared|m_shifted;
}
int main(void) {
    
    int n=1024,m=19,j=6,i=2;
    bin(clearAndUpdateBit(n,m,j,i));
    return 0;
}
