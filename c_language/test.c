#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct struct_info{
	char name[11];
	int score1;
	int score2;
};

void insertData(struct struct_info *s, int n){
	struct struct_info *p;

	for(p = s; p < s + n; p++){
		scanf("%s %d %d", p->name, &p->score1, &p->score2);
	}
}

void printResult(struct struct_info *s, int n, int n1, int n2){
	struct struct_info *p;

	for(p = s; p < s + n; p++){
		if(p->score1 <= n1){
			printf("%s %d %d\n", s->name, p->score1, p->score2);
		}
		else if(p->score2 <= n2){
			printf("%s %d %d\n", s->name, p->score1, p->score2);
		}
	}
}

int main(){
	int n, n1, n2;
	struct struct_info list[100];
	scanf("%d %d %d", &n, &n1, &n2);

	insertData(list, n);
	printResult(list, n, n1, n2);

	return 0;
}

