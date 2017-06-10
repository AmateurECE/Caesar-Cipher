/*******************************************************************************
 * NAME:	    main.c
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Implementation of an encryption algorithm using Caesar's
 *		    alphabet shifting 'algorithm.' This file contains the main
 *		    method, which will allow for the creation of an executable.
 *		    Here will be variable parsing, etc.
 *
 * CREATED:	    06/08/17
 *
 * LAST EDITED:	    06/08/17
 ***/

/*******************************************************************************
 * INCLUDES
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cipher.h"
#include "main.h"

/*******************************************************************************
 * EXTERNAL REFERENCES
 ***/

extern const int caesars_key;

/*******************************************************************************
 * MACRO DEFINITIONS
 ***/

#define DEFAULT_KEY (caesars_key)

/*******************************************************************************
 * LOCAL PROTOTYPES
 ***/

static inline void error_exit(char *);
static void format_digits(const char * restrict, char *);

/*******************************************************************************
 * MAIN
 ***/

int main(int argc, char * argv[])
{
  char * string;
  char * output;
  cipher_options * opts;
  /* Get arguments from stdin. If there is more than two, parse the first to be
   * 'key' then set key to be the second--after checking that is is of the
   * correct type.
   *
   * Use ascii.c in tools to get the ascii value of a character, then stream-
   * encode by changing each byte in memory sequentially.
   */
  if (argc < 2)
    error_exit(USAGE);

  opts = (cipher_options *)malloc(sizeof(cipher_options));
  *opts = (cipher_options){.print_as_digits = 0, .key = DEFAULT_KEY,
			  .action = 'e', .value = (VALUE)0};
  string = NULL;

  for(int i = 1; i < argc; i++) {

    if (!strcmp(argv[i], ".key")) {
      
      if (i + 1 >= argc)
	error_exit(USAGE);

      opts->key = atoi(argv[i + 1]);
      if (opts->key > 25 || opts->key < 0)
	error_exit(USAGE);

    } else if (!strcmp(argv[i], ".print_as_digits")) {
      
      if (i + 1 >= argc)
	error_exit(USAGE);

      opts->print_as_digits = atoi(argv[i + 1]);

    } else if (!strcmp(argv[i], ".value")) {
      
      if (i + 1 >= argc)
	error_exit(USAGE);

      if (!strcmp(argv[i + 1], "HEX"))
	opts->value = HEX;
      else if (!strcmp(argv[i + 1], "DEC"))
	opts->value = DEC;
      else error_exit(USAGE);

    } else if (!strcmp(argv[i], ".d")) {

      opts->action = 'd';

    } else if (!strcmp(argv[i], ".e")) {

      opts->action = 'e';

    } else {

      string = (char *)malloc((strlen(argv[i]) + 1) * sizeof(char));
      strcpy(string, argv[i]);

    }

  }

  if (string != NULL) {

    output = (char *)malloc((strlen(string) + 1) * sizeof(char));
    if (opts->action == 'e') {
      if (cipher_encode(opts->key, string, &output))
	error_exit("There was an error in cipher_encode.\n");
    } else if (opts->action == 'd') {
      if (cipher_decode(opts->key, string, &output))
	error_exit("There was an error in cipher_decode.\n");
    } else error_exit(USAGE);

  } else error_exit(USAGE);

  if (opts->print_as_digits) {
      
    if (opts->value == HEX)
      format_digits("%2x", output);
    else if (opts->value == DEC)
      format_digits("%2d", output);
    else error_exit(USAGE);
      
  } else printf("%s\n", output);

  free(string);
  free(output);
  free(opts);
  return 0;
}

/*******************************************************************************
 * LOCAL FUNCTIONS
 ***/

static inline void error_exit(char * msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

static void format_digits(const char * restrict format, char * string)
{
  char * pC;

  if (format == NULL || string == NULL)
    error_exit("NULL Parameter in format_digits");

  pC = string;
  while (*pC != '\0') {
    printf(format, *pC);
    pC++;
  }
  printf("\n");
  return;
}

/******************************************************************************/
