//
//  PowerTools.cpp
//  CECS282_Program5
//
//  Created by Jasmin Agustin on 4/4/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#include "BigInt.hpp"
#include "PowerTools.hpp"
#include <iostream>
#include <map>
using namespace std;

int fibo(int n){
    static map<int, int> fiboMap;
    if(fiboMap.find(n) != fiboMap.end())
        return fiboMap[n];
    if(n == 0 || n == 1)
        return 1;
    else
        return fiboMap[n] = fibo(n-1) + fibo(n-2);
}

int fact(int n){
    if(n > 16)
        throw n;
    if(n == 0)
        return 1;
    else return n * fact(n-1);
}

int exp(int x, int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    else
        return x * exp(x, y-1);
}

BigInt fibo(BigInt Bn){
    
    static map<int, BigInt> fiboMap;
    fiboMap[0] = BigInt(1);
    fiboMap[1] = BigInt(1);
    if(Bn == BigInt(0) || Bn == BigInt(1))
        return fiboMap[1];
    else if(fiboMap.find(Bn.bigToInt()) == fiboMap.end()){
        BigInt result = fibo(Bn-BigInt(1)) + fibo(Bn-BigInt(2));
        fiboMap[Bn.bigToInt()] = result;
        return fiboMap[Bn.bigToInt()];
    }
    else
        return fiboMap[Bn.bigToInt()];
}

BigInt fact(BigInt Bn){
    BigInt factorial(1);
    for(BigInt i = BigInt(1); i < Bn+BigInt(1); i++){
        factorial *= i;
    }
    return factorial;
}

BigInt exp(BigInt Bx, BigInt By){
    if (By == BigInt(0))
        return BigInt(1);
    if (By == BigInt(1))
        return Bx;
    else
        return Bx * exp(Bx, By-BigInt(1));
}

BigInt exp(BigInt Bx, int y){
    if (BigInt(y) == BigInt(0))
        return BigInt(1);
    if (BigInt(y) == BigInt(1))
        return Bx;
    else
        return Bx * exp(Bx, y-1);
}

BigInt UniverseMiles(){
    BigInt lightYearPerMile("9300000");//0000
    BigInt daysPerYear(3652425);//365.2425
    BigInt hourPerDay(24);
    BigInt minPerHour(60);
    BigInt secPerMin(60);
    BigInt milesPerSec(186282);
    BigInt totalMiles = lightYearPerMile * daysPerYear * hourPerDay * minPerHour * secPerMin * milesPerSec;
    return totalMiles;
}
