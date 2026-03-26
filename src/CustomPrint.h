#pragma once

#include <string>

class CustomPrint {

private:
	std::string m_message {};

public:
	CustomPrint(std::string message="") : m_message{message} {}
	void setMessage(std::string setMessage);
	std::string showMessage();
};
