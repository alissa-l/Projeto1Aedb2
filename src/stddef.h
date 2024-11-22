#ifndef _STDDEF_H_
#define _STDDEF_H_

// Define NULL como 0
#ifndef NULL
    #define NULL ((void*)0)
#endif

// Define o tipo size_t, geralmente usado para tamanhos de objetos
typedef unsigned long size_t;

// Define o tipo ptrdiff_t, usado para diferenças entre ponteiros
typedef long ptrdiff_t;

// Define o tipo wchar_t, usado para caracteres largos
#ifndef __cplusplus
    typedef unsigned short wchar_t;
#endif

#endif /* _STDDEF_H_ */
