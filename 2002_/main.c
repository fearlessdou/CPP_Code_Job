
#include <stdio.h>
#include <math.h>

int DoubleToBinary32(double value)
{
	int minus = 0, integer, exponent = 127, fraction = 0, i, result;

	if (value < 0) { minus = 0x80000000; value = -value; }
	integer = floor(value);
	value -= integer;
	for (i = 22; i >= 0; i--)
	{
		value += value;
		fraction += floor(value) * pow(2, i);
		value -= floor(value);
	}
	while ((integer != 1) && (exponent > 0) && (exponent < 255))
	{
		if (integer > 1)
		{
			fraction = (integer & 1) << 22 + fraction >> 1;
			integer = integer >> 1;
			exponent++;
		}
		else
		{
			integer = (fraction & 0x400000) >> 22;
			fraction = (fraction & 0x3FFFFF) << 1;
			value += value;
			fraction += floor(value);
			value -= floor(value);
			exponent--;
		}
	}
	result = minus + exponent << 23 + fraction;

	return(result);
}

double Binary32ToDouble(int value)
{
	int minus = -1, exponent;
	double fraction, result;

	if (value & 0x80000000 == 0) minus = 1;
	exponent = ((value & 0x7F800000) >> 23) - 127;
	fraction = value & 0x7FFFFF + 0x800000;
	fraction = fraction / 0x800000;
	result = minus * fraction * pow(2, exponent);
	return(result);
}
double ieeNum = 176.0625;
int Result ;
int main()
{
	int print_buff[30] = { 0 };
	Result = DoubleToBinary32(ieeNum);
	printf("%X", Result);
	//sprintf((char*)print_buff, " %d \n", Result);
	//printf((char*)print_buff);
	return 0;
}