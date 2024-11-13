#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Esco {

	class ESCO_API Log
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

// #ifdef ESCO_CONFIGURATION_DEBUG

// Core log macros
#define ESCO_CORE_ERROR(...)	::Esco::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ESCO_CORE_WARN(...)		::Esco::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ESCO_CORE_INFO(...)		::Esco::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ESCO_CORE_TRACE(...)	::Esco::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ESCO_CORE_FATAL(...)	::Esco::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ESCO_CLIENT_ERROR(...)	::Esco::Log::GetClientLogger()->error(__VA_ARGS__)
#define ESCO_CLIENT_WARN(...)	::Esco::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ESCO_CLIENT_INFO(...)	::Esco::Log::GetClientLogger()->info(__VA_ARGS__)
#define ESCO_CLIENT_TRACE(...)	::Esco::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ESCO_CLIENT_FATAL(...)	::Esco::Log::GetClientLogger()->fatal(__VA_ARGS__)


// 如果是发行版，可以使用宏来控制日志是否启用
// #elif ESCO_COFIGURATION_DIST
// #define ESCO_CORE_ERROR(...)
// #else
// #error please give a configuration...
// #endif


