#include<stdio.h>
#include<string.h>

typedef struct transcript{
	char name[10];
	int score;
}TS;

void main(){
	int i, j, tmp;
	char tmps[10];

	TS data[5];

	for(i = 0; i < 5; i++){
		printf("Student %d: ", i+1);
		scanf("%s", data[i].name);
		printf("His score: ");
		scanf("%d", &data[i].score);
	}

	for(i = 4; i >= 0; i--){
		for(j = 0; j < i; j++){
			if(data[j].score < data[j+1].score){
				tmp = data[j].score;
				data[j].score = data[j+1].score;
				data[j+1].score = tmp;
				strcpy(tmps, data[j].name);
				strcpy(data[j].name, data[j+1].name);
				strcpy(data[j+1].name, tmps);
				//tmps = data[j].name;
				//data[j].score = data[j+1].name;
				//data[j+1].name = tmps;
			}
		}
	}

	printf("=================================\nstudent\tscore\n");
	for(i = 0; i < 5; i++){
		printf("%s\t%d\n", data[i].name, data[i].score);
	}
}
