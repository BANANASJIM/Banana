#pragma once

#ifdef BN_PlATFORM_WINDOWS
		#ifdef BN_BUILD_DLL
			#define BANANA_API _declspec(dllexport)
		#else 
			#define BANANA_API _declspec(dllimport)
		#endif
#else
	#error Banana only support Windows!
#endif 

#define BIT(x) (1 << x)