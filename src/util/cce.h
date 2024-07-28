#ifndef CCE_H
#define CCE_H

// can's character encoding
// base is ascii

// german
#define CCE_UPPER_AE          0x81
#define CCE_LOWER_AE          0x82
#define CCE_UPPER_OE          0x83
#define CCE_LOWER_OE          0x84
#define CCE_UPPER_UE          0x85
#define CCE_LOWER_UE          0x86
#define CCE_UPPER_ESZETT      0x87
#define CCE_LOWER_ESZETT      0x88
#define CCE_LOWER_QUOT        0x89
//turk
#define CCE_UPPER_TURK_C      0x90
#define CCE_LOWER_TURK_C      0x91
#define CCE_UPPER_TURK_G      0x92
#define CCE_LOWER_TURK_G      0x93
#define CCE_UPPER_TURK_I      0x94 // with dot
#define CCE_LOWER_TURK_I      0x95 // without dot
#define CCE_UPPER_TURK_S      0x96
#define CCE_LOWER_TURK_S      0x97
#define CCE_SKIP              0xff
#define CCE_FORMATTER  '\a'

void cce_transform(char* t);

#endif