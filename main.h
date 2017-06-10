/*******************************************************************************
 * NAME:	    main.h
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Header file containing typedefs for main.c used in cipher.c.
 *
 * CREATED:	    06/08/17
 *
 * LAST EDITED:	    06/08/17
 ***/

#ifndef __ET_MAIN_H__
#define __ET_MAIN_H__

/*******************************************************************************
 * INCLUDES
 ***/

#include "cipher.h"

/*******************************************************************************
 * TYPE DEFINITIONS
 ***/

typedef enum _VALUE_ {
  
  HEX = 0,
  DEC = 1

} VALUE;

typedef struct _cipher_options_ {

  int print_as_digits;
  int key;
  char action;
  VALUE value;

} cipher_options;

/*******************************************************************************
 * MACRO DEFINITIONS
 ***/

#define USAGE \
  "cipher: [.key <num>] [.print_as_digits <1 | 0>] [.value <enum>] [.d | .e] " \
  "<string>\n\n" \
  "\t.key - sets the key for encryption to be <num>, where <num> is a digit" \
  " between 0 and 25.\n" \
  "\t.print_as_digits - a boolean value that determines whether the encrypted" \
  " string is printed as alpha characters or in numeric values.\n" \
  "\t.value - an enumerated value that determines which ascii value is used" \
  " when .print_as_digits is set to true.\n" \
  "\tAction - to specify an action, add either .d or .e to the arguments." \
  " Specify .d to decrypt, or .e to encrypt. If no action is specified," \
  " encryption is assumed.\n" \
  "\t\tHEX:  use the hexadecimal ascii value.\n" \
  "\t\tDEC:  use the decimal ascii value.\n" \
  "\t\tOCT:  NOT YET SUPPORTED\n" \
  "\t\tHTML: NOT YET SUPPORTED\n" \
  "\n"

#endif /* __ET_MAIN_H__ */

/******************************************************************************/
