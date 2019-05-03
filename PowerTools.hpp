//
//  PowerTools.hpp
//  CECS282_Program5
//
//  Created by Jasmin Agustin on 4/4/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#ifndef _PowerTools
#define _PowerTools
#include "BigInt.hpp"

#include <iostream>
using namespace std;


int fibo(int n);
int fact(int n);
int exp(int x, int y);

BigInt fibo(BigInt Bx);
BigInt fact(BigInt Bx);
BigInt exp(BigInt Bx, BigInt By);
BigInt exp(BigInt Bx, int y);
BigInt UniverseMiles();

#endif

