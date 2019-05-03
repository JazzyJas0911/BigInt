//
//  BigInt.cpp
//  CECS282_Program5
//
//  Created by Jasmin Agustin on 4/4/17.
//  Copyright © 2017 Jasmin Agustin. All rights reserved.
//

#include "BigInt.hpp"

#include <sstream>

#include <vector>
#include <iostream>
using namespace std;

BigInt:: BigInt(int x){
    while(x > 0){
        int number = x % 10;
        intVec.push_back(number);
        x /= 10;
    }
}

BigInt:: BigInt(const string & s){
    char cDigits[100000];
    int iDigits[100000];
    for(int i = 0; i < s.length(); i++){
        cDigits[i] = s[i];
        iDigits[i] = cDigits[i] - '0';
    }
    for(int i = 0; i < s.length(); i++){
        intVec.insert(intVec.begin(), iDigits[i]);
    }
}

bool BigInt:: operator==(BigInt n){
    if(n.intVec.size() == this->intVec.size()){
        for(int i = 0; i < this->intVec.size(); i++){
            if(n.intVec[i] != this->intVec[i])
                return false;
        }
        return true;
    }
    return false;
}

BigInt BigInt:: operator++(int x){
    int sum = intVec[0] + 1;
    int newdigit = sum % 10;
    int carry = sum / 10;
    intVec[0] = newdigit;
    int i = 1;
    while(i < intVec.size() && carry != 0){
        sum = intVec[i] + carry;
        newdigit = sum % 10;
        carry = sum / 10;
        intVec[i] = newdigit;
        i++;
    }
    if (carry != 0)
        intVec.push_back(carry);
    return *this;
}

void BigInt:: print(){
    reverse(intVec.begin(), intVec.end());
    vector <int> :: iterator vi;
    for(vi = intVec.begin(); vi != intVec.end(); vi++){
        cout << *vi;
    }
    cout << " " << endl;
}

bool BigInt:: operator<(int x){
    BigInt num(x);
    if(this->intVec.size() != num.intVec.size())
        return this->intVec.size() < num.intVec.size();
    for(int i = 0; i < this->intVec.size(); i++){
        if(this->intVec[i] < num.intVec[i])
            return true;
    }
    return false;
}

bool BigInt:: operator>(BigInt n){
    if(this->intVec.size() != n.intVec.size())
        return this->intVec.size() > n.intVec.size();
    for(int i = 0; i < this->intVec.size(); i++){
        if(this->intVec[i] > n.intVec[i])
            return true;
    }
    return false;
}

ostream & operator<<(ostream & out, const BigInt & n){
    BigInt temp(n);
    std::vector<int>::reverse_iterator rit;
    if(n.intVec.size() < 21){
        for (rit = temp.intVec.rbegin(); rit < temp.intVec.rend(); ++rit) {
            out << *rit;
        }
    }
    else{
        for (rit = temp.intVec.rbegin(); rit < temp.intVec.rbegin()+10; ++rit) {
            out << *rit;
        }
        out << "...";
        for (rit = temp.intVec.rend()-10; rit < temp.intVec.rend(); ++rit) {
            out << *rit;
        }
        out << "[size: " << n.intVec.size() << "]";
    }
    return out;
}

BigInt BigInt::operator+(BigInt n){
    bool in = true;
    BigInt left(*this);
    BigInt right(n);
    BigInt result(1);
    result.intVec.clear();
    int x = 0;
    int y = 0;
    int vector = 0;

    int overhead = 0;
    int longest = left.intVec.size() < right.intVec.size() ? right.intVec.size():left.intVec.size();
    
    for (int counter = 0; counter < longest; counter++) {
        if(counter < left.intVec.size() && counter < right.intVec.size()){
            x = left.intVec[counter];
            y = right.intVec[counter];
        }
        if(counter >= left.intVec.size()){
            x = 0;
            y = right.intVec[counter];
        }
        if(counter >= right.intVec.size()){
            x = left.intVec[counter];
            y = 0;
        }
        
        vector = x + y + overhead;
        
        if(vector > 9){
            overhead = 1;
            result.intVec.push_back(vector%10);
        }
        else{
            overhead = 0;
            result.intVec.push_back(vector);
        }
    }
    if (overhead == 1) {
        result.intVec.push_back(1);
    }
    for(int g =(result.intVec.size()-1); g >= 0; g--){
        if(result.intVec[g] != 0)
            in = false;
        if(in)
            result.intVec.erase(result.intVec.begin() + g);
    }
    return result;
}

BigInt BigInt::operator+(int n){
    BigInt left(*this);
    BigInt right(n);
    return left + right;
}

BigInt BigInt::operator-(BigInt n){
    bool in = true;
    BigInt left(*this);
    BigInt right(n);
    BigInt result(1);
    int x = 0;
    int y = 0;
    if(n > *this)
        return result;
    result.intVec.clear();
    int overhead = 0;
    for (int counter = 0; counter < left.size(); counter++) {
        x = left.intVec[counter];
        if(counter < right.intVec.size())
            y = right.intVec[counter] + overhead;
        if ( counter >= right.intVec.size())
            y = overhead;
        if(y > x){
            x += 10;
            overhead = 1;
        }
        else overhead = 0;
        
        int val = x - y;
        result.intVec.push_back(val);
    }
    for(int g =(result.intVec.size()-1) ; g >= 0; g--){
        if(result.intVec[g] != 0)
            in = false;
        if(in)
            result.intVec.erase(result.intVec.begin() + g);
    }
    return result;
}

int BigInt::size(){
    return intVec.size();
}

BigInt BigInt::operator*(const BigInt& bi2)const{
    const int prodsize = bi2.intVec.size() + intVec.size() + 1;
    BigInt temp(0);
    temp.intVec.resize(prodsize);
    unsigned long int x;
    int iplusj;
    for (int i = 0; i < intVec.size(); i++){
        for (int j = 0; j < bi2.intVec.size(); j++){
            x = bi2.intVec[j] * intVec[i];
            iplusj = i + j;
            temp.intVec[iplusj] += x % 10;
            temp.intVec[iplusj + 1] = temp.intVec[iplusj] / 10 + x / 10 + temp.intVec[iplusj + 1];
            temp.intVec[iplusj] %= 10;
        }
    }
    for (int g = temp.intVec.size() - 1; g >= 0; g--){
        if (temp.intVec[g] == 0)
            temp.intVec.pop_back();
        else if (temp.intVec[g]>0)
            break;
    }
    return temp;
}

bool BigInt:: operator<(BigInt n){
    if(this->intVec.size() != n.intVec.size())
        return this->intVec.size() < n.intVec.size();
    for(int i = 0; i < this->intVec.size(); i++){
        if(this->intVec[i] < n.intVec[i])
            return true;
    }
    return false;
}

BigInt BigInt:: operator*=(const BigInt & x){
    *this = *this*x;
    return *this;
}

BigInt BigInt:: operator=(int x){
    intVec.clear();
    int temp = x;
    do{
        intVec.push_back(temp%10);
        temp /= 10;
    }while(temp != 0);
    return *this;
}

bool BigInt:: operator!=(BigInt n){
    if(n.intVec.size() == this->intVec.size()){
        for(int i = 0; i < this->intVec.size(); i++){
            if(n.intVec[i] != this->intVec[i])
                return true;
        }
        return false;
    }
    return true;
}

BigInt BigInt:: operator++(){
    int sum = intVec[0] + 1;
    int newdigit = sum % 10;
    int carry = sum / 10;
    intVec[0] = newdigit;
    int i = 1;
    while(i < intVec.size() && carry != 0){
        sum = intVec[i] + carry;
        newdigit = sum % 10;
        carry = sum / 10;
        intVec[i] = newdigit;
        i++;
    }
    if (carry != 0)
        intVec.push_back(carry);
    return *this;
}

BigInt BigInt:: operator+=(const BigInt & x){
    *this = *this+x;
    return *this;
}

BigInt:: BigInt(){
    intVec.push_back(0);
}

int BigInt:: bigToInt(){
    BigInt b(*this);
    reverse(b.intVec.begin(), b.intVec.end());
    int x = 0;
    for(int i = 0; i < b.intVec.size(); i++){
        x = 10 * x + b.intVec[i];
    }
    return x;
}
