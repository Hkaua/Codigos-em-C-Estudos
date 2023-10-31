#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
  TOKEN_IDENTIFIER,
  TOKEN_KEYWORD,
  TOKEN_OPERATION,
  TOKEN_INTEGER_LITERAL,
  TOKEN_ERROR
} TokenType;

typedef struct
{
  TokenType type;
  char *lexeme;
} Token;

bool isKeyword(const char * word)
{
  const char* keywords[] = { "int", "float", "if", "else", "while", "for", "return" };
  int numKeywords = sizeof(keywords)/sizeof(keywords[0]);

  for (int i = 0; i < numKeywords; i++)
    {
      if (strcmp (word, keywords[i]) == 0)
	{
	  return true;
	}
    }
  return false;
}

Token *
tokenize (const char *input, int *numTokens)
{
  const char *current = input;
  Token *tokens = NULL;
  int tokenCount = 0;

  while (*current != '\0')
    {
      while (isspace (*current))
	{
	  current++;
	}
      if (isalpha (*current) || *current == '_')
	{
	  const char *start = current;
	  while (isalnum (*current) || *current == '_')
	    {
	      current++;
	    }
	  int length = current - start;
	  char *lexeme = (char *) malloc (length + 1);
	  strncpy (lexeme, start, length);
	  lexeme[length] = '\0';

	  Token token;
	  token.lexeme = lexeme;
	  if (isKeyword (lexeme))
	    {
	      token.type = TOKEN_KEYWORD;
	    }
	  else
	    {
	      token.type = TOKEN_IDENTIFIER;
	    }

	  tokens =
	    (Token *) realloc (tokens, (tokenCount + 1) * sizeof (Token));
	  tokens[tokenCount++] = token;
	}

      else if (strchr ("+-*/=<>", *current) != NULL)
	{

	}
      else if (isdigit (*current)
	       || (*current == '.' && isdigit (*(current + 1))))
	{

	}
      else
	{

	}
    }

  *numTokens = tokenCount;
  return tokens;
}

int
main ()
{
  const char *input = "int main() { return 0;}";
  int numTokens;
  Token *tokens = tokenize (input, &numTokens);

  for (int i = 0; i < numTokens; i++)
    {
      printf ("Token Type: %d, Lexeme: %s\\n", tokens[i].type,
	      tokens[i].lexeme);
      free (tokens[i].lexeme);
    }
  free (tokens);
  return 0;
}