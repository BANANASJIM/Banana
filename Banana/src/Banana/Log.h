#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Banana {
	
	
		class BANANA_API Log
		{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
		};

}

// Core log macros
#define BN_CORE_TRACE(...)    ::Banana::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BN_CORE_INFO(...)     ::Banana::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BN_CORE_WARN(...)     ::Banana::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BN_CORE_ERROR(...)    ::Banana::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BN_CORE_CRITICAL(...) ::Banana::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BN_TRACE(...)         ::Banana::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BN_INFO(...)          ::Banana::Log::GetClientLogger()->info(__VA_ARGS__)
#define BN_WARN(...)          ::Banana::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BN_ERROR(...)         ::Banana::Log::GetClientLogger()->error(__VA_ARGS__)
#define BN_CRITICAL(...)      ::Banana::Log::GetClientLogger()->critical(__VA_ARGS__)

