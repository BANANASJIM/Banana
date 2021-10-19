#pragma once

#ifdef BN_PLATFORM_WINDOWS
		#ifdef BN_BUILD_DLL
			#define BANANA_API __declspec(dllexport)
		#else
			#define BANANA_API __declspec(dllimport)
#endif
#else
		#error Banana only supports Windows!
#endif

#ifdef BN_ENABLE_ASSERTS
	#define BN_ASSERT(x, ...) { if(!(x)) { BN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BN_CORE_ASSERT(x, ...) { if(!(x)) { BN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BN_ASSERT(x, ...)
	#define BN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)