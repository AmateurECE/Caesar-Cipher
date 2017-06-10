/*******************************************************************************
 * NAME:	    cipher.c
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Implementation of an encryption algorithm using Caesar's
 *		    alphabet shifting 'algorithm.'
 *
 * CREATED:	    06/06/17
 *
 * LAST EDITED:	    06/06/17
 ***/

/*******************************************************************************
 * INCLUDES
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cipher.h"

/*******************************************************************************
 * CONSTANTS
 ***/

const int caesars_key = 3;
const int alphabet_len = 26;

/*******************************************************************************
 * API FUNCTIONS
 ***/

/*******************************************************************************
 * FUNCTION:	    cipher_encode
 *
 * DESCRIPTION:	    Encodes 'string' using the shift cipher method, with the
 *		    given key. Returns the string in *crypt.
 *
 * ARGUMENTS:	    key: int -- the key for the encryption; the shift distance.
 *		    string: (char *) -- the string to encode.
 *		    crypt: (char **) -- the destination to place the new string.
 *
 * RETURN:	    int -- 0 on success, -1 otherwise.
 *
 * NOTES:	    Very little error checking is done here. "Trust the
 *		    programmer."
 ***/
int cipher_encode(int key, char * string, char ** crypt)
{
  char * pC;
  char * pN;
  char * new_string;

  if (string == NULL || strlen(string) == 0) {
    *crypt = NULL;
    return -1;
  }

  new_string = (char *)malloc((strlen(string) + 1) * sizeof(char));
  pC = string;
  pN = (char *)malloc(sizeof(char));

  while (*pC != '\0') {
    if (isupper(*pC)) {

      *pN = ((*pC - 'A' + key) % alphabet_len) + 65; /* 65 is the decimal value
						       of 'A' on the ASCII
						       table. */

    } else if (islower(*pC)) {

      *pN = ((*pC - 'a' + key) % alphabet_len) + 97; /* 97 is the decimal value
							of 'a' on the ASCII
							table. */
      
    } else *pN = *pC;

    strcat(new_string, pN);
    pC++;
  }

  strcpy(*crypt, new_string);
  free(new_string);
  free(pN);
  return 0;
}

/*******************************************************************************
 * FUNCTION:	    cipher_decode
 *
 * DESCRIPTION:	    Decodes 'string' using the shift cipher method, and places
 *		    the new string in *crypt.
 *
 * ARGUMENTS:	    key: int -- the key for encryption; the shift distance.
 *		    string: (char *) -- a previously encrypted string.
 *		    crypt: (char **) -- destination for decrypted string
 *
 * RETURN:	    int -- 0 for success, -1 otherwise.
 *
 * NOTES:	    none.
 ***/
int cipher_decode(int key, char * string, char ** crypt)
{
  char * pC;
  char * pO = NULL;
  char * old_string;

  if (string == NULL || strlen(string) == 0) {
    *crypt = NULL;
    return -1;
  }

  old_string = (char *)malloc((strlen(string) + 1) * sizeof(char));
  pC = string;
  pO = (char *)malloc(sizeof(char));

  while (*pC != '\0') {
    if (isupper(*pC)) {

      *pO = ((*pC - 'A' - key) % alphabet_len) + 65; /* 65 is the decimal value
						       of 'A' in the ASCII
						       table. */

    } else if (islower(*pC)) {

      *pO = ((*pC - 'a' - key) % alphabet_len) + 97; /* 97 is the decimal value
						       of 'a' in the ASCII
						       table. */

    } else *pO = *pC;

    strcat(old_string, pO);
    pC++;
  }

  strcpy(*crypt, old_string);
  free(old_string);
  free(pO);
  return 0;
}
