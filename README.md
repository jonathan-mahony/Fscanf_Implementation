# Fscanf_Implementation
 Implementation of the fscanf function (C)
develop an implementation of fscanf that supports
-strings: sequence of characters ends in whitespace (’ ’) or newline ('\n')
–chars–ints: sequence of digits
–variable number of parameters, passed using a linked list or array

Notes
•you are not allowed to use the stdio fscanfin any part of your scanf implementation.
•when you are reading integers, don’t forget to initialise your parameter’s value to 0 before starting toform the number out of the digits
•when you are reading strings don’t forget to finalise the string with the ‘\0’ character at the end
•get char is used to take characters out of the input buffer for processing; you can use ungetc(ch,stdin)to put the characterch back in the buffer so it can be processed later
•when the format string is all processed you should clear the input buffer by reading all remainingcharacters until you get to the newline
•check for the EOF when parsing the input; if EOF is found then scanf should exit, returning thematched elements up to that point.
