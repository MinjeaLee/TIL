#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
   char name[31];
   int id;
   int subject_num;
   char subject[31];
   double credit[31];
   int rank;
};

void input_I(struct student *p);
void sort_S(struct student *p, int n);
void print_S(struct student *p, int n);
int delete_D(struct student *p, char *c, int n);
void print_P(struct student *p, int n);
void quit_Q();

int main(){
   struct student st[101]={{NULL, 0, 0, NULL, 0.0, 0}, }, *p;
   p = st;
   
   int cnt = 0;
   char choice;
   while(1){
      scanf("%c", &choice);
      getchar();
      
      if(choice == 'I'){
         input_I(p+cnt);
         cnt++;
      } 
      else if(choice == 'S') sort_S(p, cnt);
      else if(choice == 'D'){
         char name[31];
         scanf("%s", name);
         getchar();
         cnt = delete_D(p, name, cnt);
      }
      else if(choice == 'P') print_P(p, cnt);
      else if(choice == 'Q') quit_Q();      
   }
   
}

void input_I(struct student *p){
   struct student *x;
   x = p;
   
   scanf("%s %d %d", &x->name, &x->id, &x->subject_num);
   getchar();
   
   for(int i=0; i < x->subject_num; i++){
      scanf("%s %lf", &x->subject, &x->credit[i]);
   }
   getchar();
   
}

void sort_S(struct student *p, int n){
   struct student *x, temp;
   char save[41];
   strcpy(save, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
   
   for(x = p; x < p + n; x++){
      x->rank = 0;
   }
   
   for(int i=0; i<n; i++){
      for(x = p; x < p + n; x++){
         if(strcmp(save, x->name) > 0 && x->rank == 0){
            strcpy(save, x->name);
         }
      }
      
      for(x = p; x < p + n; x++){
         if(strcmp(save, x->name) == 0 && x->rank == 0){
            x->rank = 1;
            print_S(p, n);
            x->rank = -1;
            strcpy(save, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
            break;
         }
      }
            
   }
   
}

void print_S(struct student *p, int n){
   struct student *x;
   double sum = 0.0, avg;
   
   for(x = p; x < p + n; x++){
      if(x->rank == 1){
         for(int i=0; i<x->subject_num; i++){
            sum += x->credit[i];
         }
         avg = sum/x->subject_num;
         sum = 0;
         
         printf("%s %d %d %.2lf\n", x->name, x->id, x->subject_num, avg);
      }
   }
   
}


int delete_D(struct student *p, char *q, int n){
   struct student *x;
   int num = -1, i = 0, check = 0;
   
   for(x = p; x < p + n; x++, i++){
      if(strcmp(x->name, q) == 0) {
          num = i;
          check = 1;
      }
   }
   
   if(check == 1){
      for(x = p + num; x < p + n; x++){
         *x = *(x+1);
      }
   }   
   n--;
   
   return n;
}

void print_P(struct student *p, int n){
   struct student *x, *y;
   double sum = 0.0, avg;
   
   int i;
   for(x = p; x < p + n; x++){
      for(i=0; i < x->subject_num; i++, y++){
         sum += x->credit[i];
      }
      avg = sum/x->subject_num;
      sum = 0;      
      
      printf("%s %d %d %.2lf\n", x->name, x->id, x->subject_num, avg);
   }
   
}

void quit_Q(){
   exit(0);
}