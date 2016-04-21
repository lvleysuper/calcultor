#ifndef __CALC_H__
#define __CALC_H__

#include <iostream>
using namespace std;

const int hashTableSize = 127;
int hash(const char* str)
{
	unsigned h  = str[0];
	for (int i=1;str[i]!=0;++i)
	{
		h = (h << 4) + str[i];
	}
	return h % hashTableSize;
}

const int maxBuf = 256;
class IStack 
{
public:
	bool IsFull() { return _done;}
	bool IsEmpty() {return _done;}
	void Push(int num){} 
	int Pop() {return 1;}
private:
	bool _done;
};

class StackSeq
{
public:
	StackSeq(const IStack& stack):_stack(stack),_done(false) {
		cout <<"create stack sequencer " << endl;
	}
	bool AtEnd() const {
		return _done;
	}
	void Advance(){
		_done = true;
	}

	int GetNum(){
		return 13;
	}

private:
	const IStack& _stack;
	bool _done;
};


class Input
{
public:
	enum Token {tokNumber,tokError};
	Input(){
		cout <<"create input " << endl;
	}
	int Token() const {
		return _token;
	}
	int Number() const {return 0;}

private:
	int _token;
	char _buf[maxBuf];
};

class Calculator
{
public:
	Calculator():_done(false){
		cout <<"create calculator " <<endl;
	}
	int Calculate(int num1,int num2,char token);
	bool Execute(Input& input);
	const IStack& GetStack() {
		_done = true;
		return _stack;
	}
private:
	IStack _stack;
	bool _done;
};



#endif