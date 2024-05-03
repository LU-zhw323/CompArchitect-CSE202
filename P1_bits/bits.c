/*
 * CSE202 SP21 Bits Program
 * Full Name: Zhenyu Wu
 * Full Lehigh email: zhw323@lehigh.edu
 */

/* The following C pre-processor statements allow you to compile with gcc option "-DDEBUG" to selectively 
 * take some particular action, such as printing a header for your output. Passing "-DDEBUG" to gcc defines
 * "DEBUG" such that you can test its value (see "if (DEBUG) {}" statement in main). If you don't like this 
 * whole idea/approach, you can delete this comment, the next three lines, and the "if (DEBUG) {}" statement.
 */
#ifndef DEBUG
#define DEBUG 0
#endif
#include<string.h>
#include <stdio.h> /* for printf, fprintf, etc. */
#include <regex.h>
#include <stdbool.h>

/* You are required to use the following union typedef. Doing so will prevent compiler warnings
 * when you attempt to access a memory location using a different type than when it was declared,
 * and you won't have to explicitly cast your variable references.
 */
typedef union {
  signed int s;
  unsigned int u;
  float f;
  unsigned char c[sizeof(int)];
} num_t;

int match(char*, const char*);



int main(int argc, char** argv) {

  /* You can choose to use the "DEBUG" option or not, up to you. And you can choose to use this header or not, up to you. 
   * Note that if the header is always printed, your output will not match the reference output.
   */ 
  if (DEBUG) printf("Bits of characters entered       Unsigned int     Signed int       Floating-point (binary)                Floating-point (decimal)\n");
  if(argc != 2){
    printf("Invalid input");
    return 0;
  }
  char* Input = argv[1];
  if(match(argv[1], "^[0-9a-fA-F]{8}$")){
    num_t target;
    long int i = 0;
    char* hex = argv[1];
    while(hex[i]){
      switch (hex[i]) {
         case '0':
             printf("0000");
             break;
         case '1':
             printf("0001");
             break;
         case '2':
             printf("0010");
             break;
         case '3':
             printf("0011");
             break;
         case '4':
             printf("0100");
             break;
         case '5':
             printf("0101");
             break;
         case '6':
             printf("0110");
             break;
         case '7':
             printf("0111");
             break;case '8':
             printf("1000");
             break;
         case '9':
             printf("1001");
             break;
         case 'A':
         case 'a':
             printf("1010");
             break;
         case 'B':
         case 'b':
             printf("1011");
             break;
         case 'C':
         case 'c':
             printf("1100");
             break;
         case 'D':
         case 'd':
             printf("1101");
             break;
         case 'E':
         case 'e':
             printf("1110");
             break;
         case 'F':
         case 'f':
             printf("1111");
             break;
         default:
             printf("\nInvalid hexadecimal digit %c",
             hex[i]);
      }
      i++;
    }
    int result = 0;
    for(int i = 0; i < 8; i++){
      int temp_int = 0;
      char temp;
      temp = Input[i];
      int temp_char = temp;
      if((temp_char >= 48) && (temp_char <= 57)){
        temp_int = temp_char-48;
      }
      else if((temp_char >= 65) && (temp_char <= 70)){
        temp_int = temp_char-55;
      }
      else if((temp_char >= 97) && (temp_char <= 102)){
        temp_int = temp_char-87;
      }
      result += temp_int<<(4*(7-i));
    }
    target.s = result;
    printf(" ");
    printf("%u\t",target.u);
    printf("%d\t",target.s);
    printf("%+g\t",target.f);


  }
  else if(match(argv[1], "-e")){
    unsigned int i = 1;
    char* c = (char* )&i;
    if(*c){
      printf("Little Endian\n");
    }
    else{
      printf("Big Endian\n");
    }
  }
  else{
    printf("Invalid input");
    return 0;
  }

  
  /*
  for(int i = 0 ; i < argc; i++){
    if(argv[i][0] == '-'){
      if(strcmp(argv[i],"-e")){
        unsigned short endian = 0x1122;
        if(*((unsigned char*)&endian) == 0x11){
          printf("Little Endian/n");
        }
        else{
          printf("Big Endian/n");
        }
      }
    }     
  }
  */
  return 0;
}
int match(char* Input, const char* display){
  int status;
  regex_t regex;
  if (regcomp(&regex, display, REG_EXTENDED|REG_NOSUB) != 0) {
        return 0;
    }
  status = regexec(&regex, Input, (size_t) 0, NULL, 0);
  regfree(&regex);
  if (status != 0) {
      return 0;
  }
  return 1;
}

