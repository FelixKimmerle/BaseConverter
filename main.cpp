#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
const char *set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

unsigned long long int CharToNumber(const char &val)
{
	if (val == 124)
	{
		return 0;
	}
	if (val > 47 && val < 58)
	{
		return val - 48;
	}
	if (val > 64 && val < 91)
	{
		return val - 55;
	}
	if (val > 96 && val < 123)
	{
		return val - 61;
	}
	switch(val)
	{
		case 43:
			return 62;
		break;
		case 47:
			return 63;
		break;
	}
	std::cerr << val << " : is not a valid character" << std::endl;
	return 0;
}

unsigned long long int ToBinary(int base, const std::string &text) //So the c++ programm can calculate
{
	if (base == 1)
	{
		return text.length();
	}
	else
	{
		unsigned long long int num = 0;
		for (size_t i = 0; i < text.length(); i++)
		{
			num += CharToNumber(text[i]) * std::pow(base, text.length() - i - 1);
		}
		return num;
	}
}

std::string ToBaseNFromM(int n, int m, std::string text)
{
	if (n == 1)
	{
		unsigned long long int num = ToBinary(m, text);
		return std::string(num, '|');
	}
	else
	{
		std::string r;
		unsigned long long int num = ToBinary(m, text);
		while (num != 0) {
			r = set[num % n] + r;
			num /= n;
		}
		if(r.size() == 0)
                {
                        r = "0";
                }
		return r;
	}
}

std::string ToBaseNFromM(int n, unsigned long long int value)
{
	if (n == 1)
	{
		return std::string(value, '|');
	}
	else
	{
		std::string r;
		while (value != 0) {
			r = set[value % n] + r;
			value /= n;
		}
		if(r.size() == 0)
		{
			r = "0";
		}
		return r;
	}
}

int ToBaseNFromM(int m, std::string text)
{
	return ToBinary(m, text);
}

unsigned long long int StringToInt(std::string val)
{
	unsigned long long int num = 0;
	size_t length = val.length();
	if(length > 0)
	{
        	for (size_t i = 0; i < length; i++)
        	{
			int digit = (((int)val[i])-48);
			if(digit > 9 || digit < 0)
			{
				std::cerr << "Base 10 numbers can only be between 0 and 9" << std::endl;
				exit(0);
			}
			else
			{
				num += digit * std::pow(10, length - i - 1);
			}
        	}
	}
        return num;

}

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		std::cerr << "Usage: " << argv[0] << " <outputbase> <input> [<inputbase>]" << std::endl;
	}
	else
	{
		if(argc == 3)
		{
			int basen = StringToInt(argv[1]);

                        if(basen > 64 || basen < 1)
                        {
                                std::cerr << "a base must be in the area between 1 and 64" << std::endl;
                        }
			else
			{
				std::cout << ToBaseNFromM(basen,StringToInt(argv[2])) << std::endl;
			}
		}
		else if(argc >= 4)
		{
			int basen = StringToInt(argv[1]);
			if(std::string(argv[3]) == "-a")
			{
				int value = ToBaseNFromM(basen,argv[2]);
				for(int i = 2;i <= 62;i++)
				{
					std::cout << "Base: " << ((i<10) ?" ":"") << i << " " << ToBaseNFromM(i,value) << std::endl;
				}
			}
			else
			{
				int basem = StringToInt(argv[3]);
				if(basen > 64 || basen < 1 || basem > 64 || basem < 1)
				{
					std::cerr << "a base must be in the area between 1 and 64" << std::endl;
				}
				else
				{
					std::cout << ToBaseNFromM(basen,basem,argv[2]) << std::endl;
				}
			}
		}
	}
	return 0;
}
