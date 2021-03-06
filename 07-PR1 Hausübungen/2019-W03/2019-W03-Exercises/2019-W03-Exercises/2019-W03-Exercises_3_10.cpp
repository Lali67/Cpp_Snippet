/* 2019-W02-Exercise_3_10.cpp :

Exercise 3.10
  Schreiben Sie ein Programm, das einen ganz simplen Taschenrechner simuliert. 
  Eingegeben wird ein mathematischer Ausdruck, der Zahlen und die bin�ren Operatoren +,-,* und / enth�lt. 
  Der Ausdruck wird durch ein Rufzeichen abgeschlossen. 
  Das Programm soll das Ergebnis des Ausdrucks berechnen, wobei die Operationen strikt von links 
  nach rechts durchzuf�hren sind. (Das heisst, es gilt nicht Punkt- vor Strichrechnung!)
    Z.B.:
          Eingabe: 2+3-4/2*3-1!      Ausgabe: 0.5


D�niel Sz�ke (11913915)
26.10.2019

*/

#include <iostream>
#include <string> //stol

//#include <exception> 

using namespace std;

const string EnabledFirstCharList = "0123456789";
const string EnabledCharList      = "+-/*0123456789!";

inline bool IsEnabledChar(string aString, char c) {
	return std::string(aString).find(c) != std::string::npos;
}


double SimpleCalculator(string mathExpression) {
	double result{ 0.0 }, operand{ 0.0};
	unsigned long counter{ 0 };
	string operandString{""}; 
	char operatorSign{ '_' };

	if (!IsEnabledChar(EnabledFirstCharList, mathExpression[0]))
		throw("Der Ausdruck ist nicht gueltig.");

	//--- Create first number reading digits from mathExpression
	while (counter < mathExpression.length() &&
		mathExpression[counter] >= '0' && mathExpression[counter] <= '9') {
		operandString = operandString + mathExpression[counter];
		counter++;
	}
	result = double(stol(operandString));
	
	while(counter < mathExpression.length()) {
		//--- Check char[counter] whether is valid
		if (!IsEnabledChar(EnabledCharList, mathExpression[counter]))
			throw("Der Ausdruck enthaelt einen irregularen Charakter.");
		
		//Read operator type (+,-,/,*) or end of operation (!)
		operatorSign = mathExpression[counter++];
		
		//--- Create number as operand to an Operation reading digits from mathExpression
		operandString = ""; operand = 0.0;
		while (counter < mathExpression.length() &&
			mathExpression[counter] >= '0' && mathExpression[counter] <= '9') {
			operandString = operandString + mathExpression[counter];
			counter++;
		}
		if(operandString != "") operand = double(stol(operandString));
		
		//--- Make operation according to operatorSign
		switch (operatorSign) {
			case '+':
				result = result + operand;
				break;
			case '-':
				result = result - operand;
				break;
			case '*':
				result = result * operand;
				break;
			case '/':
				result = result / operand;
				break;
			case '!':
				break;
			default:
				//--- If the operator is other than +, -, *, / or !, error message is shown
				throw("Fehler! Ausdruck ist nicht korrekt");
		} //end switch

	}//end while

	return result;
}


int main()
{
	
	
	cout << "------------Test------------" << endl;
	cout << "123!         :  " << SimpleCalculator("123!") << endl;
	cout << "12+50/2!     :  " << SimpleCalculator("12+50/2!") << endl;
	cout << "1+55/13*3+1! :  " << SimpleCalculator("1+55/13*3+1!") << endl;
	cout << endl;
	
	// Get from the data from user to function
	string realString;
	cout << "\n";
	cout << "Bitte geben Sie hier einen mathematischen Ausdruck ein: "; cin >> realString;
	cout << "Resultat: " << SimpleCalculator(realString) << endl;
	
	return 0;
}
