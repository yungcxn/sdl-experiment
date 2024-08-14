#include "./cce.h"

#include <stdlib.h>
#include <stdint.h>

char* cce_create(wchar_t* t) {
  int len = -1;
  wchar_t* r = t;
  for (; r != 0; r++) 
    ++len;

  if (len == -1)
    return 0;

  char* x = (char*) malloc(len * sizeof(char));
  for (; t != 0; t++) {
    if (*t <= 0x7f) {
      // fits in ascii
      *x = (char) *t;
    }
    else {
      switch(*t) {
        case L'Ä':
          *x = CCE_UPPER_AE;
          break;
        case L'ä':
          *x = CCE_LOWER_AE;
          break;
        case L'Ö':
          *x = CCE_UPPER_OE;
          break;
        case L'ö':
          *x = CCE_LOWER_OE;
          break;
        case L'Ü':
          *x = CCE_UPPER_UE;
          break;
        case L'ü':
          *x = CCE_LOWER_UE;
          break;
        case L'ẞ':
          *x = CCE_UPPER_ESZETT;
          break;
        case L'ß':
          *x = CCE_LOWER_ESZETT;
          break;
        case L'Ç':
          *x = CCE_UPPER_TURK_C;
          break;
        case L'ç':
          *x = CCE_LOWER_TURK_C;
          break;
        case L'Ğ':
          *x = CCE_UPPER_TURK_G;
          break;
        case L'ğ':
          *x = CCE_LOWER_TURK_G;
          break;
        case L'İ':
          *x = CCE_UPPER_TURK_I;
          break;
        case L'ı':
          *x = CCE_LOWER_TURK_I;
          break;
        case L'Ş':
          *x = CCE_UPPER_TURK_S;
          break;
        case L'ş':
          *x = CCE_LOWER_TURK_S;
          break;
        case L'„':
          *x = CCE_LOWER_QUOT;
          break;
      }
    }
    ++x;  
  }
  return x;
}