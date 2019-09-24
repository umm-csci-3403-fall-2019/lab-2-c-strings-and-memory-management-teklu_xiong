#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"
#include <stdio.h>


int isval(char *str1) {
 int len;
 char *result;
 int a;

 a = strlen(str1);
 len = 0;
 result = str1;

 for (int i = 0; i < a; i++){
      if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u' || result[i] == 'A' || result[i] == 'E' || result[i] == 'I' || result[i] == 'O' || result[i] == 'U') {
           len++;
     }
 }

 return len;
}

char *disemvowel(char *str) {
 char *result;
 char *newString;
 int len;
 int j;

 len = strlen(str);
 result = str;

 newString = (char*) calloc(len-isval(result)+1, sizeof(char)); 


 for (int i = 0; i < len; i++){
      if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u' || result[i] == 'A' || result[i] == 'E' || result[i] == 'I' || result[i] == 'O' || result[i] == 'U') {
//	     result[i] = "";
     } else {
	     newString[j] = result[i];
	     j++;
     }
 }
  newString[len-isval(result)+1] = '\0';
  return newString;
}
