//
//  BigInt.hpp
//  CECS282_Program5
//
//  Created by Jasmin Agustin on 4/4/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#ifndef BigInt_hpp
#define BigInt_hpp

#include <iostream>
#include <vector>
using namespace std;

class BigInt{
    
private:
    vector<int> intVec;
    
public:
    BigInt();
    BigInt operator++(int x);
    bool operator==(BigInt n);
    BigInt(int x);
    BigInt(const string & s);
    friend ostream & operator<<(ostream & out, const BigInt & n);
    void print();
    bool operator<(int x);
    bool operator>(BigInt n);
    bool operator<(BigInt n);
    BigInt operator*=(const BigInt & x);
    BigInt operator+(BigInt n);
    BigInt operator+(int n);
    BigInt operator-(BigInt n);
    friend BigInt operator+(int x, BigInt n);
    BigInt operator*(const BigInt & n)const;
    int size();
    BigInt operator=(int x);
    bool operator!=(BigInt n);
    BigInt operator++();
    BigInt operator+=(const BigInt & x);
    int bigToInt();
};

#endif
