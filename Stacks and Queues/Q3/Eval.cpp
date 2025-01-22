/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;

Token numericOperation(Token numTokenA, Token numTokenB, Token opToken)
{
	int answer = 0;
	int a = numTokenA.val;
	int b = numTokenB.val;
	string op = opToken.text;
				
	if(op == "+") answer = a + b;
	else if(op == "-") answer = b - a;
	else if(op == "*") answer = a * b;
	else if(op == "/") answer = b / a;
	
	Token temp;
	temp.val = answer;
	//cout<<endl<<b<<" "<<op<<" "<<a<<" = "<<answer<<endl;
	return temp;
}

int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();
	int answer = 0;

    while (t.tt != eof || !opstack.isEmpty()) 
	{
		//cout<<"\nNext Char is : "<<t;
		if(t.tt == integer)
		{	
			numstack.push(t);
			t = S.getnext();
		}
		else if(t.tt == lptok)
		{	
			opstack.push(t);
			t = S.getnext();
		}
		else if(t.tt == rptok)
		{
			if(opstack.peek().tt == lptok)
			{
				opstack.pop();
				t = S.getnext();
			}
			else
			{
				Token oprand1 = numstack.pop();
				Token oprand2 = numstack.pop();
				numstack.push(numericOperation(oprand1, oprand2, opstack.pop()));
				//numstack.push(numericOperation(numstack.pop(), numstack.pop(), opstack.pop()));
			}
		}
		else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
		{
			
			//cout<<endl<<t<<endl;
			if(!opstack.isEmpty())
			{
				Token top = opstack.peek();
				if(top.tt == lptok)
				{
					opstack.push(t);
					t = S.getnext();
				}
				else if(top.tt == asttok || top.tt == slashtok || top.tt == pltok || top.tt == mitok)
				{
					Token oprand1 = numstack.pop();
					Token oprand2 = numstack.pop();
					numstack.push(numericOperation(oprand1, oprand2, opstack.pop()));
					//numstack.push(numericOperation(numstack.pop(), numstack.pop(), opstack.pop()));
				}
			}
			else
			{
				opstack.push(t);
				t = S.getnext();
			}
		}
		else if (t.tt == asttok || t.tt == slashtok)
		{
			if(!opstack.isEmpty())
			{
				Token top = opstack.peek();
				if(top.tt == lptok)
				{
					opstack.push(t);
					t = S.getnext();
				}
				else if(top.tt == asttok || top.tt == slashtok)
				{
					Token oprand1 = numstack.pop();
					Token oprand2 = numstack.pop();
					numstack.push(numericOperation(oprand1, oprand2, opstack.pop()));
					//numstack.push(numericOperation(numstack.pop(), numstack.pop(), opstack.pop()));
				}
			
				else
				{
					opstack.push(t);
					t = S.getnext();
				}
			}
			else
			{
				opstack.push(t);
				t = S.getnext();
			}
		}
    }
	cout<<numstack.pop().val;

    cout << endl;


    return 0;
}

