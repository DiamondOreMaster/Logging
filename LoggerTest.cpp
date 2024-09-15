#include "Logger.hpp"

std::string testingString = "Test";

Logger::error(testingString, true);
Logger::warning(testingString, true);
Logger::log(testingString, true);
Logger::success(testingString, true);

Logger::error(testingString, false);
Logger::warning(testingString, false);
Logger::log(testingString, false);
Logger::success(testingString, false);

Logger::timeFormatInternational = true;
Logger::error(testingString, true);
Logger::warning(testingString, true);
Logger::log(testingString, true);
Logger::success(testingString, true);

Logger::error(testingString, false);
Logger::warning(testingString, false);
Logger::log(testingString, false);
Logger::success(testingString, false);

Logger::timeFormatInternational = false;
Logger::disableColoredText = true;
Logger::error(testingString, true);
Logger::warning(testingString, true);
Logger::log(testingString, true);
Logger::success(testingString, true);

Logger::error(testingString, false);
Logger::warning(testingString, false);
Logger::log(testingString, false);
Logger::success(testingString, false);

Logger::timeFormatInternational = true;
Logger::disableColoredText = true;
Logger::error(testingString, true);
Logger::warning(testingString, true);
Logger::log(testingString, true);
Logger::success(testingString, true);

Logger::error(testingString, false);
Logger::warning(testingString, false);
Logger::log(testingString, false);
Logger::success(testingString, false);
