/*
Author: Kay Wojtowicz
Date: 4/16/2022
Purpose: To take numbers in two files, arranged from smallest to greatest within the file,
	and to place them into a single file going from the smallest number to the largest number.
Sources of help: none
Time spent: 2 hours
*/

#include <stdio.h>
#include <stdlib.h>

void compare_and_order(FILE* input1, FILE* input2, FILE* output);

int main(void)
{
	FILE* fp_numbers1;
	FILE* fp_numbers2;
	FILE* fp_output;

	char numbers1[] = "numbers1.txt";
	char numbers2[] = "numbers2.txt";
	char output[] = "output.txt";

    fp_numbers1 = fopen(numbers1, "r");
    if (fp_numbers1 == NULL)
    {
        printf("Failed to open %s for reading.\n", numbers1);
        exit(1);
    }
    fp_numbers2 = fopen(numbers2, "r");
    if (fp_numbers2 == NULL)
    {
        printf("Failed to open %s for reading.\n", numbers2);
        exit(1);
    }
    fp_output = fopen(output, "w");
    if (fp_output == NULL)
    {
        printf("Failed to open %s for writing.\n", output);
        exit(1);
    }

    compare_and_order(fp_numbers1, fp_numbers2, fp_output);

    fclose(fp_numbers1);
    fclose(fp_numbers2);
    fclose(fp_output);

	return 0;
}

void compare_and_order(FILE* input1, FILE* input2, FILE* output)
{
    int noc_1;
    int number_1;
    int noc_2;
    int number_2;
    int smaller_number;
    int bigger_number;
    int left_over;

    noc_1 = fscanf(input1, "%d", &number_1);
    noc_2 = fscanf(input2, "%d", &number_2);

    while (noc_1 == 1 || noc_2 == 1)
    {
        if (noc_1 == 1 && noc_2 == 1)
        {
            if (number_1 < number_2)
            {
                fprintf(output, "%d\n", number_1);
                noc_1 = fscanf(input1, "%d", &number_1);
            }
            else if (number_1 > number_2)
            {
                fprintf(output, "%d\n", number_2);
                noc_2 = fscanf(input2, "%d", &number_2);
            }

        }
        else if (noc_1 == 1 && noc_2 != 1)
        {
            smaller_number = number_1;
            fprintf(output, "%d\n", smaller_number);
            noc_1 = fscanf(input1, "%d", &number_1);

        }
        else if (noc_1 != 1 && noc_2 == 1)
        {
            smaller_number = number_2;
            fprintf(output, "%d\n", smaller_number);
            noc_2 = fscanf(input2, "%d", &number_2);
        }
    }
    return;
}
