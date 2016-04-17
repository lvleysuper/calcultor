#include "calculator.h"

int main()
{
	Calculator TheCalc(Calculator::LOGIC_CALC);
	bool stauts;
	do 
	{
		cout << "> ";
		Input input;
		stauts = TheCalc.Execute(input);
		if(stauts)
		{
			for (StackSeq seq(TheCalc.GetStack());!seq.AtEnd();seq.Advance())
			{
				if (TheCalc.Type() == Calculator::LOGIC_CALC){
					cout << boolalpha << (bool)seq.GetNum() << endl;
				}
				else {
					if (input.Token() == 'x')
						cout << hex << " " << seq.GetNum() << endl;
					else 
						cout << dec <<" " << seq.GetNum() << endl;
				}
			}
		}
	} while (stauts);
}