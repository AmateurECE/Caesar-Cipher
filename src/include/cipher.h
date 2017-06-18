/*******************************************************************************
 * NAME:	    ciper.h
 *
 * AUTHOR:	    Ethan D. Twardy
 *
 * DESCRIPTION:	    Header for implementation of a Caesar cipher, for encrypting
 *		    strings.
 *
 * CREATED:	    06/06/17
 *
 * LAST EDITED:	    06/06/17
 ***/

#ifndef __ET_CIPHER_H__
#define __ET_CIPHER_H__

/*******************************************************************************
 * API FUNCTION PROTOTYPES
 ***/

extern int cipher_encode(int, char *, char **);
extern int cipher_decode(int, char *, char **);

#endif /* __ET_CIPHER_H__ */
