#include "CustomPrint.h"


void CustomPrint::setMessage(std::string setMessage) {
	m_message = setMessage;
}

std::string CustomPrint::showMessage() {
	return "[INFO]: " + m_message + "\n";
}



