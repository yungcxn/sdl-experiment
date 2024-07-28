#include "./cce.h"

void cce_transform(char* t) {
  char replace_mode = 0;
  while(*t != '\0') {
    if (*t == CCE_FORMATTER) {
      *t = CCE_SKIP;
      replace_mode = 1;
      continue;
    }

    if (replace_mode) {
      switch(*t) {
        case 'A':
          *t = CCE_UPPER_AE;
          break;
        case 'a':
          *t = CCE_LOWER_AE;
          break;
        case 'O':
          *t = CCE_UPPER_OE;
          break;
        case 'o':
          *t = CCE_LOWER_OE;
          break;
        case 'U':
          *t = CCE_UPPER_UE;
          break;
        case 'u':
          *t = CCE_LOWER_UE;
          break;
        case 'Z':
          *t = CCE_UPPER_ESZETT;
          break;
        case 'z':
          *t = CCE_LOWER_ESZETT;
          break;
        case 'C':
          *t = CCE_UPPER_TURK_C;
          break;
        case 'c':
          *t = CCE_LOWER_TURK_C;
          break;
        case 'G':
          *t = CCE_UPPER_TURK_G;
          break;
        case 'g':
          *t = CCE_LOWER_TURK_G;
          break;
        case 'I':
          *t = CCE_UPPER_TURK_I;
          break;
        case 'i':
          *t = CCE_LOWER_TURK_I;
          break;
        case 'S':
          *t = CCE_UPPER_TURK_S;
          break;
        case 's':
          *t = CCE_LOWER_TURK_S;
          break;
        case '"':
          *t = CCE_LOWER_QUOT;
          break;
      }

      replace_mode = 0;
    }
    ++t;
  }
}