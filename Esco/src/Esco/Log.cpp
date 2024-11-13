#include "Log.h"


std::shared_ptr<spdlog::logger> Esco::Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Esco::Log::s_ClientLogger;

void Esco::Log::Init() {
	spdlog::set_pattern(">>>>>>>>> %H:%M:%S %z %v <<<<<<<<<");
	s_CoreLogger = spdlog::stdout_color_mt("Esco");
	s_CoreLogger->set_level(spdlog::level::trace);
	s_ClientLogger = spdlog::stdout_color_mt("Application");
	s_ClientLogger->set_level(spdlog::level::warn);
}