// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E1F22A53_DDD0_4EC3_BA00_07BD5F0D7EAB__INCLUDED_)
#define AFX_STDAFX_H__E1F22A53_DDD0_4EC3_BA00_07BD5F0D7EAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define IRIS_WIN32_VCC

#define TIME_TICK_INTERVAL 1000

// This didn't work:
// #define rdtsc __asm __emit 0fh __asm __emit 031h

#define PENTIUM
#define MHz 3000
#define WIN32_APP

#define NO_CONNECT 1009
//#define USE_OUTPUT_FILE

#include <stdio.h>
#include "utils.h"
#include <conio.h>
#include "time.h"
#include <string.h>
#include <stdio.h>
#include "dos.h"
//#include "txteng.h"

/* GetRandom returns a random integer between min and max. */
#define GetRandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))

#define NBR_OF_PORTS 6

// this file included for "rdtsc"
//#include "intrin.h"
// Basic types
#define byte  unsigned char
#define word  unsigned int
#define dword unsigned long int
#define sel   void _seg *
#define fptr  void*

#define RECV_DATA_BUF_SIZE 1200 // old was: 150
#define COM_PORTS 4

typedef unsigned char  BYTE;   // 8-bit unsigned entity
typedef unsigned short WORD;   // 16-bit unsigned number
typedef unsigned int   UINT;   // machine sized unsigned number (preferred)
typedef long           LONG;   // 32-bit signed number
typedef unsigned long  DWORD;  // 32-bit unsigned number
typedef int            BOOL;   // BOOLean (0 or !=0)
typedef char *         PSTR;   // pointer to a string
typedef const char *   PCSTR;  // pointer to a read-only string
typedef char *         LPSTR;  // far pointer to a string
typedef const char *   LPCSTR; // far pointer to a read-only string
typedef volatile unsigned char  VBYTE;   // 8-bit volatile unsigned entity
typedef volatile unsigned short VWORD;   // 16-bit volatile unsigned number
typedef volatile unsigned long  VDWORD;  // 32-bit volatile unsigned number
//#include <sys/stat.h>
#include "stdlib.h"
// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E1F22A53_DDD0_4EC3_BA00_07BD5F0D7EAB__INCLUDED_)
