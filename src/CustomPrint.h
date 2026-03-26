#pragma_once

#include <string>

class CustomPrint {

private:
	std::string m_message {};

public:
	CustomPrint(std::string message="") : m_message{message} {}

	std::string showMessage(std::string message);
};
