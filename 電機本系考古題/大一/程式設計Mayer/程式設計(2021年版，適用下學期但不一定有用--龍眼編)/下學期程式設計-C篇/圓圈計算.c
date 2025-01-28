#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct circle{
	float x;
	float y;
	float r;
}CIRCLE;

void check_point(CIRCLE data[], int count, int x, int y);

void main(){
	int count, i, func = 1;
	float x, y;

	printf("How much circle do you want?\n");
	scanf("%d", &count);

	CIRCLE data[count];

	printf("Please enter their parameters(x-axis/y-axis/radius)\n");

	for(i = 0; i < count; i++){
		printf("Circle %d:\n", i+1);
		printf("x:");
		scanf("%f", &data[i].x);
		printf("y:");
		scanf("%f", &data[i].y);
		printf("r:");
		scanf("%f", &data[i].r);
	}

	while(1){
		printf("Do you want to check any point? (yes:1; no:0) : ");
		scanf("%d", &func);

		if(func != 1){
			printf("bye bye!\n\n");
			break;
		}

		printf("Enter a point(x y): ");
		scanf("%f %f", &x, &y);

		check_point(data, count, x, y);
	}

	/*print all circle
	for(i = 0; i < count; i++){
		printf("%f\t%f\t%f\n", data[i].x, data[i].y, data[i].r);
	}
	*/
}

void check_point(CIRCLE data[], int count, int x, int y){
	int i, tmp = 0;
	float upper, lower, xrange;

	for(i = 0; i < count; i++){
		xrange = (data[i].r - (x - data[i].x)) * (data[i].r + (x - data[i].x));
		if(xrange < 0)continue;
		
		upper = data[i].y + sqrt(xrange);
		lower = data[i].y - sqrt(xrange);
		
		if(y <= upper && y >= lower){
			printf("this point is in circle %d\n", i+1);
			tmp ++;
		}
	}
	if(tmp == 0){
		printf("this point isn't in any circle!!\n");
	}
	printf("================================================\n");
}
