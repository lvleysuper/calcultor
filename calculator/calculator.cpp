#include "calculator.h"
#include <assert.h>


bool Calculator::Execute( Input& input )
{
	int token = input.Token();
	bool status = false;

	if(token == Input::tokError ){
		cout <<"Unknown token " << endl;
	}
	else if(token == Input::tokNumber){
		if(_stack.IsFull()){
			cout <<"Stack is full " << endl;
		}
		else{
			_stack.Push(input.Number());
			status = true;
		}
	}
	else{
		assert(token == '+' ||token == '-' ||token == '*' ||token == '/');
		if(_stack.IsEmpty()){
			cout <<"Stack is empty " << endl;
		}
		else{
			int num2 = _stack.Pop();
			int num1 =0;
			if(_stack.IsEmpty())
				num1 = num2;
			else 
				num1 = _stack.Pop();

			_stack.Push(Calculate(num1,num2,token));
			status = true;
		}
	}

	return status;
}

int Calculator::Calculate( int num1,int num2,char token )
{
	int result;
	if(token == '+'){
		result = num1 + num2;
	}
	else if(token == '-'){
		result = num1 - num2;
	}
	else if(token == '*'){
		result = num1 * num2;
	}
	else if(token == '/'){
		if(num2 == 0){
			cout <<"Division by zero" << endl;
			result = 0;
		}
		else 
			result = num1 / num2;
	}

	return result;
}

