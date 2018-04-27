%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int number;
	char *string;
}

// define the constant-string tokens:
%token SNAZZLE TYPE
%token END

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:

%token <string> NAMETOKEN
%token <string> IDENTIFIERTOKEN
%token <string> NAME_INITIAL_TOKEN
%token <string> ROMANTOKEN
%token <string> SRTOKEN
%token <string> JRTOKEN
%token <string> EOLTOKEN
%token <number> INTTOKEN
%token <string> COMMATOKEN
%token <string> DASHTOKEN
%token <string> HASHTOKEN

%start	Several_Addresses

%%

/*
 * Careful here... the very last entry in the source file should not
 * have a double newline.  An extra blank line indicates that another
 * BigMac Description is starting.
 *
 * This entry follows the pattern in the notes that discusses
 * how to handle an unknown number of items.
 */


Several_Addresses:
			Several_Addresses Address
		|	Address
		;

Address:
		  	Form1 
	|		Form2
	|		Form3
	|	        error EOLTOKEN { printf("Bad Address... skipping to next address\n"); }
	;

Form1:
	NAMETOKEN EOLTOKEN NAMETOKEN EOLTOKEN {fprintf(stderr, "%sFound a Form1 address", $3); }
	;

Form2:
	NAME_INITIAL_TOKEN NAMETOKEN EOLTOKEN INTTOKEN NAMETOKEN HASHTOKEN INTTOKEN EOLTOKEN NAMETOKEN COMMATOKEN NAMETOKEN INTTOKEN{fprintf(stderr, "%sFound a Form2 address", $3); }
	;

Form3:
	NAME_INITIAL_TOKEN NAMETOKEN ROMANTOKEN EOLTOKEN INTTOKEN NAMETOKEN INTTOKEN EOLTOKEN NAMETOKEN COMMATOKEN NAMETOKEN INTTOKEN DASHTOKEN INTTOKEN{fprintf(stderr, "%sFound a Form3 address", $3); }
	;

%%


void yyerror(char *s)
{
}