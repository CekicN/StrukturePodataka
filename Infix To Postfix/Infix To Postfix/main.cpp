#include"stek.h"
int toInt(char z)
{
	return z - '0';
}
char toChar(int z)
{
	return z + '0';
}
bool isDigit(char z)
{
	return z >= '0' && z <= '9';
}
char* toPostfix(const char* z)
{
	stek a(strlen(z));
	char* rez = new char[strlen(z) + 1];
	int i = 0;
	int j = 0;
	while (z[i] != 0)
	{
		if (!isDigit(z[i]))
		{
			switch (z[i])
			{
			case '(':
				a.push(toInt(z[i]));
				break;
			case '+':
				if (toChar(a.getTop()) == '*' || toChar(a.getTop()) == '/')
				{
					rez[j++] = toChar(a.pop());
				}
				a.push(toInt(z[i]));
				break;
			case '-':
				if (toChar(a.getTop()) == '*' || toChar(a.getTop()) == '/')
				{
					rez[j++] = toChar(a.pop());
				}
				a.push(toInt(z[i]));
				break;
			case '*':
				if (toChar(a.getTop()) == '*' || toChar(a.getTop()) == '/')
				{
					rez[j++] = toChar(a.pop());
				}
				a.push(toInt(z[i]));
				break;
			case '/':
				if (toChar(a.getTop()) == '*' || toChar(a.getTop()) == '/')
				{
					rez[j++] = toChar(a.pop());
				}
				a.push(toInt(z[i]));
				break;
			case '^':
				a.push(toInt(z[i]));
				break;
			default:
				while (toChar(a.getTop()) != '(')
				{
					rez[j++] = toChar(a.pop());
				}
				a.pop();
				break;
			}
		}
		else
		{
			rez[j++] = z[i];
		}
		i++;
	}
	while (a.getBr() != 0)
	{
		rez[j++] = toChar(a.pop());
	}
	rez[j] = '\0';
	return rez;
}

int zbir(const char* z)
{
	stek a(strlen(z));
	int i = 0;
	int c, b;
	while (z[i] != 0)
	{
		switch (z[i])
		{
		case '+':
			c = a.pop();
			b = a.pop();
			a.push(c + b);
				break;
		case '-':
			c = a.pop();
			b = a.pop();
			a.push(c - b);
			break;
		case '*':
			c = a.pop();
			b = a.pop();
			a.push(c * b);
			break;
		case '/':
			c = a.pop();
			b = a.pop();
			a.push(c / b);
			break;
		case '^':
			c = a.pop();
			b = a.pop();
			a.push(c ^ b);
			break;
		default:
			a.push(toInt(z[i]));
			break;
		}
		i++;
	}
	return a.pop();
}
int main()
{
	char* postfix = toPostfix("((a+b)*c/d+e^f)/g");
	cout << postfix<<endl;

	//cout << zbir(postfix);
	return 0;
}