#pragma once

#include <string>
#include <chrono>
#include <iostream>

struct RGB {
	uint8_t red = 0; 
	uint8_t green = 0;
	uint8_t blue = 0;
};

constexpr RGB ErrorColor = RGB{ 255, 0, 0 };
constexpr RGB WarningColor = RGB{ 255, 165, 0 };
constexpr RGB LogColor = RGB{ 255, 255, 255 };
constexpr RGB SuccessColor = RGB{ 34, 139, 34 };

namespace Logger {

	bool timeFormatInternational = false;
	bool exitOnError = false;
	bool disableColoredText = false;

	void resetTerminalTextColor() {
		std::cout << "\033[0m";
	}

	void setTerminlTextColor(RGB colorData) {

		if (disableColoredText) {
			resetTerminalTextColor();
			return;
		}

		std::string message = "\033[38;2;" + 
			std::to_string(colorData.red) + ";" +
			std::to_string(colorData.green) + ";" +
			std::to_string(colorData.blue) + "m";

		std::cout << message;
	}

	

	void logMessage(const std::string& message, RGB colorData) {
		setTerminlTextColor(colorData);

		std::cout << message << "\n";
		resetTerminalTextColor();
	}

	std::string unixToStandardTime(std::chrono::system_clock::time_point unixTime) {
		std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
		std::time_t localTime = std::chrono::system_clock::to_time_t(timePoint);
		std::tm unixToLocalTime;

		localtime_s(&unixToLocalTime, &localTime);

		std::string timeFormat = "%m/%d/%Y %H:%M:%S";
		if (timeFormatInternational) {
			timeFormat = "%d/%m/%Y %H:%M:%S";
		}

		std::ostringstream oss;
		oss << std::put_time(&unixToLocalTime, timeFormat.c_str());

		return oss.str();
	}

	void log(const std::string& message, bool logTime) {
		std::string finalMessage = "[LOG] " + message;
		if (logTime) {
			finalMessage = "["
				+ unixToStandardTime(std::chrono::system_clock::now())
				+ "]"
				+ " [LOG] "
				+ message;
		}

		logMessage(finalMessage, LogColor);
	}

	void success(const std::string& message, bool logTime) {
		std::string finalMessage = "[SUCCESS] " + message;
		if (logTime) {
			finalMessage = "["
				+ unixToStandardTime(std::chrono::system_clock::now())
				+ "]"
				+ " [SUCCESS] "
				+ message;
		}

		logMessage(finalMessage, SuccessColor);
	}

	void warning(const std::string& message, bool logTime) {
		std::string finalMessage = "[WARNING] " + message;
		if (logTime) {
			finalMessage = "["
				+ unixToStandardTime(std::chrono::system_clock::now())
				+ "]"
				+ " [WARNING] "
				+ message;
		}

		logMessage(finalMessage, WarningColor);
	}

	void error(const std::string& message, bool logTime) {
		std::string finalMessage = "[ERROR] " + message;
		if (logTime) {
			finalMessage = "[" 
				+ unixToStandardTime(std::chrono::system_clock::now()) 
				+ "]"
				+ " [ERROR] "
				+ message;
		}

		logMessage(finalMessage, ErrorColor);

		if (exitOnError) {
			exit(-1);
		}
	}
}