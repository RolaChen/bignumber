#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
<<<<<<< HEAD
using namespace std;

string dezero(string);//erase the zeros in the front of a positive number
int judge(string, string);
string Minus(string, string);
string Divide(string, string);
string Multiply(string, string);
string Add(string, string);

class bignumber
{
public:
	bignumber();
	~bignumber();
	void readline();
	void print();
private:
	string a;
	string b;
	char sign;
=======
#include<stdlib.h>
using namespace std;

string dezero(string);//erase the zeros in the front of a positive number
int judge(string,string); 
string Minus(string,string);
string Divide(string,string);
string Multiply(string,string);
 string Add(string,string);
class bignumber
{
public:
 bignumber();
 ~bignumber();
 void readline();
 void print();
private:
 string a;
 string b;
 char sign;
>>>>>>> f9159e07d644d9f53140b629451b2af7b7220c0c
};

#endif
