#include <stdlib.h>
#include <stdio.h>

typedef enum {
    TOKEN_NUM,
    TOKEN_OP,
    TOKEN_EOF,
    TOKEN_ERROR  
} TokenTypeId;

typedef struct {
  TokenTypeId id;
  char * description;
} TokenType;

typedef struct {
    TokenType tipo;
    char* valor;
} Token;


int tokenizar(FILE* input, FILE* output);