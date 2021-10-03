#include <stdio.h>
#include <string.h>

int check(char *p, char *q);
int same_check(char *p, char *q);

int same_check_2(char *standard, char *cmp){
    char check_letter;
    int same_count = 0;

    for(int i = 0; i < strlen(cmp); i++){
        check_letter = *(cmp + i);
        for(int j = 0; j < strlen(standard); j++){
            if(check_letter == *(standard + j)){
                same_count++;
                break;
            }
        }
    }
    
    return same_count;
}

int main(){
   char str[1001], *word[100], *p;
   int k;
   char *standard, *result[100], result_index = 0, same_count;
   
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
   //puts(w); // --------------------------------

    standard = w;

    for(int i = 0; i < n; i++){
    char *debugger = *(word + 1);
        if(strlen(*(word+i)) > strlen(standard) + 1){
            *(word + i) = "\0";
        }
        else if(strlen(*(word+i)) < strlen(standard) - 1){
            *(word + i) = "\0";
        }
    }

    result[0] = standard;
    result_index++;

    for(int i = 0; i < n; i++){
        if(i == k - 1){
            continue;
        }
        if(*(word + i) == "\0"){
            continue;
        }
        
        same_count = same_check_2(standard, *(word + i));
        if(strlen(standard) <= strlen(*(word + i))){
            if(strlen(*(word + i)) - 1 <= same_count && same_count <= strlen(*(word + i)) + 1){
                result[result_index] = *(word + i);
                result_index++;
            }
        }
        else{
            if(strlen(standard) - 1 <= same_count && same_count <= strlen(*(word + i)) + 1){
                result[result_index] = *(word + i);
                result_index++;
            }
        }
    }

    for(int i = 0; i < result_index; i++){
        printf("%s\n", *(result + i));
    }

   
//    int len_word = strlen(w);  // w -> standard
//    char newc[1001] = {0, }, *pnewc; // n
//    for(int i=0; i<n; i++){
//       if(i == k-1) continue;
      
//       int len_chg = strlen(word[i]);
//       if(len_word -1 == len_chg)
//          for(char p = 'a'; p <= 'z'; p++){
//             pnewc = newc;
//             strcpy(pnewc, word[i]);
//             *(pnewc+len_chg-1)=p;
            
//             if(check(w, newc) == 1){
//                puts(word[i]);
//                break;
//             }
//          }
      
//       else if(len_word + 1 == len_chg)
//          for(int j=0; j<len_chg; j++){
//             pnewc = newc;
//             for(int k=0; k<len_chg; k++){
//                if(k!=j){
//                   *(pnewc++) = word[i][k];
//                }
//             }
//             if(check(w, newc) == 1){
//                puts(word[i]);
//                break;
//             }
//          }
      
//       else if(len_word == len_chg){
//          if(same_check(w, word[i]) == 1)
//             puts(word[i]);         
//       }
//    }
   
   return 0;
}

int check(char *word, char *chg){
   int a1[26]={0, }, a2[26]={0, }, len;
   char *p;
   
   len = strlen(word);
   for(p = word; *p; p++) a1[*p - 'a']++;
   for(p = chg; *p; p++) a2[*p - 'a']++;
   
   for(int i=0; i<26; i++) 
      if(a1[i] != a2[i]) return 0;
      
   return 1;
}

int same_check(char *word, char *chg){
   int a1[26]={0, }, a2[26]={0, }, len, cnt=0;
   char *p;
   
   len = strlen(word);
   for(p = word; *p; p++) a1[*p - 'a']++;
   for(p = chg; *p; p++) a2[*p - 'a']++;
   
   for(int i=0; i<26; i++) 
      if(a1[i] != a2[i]) cnt++;
   
   if(len-cnt<2) return 0;
      
   return 1;
}
