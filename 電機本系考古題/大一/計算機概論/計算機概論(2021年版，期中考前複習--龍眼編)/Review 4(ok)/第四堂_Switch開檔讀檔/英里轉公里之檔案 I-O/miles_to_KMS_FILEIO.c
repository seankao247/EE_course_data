/*2019/10/02 convert miles to kilometers*/
#include<stdio.h>
#include<stdlib.h>
#define KMS_PER_MILES 1.609  //conversion constant 1 mile = 1.609 km

int main()
{
    FILE * input;        //pointer to input file
    FILE * output;       //pointer to output file

    float miles = 0;     //distance in miles
    float kms = 0;       //equivalent distance in kilometers

    /*Open the input and output files.*/
    input = fopen("miles.txt","r");
    if(input == NULL)
    {
        printf("Fail\n\n");
        return 0;
    }

    output = fopen("kms.txt","w");

    /*Get and print the value of miles*/
    fscanf(input,"%f",&miles);
    fprintf(output,"The distance in miles is %f\n",miles);

    /*convert the distance to kilometers*/
    kms = KMS_PER_MILES * miles;

    /*Display the distance in kilometers*/
    fprintf(output,"That equals to %f kilometers.",kms);

    /*Close files*/
    fclose(input);
    fclose(output);

    return 0;
}
