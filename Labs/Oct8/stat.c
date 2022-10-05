#include <stdio.h>
#include <math.h>

int getInt(char prompt[]);
void getData(char prompt[], int array[], int size);
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev);
void printResults(double mean, double stdDev);

int main(void) {
	int size = getInt("Enter the array size:\n");
	int array[size];
	getData("Enter the numbers:\n", array, size);
	
	double mean, stdDev;
	calcMeanStdDev(array, size, &mean, &stdDev);
	printResults(mean, stdDev);
	
	return 0;
}

// YOUR CODE BELOW HERE
int getInt(char prompt[]){
	printf("%s",prompt);
	int s=0;
	scanf("%d",&s);
	return s;
}

void getData(char prompt[], int array[], int size){
	printf("%s",prompt);
	for(int i=0;i<size;i++){
		int num;
		scanf("%d",&num);
		array[i] = num;
	}
}

void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev){
	double sum = 0;
	int count = 0;
	for(int i=0;i<size;i++){
		sum += array[i];
		count++;
	}

	*pMean = ((double)(sum/count));\
	double diffSum = 0;
	for(int i=0;i<size;i++){
		int thing = array[i];
		double diff = ((double) thing -*pMean);
		double add = pow(diff,2);
		diffSum+=add;

	}
	*pStdDev = sqrt((double)diffSum/count);
}

void printResults(double mean, double stdDev){
	printf("The mean is %.2lf and the standard deviation is %.2lft\n",mean,stdDev);
}