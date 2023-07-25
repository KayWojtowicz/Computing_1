#include <stdio.h>

/*
Author: Kay Wojtowicz
Date : 3 / 24 / 2022
Purpose : This code allows the user to choose if they want to convert weight or length or to exit. Then,
	depending on if length or weight is chosen, the user is asked if they would like to convert to metric
	or us. Then the value is converted and the resulting value is produced.
Sources of Help : None
Time spent : 1 hour
*/

int question_inital(void);

void question_convert_lengths(void);

void length_to_metric(void);
double collect_us_length(void);
void convert_to_metric_length();
void display_metric_length();

void length_to_us(void);
double collect_metric_length(void);
void convert_to_us_length();
void display_us_length();

void question_convert_weight(void);

void weight_to_metric(void);
double collect_us_weight(void);
void convert_to_metric_weight();
void display_metric_weight();

void weight_to_us(void);
double collect_metric_weight(void);
void convert_to_us_weight();
void display_us_weight();

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int answer_one;

	do
	{
		answer_one = question_inital();

		if (answer_one == 1)
		{
			question_convert_lengths();
		}
		else if (answer_one == 2)
		{
			question_convert_weight();
		}
	} while (answer_one != 0);

	return 0;
}

int question_inital(void)
{
	int noc;
	int answer;

	do
	{
		printf("Do you want to convert \n \t 0) Quit \n \t 1) Length \n \t 2) weight\n");
		noc = scanf("%d", &answer);
		clear_keyboard_buffer();

		if (answer < 0 || answer > 2)
		{
			printf("I'm sorry that answer is invalid. Please enter either 0, 1, or 2.\n");
		}

	} while (answer < 0 || answer > 2);

	return answer;
}

void question_convert_lengths(void)
{
	int noc;
	int answer;
	do
	{
		do
		{
			printf("Would you like to convert length from \n \t 0) Quit \n \t 1) feet/inches to meters/centimeters \n \t 2) meters/centimeters to feet/inches\n");
			noc = scanf("%d", &answer);
			clear_keyboard_buffer();

			if (answer < 0 || answer > 2)
			{
				printf("I'm sorry that answer is invalid. Please enter either 0, 1, or 2.\n");
			}

		} while (answer < 0 || answer > 2);

		if (answer == 1)
		{
			length_to_metric();
		}
		else if (answer == 2)
		{
			length_to_us();
		}
	} while (answer != 0);

	return;
}

void length_to_metric(void)
{
	double initial_us_length;
	double final_length;

	initial_us_length = collect_us_length();

	convert_to_metric_length(&initial_us_length);

	final_length = initial_us_length;

	display_metric_length(final_length);

	return;
}

double collect_us_length(void)
{
	double noc;
	double feet;
	double inches;
	double length_in_feet;

	printf("Please enter your value in feet and inches to be converted to metric.\n");

	do
	{
		printf("\t feet: ");
		noc = scanf("%lf", &feet);
		clear_keyboard_buffer();
		if (feet < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (feet < 0);

	do
	{
		printf("\t inches: ");
		noc = scanf("%lf", &inches);
		clear_keyboard_buffer();
		if (inches < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero\n");
	} while (inches < 0);

	length_in_feet = feet + (inches / 12.0);

	return length_in_feet;
}

void convert_to_metric_length(double* pFeet)
{
	*pFeet = *pFeet * 0.3048;
	
	return;
}

void display_metric_length(double answer_in_meters)
{
	printf("Answer in meters is %lf\n", answer_in_meters);

	int meters = (int)answer_in_meters;
	double centimeters = (answer_in_meters - meters) * 100;

	printf("The provided length, given in feet and inches, is equivelant to %d meters and %lf centimeters!\n", meters, centimeters);

	return;
}

void length_to_us(void)
{
	double initial_metric_length;
	double final_length;

	initial_metric_length = collect_metric_length();

	convert_to_us_length(&initial_metric_length);

	final_length = initial_metric_length;

	display_us_length(final_length);

	return;
}

double collect_metric_length(void)
{
	double noc;
	double meters;
	double centimeters;
	double length_in_meters;

	printf("Please enter your value in meters and centimeters to be converted to metric.\n");

	do
	{
		printf("\t meters: ");
		noc = scanf("%lf", &meters);
		clear_keyboard_buffer();
		if (meters < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (meters < 0);

	do
	{
		printf("\t centimeters: ");
		noc = scanf("%lf", &centimeters);
		clear_keyboard_buffer();
		if (centimeters < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (centimeters < 0);

	length_in_meters = meters + (centimeters / 100);

	return length_in_meters;
}

void convert_to_us_length(double* pMeters)
{
	*pMeters = *pMeters / 0.3048;

	return;
}

void display_us_length(double answer_in_feet)
{
	int feet = (int)answer_in_feet;
	double inches = (answer_in_feet - feet) * 12.0;

	printf("The provided length, given in meters and centimeters, is equivelant to %d feet and %lf inches!\n", feet, inches);

	return;
}

void question_convert_weight(void)
{
	int noc;
	int answer;

	do
	{
		do
		{
			printf("Would you like to convert weight from \n \t 0) Quit \n \t 1) pounds/ounces to kilograms/grams \n \t 2) kilograms/grams to pounds/ounces\n");
			noc = scanf("%d", &answer);
			clear_keyboard_buffer();

			if (answer < 0 || answer > 2)
			{
				printf("I'm sorry that answer is invalid. Please enter either 0, 1, or 2.\n");
			}
		} while (answer < 0 || answer > 2);

		if (answer == 1)
		{
			weight_to_metric();
		}
		else if (answer == 2)
		{
			weight_to_us();
		}
	} while (answer != 0);

	return;
}

void weight_to_metric(void)
{
	double initial_us_weight;
	double final_weight;

	initial_us_weight = collect_us_weight();

	convert_to_metric_weight(&initial_us_weight);

	final_weight = initial_us_weight;

	display_metric_weight(final_weight);

	return;
}

double collect_us_weight(void)
{
	double noc;
	double pounds;
	double ounces;
	double weight_in_pounds;

	printf("Please enter your value in pounds and ounces to be converted to kilograms.\n");

	do
	{
		printf("\t pounds: ");
		noc = scanf("%lf", &pounds);
		clear_keyboard_buffer();
		if (pounds < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (pounds < 0);

	do
	{
		printf("\t ounces: ");
		noc = scanf("%lf", &ounces);
		clear_keyboard_buffer();
		if (ounces < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (ounces < 0); 
	
	weight_in_pounds = pounds + (ounces / 16.0);

	return weight_in_pounds;
}

void convert_to_metric_weight(double* pPounds)
{
	*pPounds = *pPounds / 2.2046;

	return;
}

void display_metric_weight(double answer_in_kilograms)
{
	int kilograms = (int)answer_in_kilograms;
	double grams = (answer_in_kilograms - (int)answer_in_kilograms) * 1000;

	printf("The provided weight, given in pounds and ounces, is equivelant to %d kilograms and %lf grams!\n", kilograms, grams);

	return;
}

void weight_to_us(void)
{
	double initial_metric_weight;
	double final_weight;

	initial_metric_weight = collect_metric_weight();

	convert_to_us_weight(&initial_metric_weight);

	final_weight = initial_metric_weight;

	display_us_weight(final_weight);

	return;
}

double collect_metric_weight(void)
{
	double noc;
	double kilograms;
	double grams;
	double weight_in_kilograms;

	printf("Please enter your value in kilograms and gram to be converted to pounds.\n");

	do
	{
		printf("\t kilograms: ");
		noc = scanf("%lf", &kilograms);
		clear_keyboard_buffer();
		if (kilograms < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (kilograms < 0);

	do
	{
		printf("\t grams: ");
		noc = scanf("%lf", &grams);
		clear_keyboard_buffer();
		if (grams < 0)
			printf("I'm sorry that value is invalid. Please enter a number greater than or equal to zero");
	} while (grams < 0);
	
	weight_in_kilograms = kilograms + (grams / 1000.0);

	return weight_in_kilograms;
}

void convert_to_us_weight(double* pKilograms)
{
	*pKilograms = *pKilograms * 2.2046;

	return;
}

void display_us_weight(double answer_in_pounds)
{
	int pounds = (int)answer_in_pounds;
	double ounces = (answer_in_pounds - (int)answer_in_pounds) * 16;
	
	printf("The provided weight, given in kilograms and grams, is equivelant to %d pounds and %lf ounces!\n", pounds, ounces);

	return;
}

void clear_keyboard_buffer(void)
{
	char c;
	int noc;

	noc = scanf("%c", &c);

	while (c != '\n')
	{
		noc = scanf("%c", &c);
	}

	return;
}