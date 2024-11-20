#pragma once


#ifdef ESCO_PLATFORM_WINDOWS

#ifdef ESCO_BUILD_DLL
#define ESCO_API __declspec(dllexport)
#else
#define ESCO_API __declspec(dllimport)
#endif
#elif ESCO_PLATFORM_UNIX
#define ESCO_API 
#else
#error Now, esco only support Windows...
#endif


#define BIT(x) (1 << x)