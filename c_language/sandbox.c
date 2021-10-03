#include <stdio.h>
#include <string.h>

int check(char *str, char *word);

int main(){
   char str[1001], *word[100], *p;
   int k;
   
   gets(str);
   scanf("%d", &k);
   
   p = strtok(str, " ");
   
   int n = 0;
   while(p != NULL){
      word[n] = p;      
      n++;   
      p = strtok(NULL, " ");
   }
   
   char *temp;
   for(int i=0; i<n-1; i++){
      for(int j=0; j<n-1; j++){
         if(strlen(word[j]) < strlen(word[j+1])){
            temp = word[j];
            word[j] = word[j+1];
            word[j+1] = temp;
         }
         
         else if(strlen(word[j]) == strlen(word[j+1])){
            if(strcmp(word[j], word[j+1]) > 0){
               temp = word[j];
               word[j] = word[j+1];
               word[j+1] = temp;
            }
         }
      }      
   }
   
   char *w = word[k-1];
   puts(w);

   for(int i = 0; i < n; i++){
      if((strlen(*(word+i)) > strlen(w) + 1)) *(word+i) = "0";
      else if (strlen(*(word+i)) < strlen(w) - 1) *(word+i) = "0";
   }

   int idx = 0, cnt;
   char *print[100];
    for(int i = 0; i < n; i++){
        if(i == k - 1 || *(word+i) == "0") continue;
        
        cnt = check(w, *(word+i));
        if(strlen(w) <= strlen(*(word+i))){
           
           if(strlen(*(word+i)) - 1 <= cnt && cnt <= strlen(*(word+i)) + 1){
               print[idx] = *(word+i);
               idx++;
           }
           else{
              if(strlen(w) - 1 <= cnt && cnt <= strlen(*(word + i)) + 1){
                  print[idx] = *(word + i);
                   idx++;
               }
           }
       }
    }

    for(int i = 0; i < idx; i++) printf("%s\n", *(print+i));

   return 0;   
}

int check(char *str, char *word){
    char p;
    int cnt = 0;

    for(int i = 0; i < strlen(word); i++){
        p = *(word+i);
        for(int j = 0; j < strlen(str); j++){
            if(p == *(str+j)){
                cnt++;
                break;
            }
        }
    }
    
    return cnt;
}