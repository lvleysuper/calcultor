#ifndef __CALC_H__
#define __CALC_H__

#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

const int maxBuf = 256;
const int maxStackSize = 256;
class StackSeq;
class IStack 
{
public:
	friend class StackSeq;
	IStack() :_top(0){}
	bool IsFull() { return _top == maxStackSize;}
	bool IsEmpty() {return _top == 0;}
	void Push(int num){
		assert(_top < maxStackSize-2);
		_arr[_top++] = num;
	} 
	int Pop() {
		assert(_top > 0);
		return _arr[--_top];
	}
private:
	int _top;
	int _arr[maxStackSize];
};

class StackSeq
{
public:
	StackSeq(const IStack& stack):_stack(stack),_iCur(0) {
	}
	bool AtEnd() const {
		return _iCur == _stack._top;
	}
	void Advance(){
		assert(!AtEnd());
		++_iCur;
	}

	int GetNum(){
		assert(!AtEnd());
		return _stack._arr[_iCur];
	}

private:
	const IStack& _stack;
	int _iCur;
};


class Input
{
public:
	enum Token {tokNumber,tokError};
	Input();
	int Token() const {
		return _token;
	}
	int Number() const {
		assert(_token == tokNumber);
		return atoi(_buf);
	}

private:
	int _token;
	char _buf[maxBuf];
};

class Calculator
{
public:
	int Calculate(int num1,int num2,char token);
	bool Execute(Input& input);
	const IStack& GetStack() {
		return _stack;
	}
private:
	IStack _stack;
};




#endif