#include "exceptions.h"
#include "hidapi/hidapi/hidapi.h"
#include "strings.h"


namespace joy_con_bridge
{
HidError::HidError(hid_device* device)
	: m_error(strings::wideToChar(std::wstring(hid_error(device))))
{}

char const* HidError::what() const noexcept
{
	return m_error.data();
}

HidTimeoutError::HidTimeoutError(hid_device* device)
	: HidError(device)
{}

HidOpenError::HidOpenError()
	: HidError(nullptr)
{}

char const* HidOpenError::what() const noexcept
{
	return "The device can't be opened.";
}

char const* JoyConNotResponding::what() const noexcept
{
	return "The device is not responding.";
}
}
