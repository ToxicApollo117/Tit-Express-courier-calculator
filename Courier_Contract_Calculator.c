
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

double conver(char dataset[], int size);
double numconversion(char num);

int main()
{
	char m3arr[20], colarr[20];
	double m3, collateral, price;
	printf("Enter Cargo Volume:");
	scanf("%s", &m3arr);

	int count1 = sizeof(m3arr)/ sizeof(char);
	m3 = conver(m3arr, count1);

	printf("Enter Collateral:");
	scanf("%s", &colarr);
	int count2 = sizeof(colarr) / sizeof(char);
	collateral = conver(colarr, count2);

	int location;
	printf("Select Starting Location: \n Press 1. for Jita \n Press 2. for Obe \n Press 3 for Q-EHMJ\nEnter Location:");
	scanf("%i", &location);
	int multiplyer;

	if (location == 1)
	{
		multiplyer = 600;
	}
	if (location == 2)
	{
		multiplyer = 600;
	}
	if (location == 3)
	{
		multiplyer = 550;
	}	
	price = m3 * multiplyer + collateral * 0.03;

	printf("final price from NSI: %.2lf \n", price);
	printf("Destination: NSI-MW - Stellar Core \n");
	printf("Contract to: Tits Express");
}

double conver(char dataset[], int size)
{
	//int size2 = sizeof(dataset);
	//printf("%d \n", size2);

	double temp = 0;
	double output = 0;
	int decCounter = 1;
	int predecimal = 1;
	for (int a = 0; a <= size; a++){
		if (dataset[a] == NULL)
		{
			dataset[a] = 0;
		}
		if (dataset[a] != ','&& dataset[a] != '.'  && predecimal == 1) {
			temp = numconversion(dataset[a]);
			output = output * 10 + temp;
		}
		else if (dataset[a] == '.') {
			predecimal = 0;
		}
		else if (predecimal == 0 && dataset[a] != ','&& dataset[a] != '.') {
			temp = numconversion(dataset[a]);
			output = output + temp*pow(0.1, decCounter);
			decCounter++;
		}
		
		else if (dataset[a] == ',') {}
	}
	return output;
}

double numconversion(char num)
{
	double out = 0;
	if (num == '0')
	{
		out = 0;
	}
	else if (num == '1')
	{
		out = 1;
	}
	else if (num == '2')
	{
		out = 2;
	}
	else if (num == '3')
	{
		out = 3;
	}
	else if (num == '4')
	{
		out = 4;
	}
	else if (num == '5')
	{
		out = 5;
	}
	else if (num == '6')
	{
		out = 6;
	}
	else if (num == '7')
	{
		out = 7;
	}
	else if (num == '8')
	{
		out = 8;
	}
	else if (num == '9')
	{
		out = 9;
	}

	return out;
}

