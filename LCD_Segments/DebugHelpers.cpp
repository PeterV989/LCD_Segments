#include "pch.h"
#include "DebugHelpers.h"

#include <stdio.h>
#include <sstream>
#include <iomanip>

namespace winrt::LCD_Segments::implementation
{
	namespace MUX = winrt::Microsoft::UI::Xaml;
	namespace MUXC = MUX::Controls;
	namespace MUXD = MUX::Documents;
	namespace MUXM = MUX::Media;
	namespace WF = winrt::Windows::Foundation;

	DebugHelpers::DebugHelpers() {};

	void DebugHelpers::DebugOutput([[maybe_unused]] winrt::hstring const& outText)
	{
		OutputDebugStringW(outText.data());
	}

	void DebugHelpers::DebugOutput(winrt::hstring const& name, winrt::hstring const& outDesc, MUXM::Brush const& br)
	{
		if (auto const& scb = br.try_as<MUXM::SolidColorBrush>())
		{
			winrt::Windows::UI::Color brushColor = scb.Color();
			std::wostringstream woss;
			woss << name.data() << L"::" << outDesc.data() << L": #" << std::setw(2) << std::setfill(L'0') << std::hex << brushColor.A << brushColor.R << brushColor.G << brushColor.B << std::endl;
			OutputDebugStringW(woss.str().c_str());
		}
	}
	void DebugHelpers::DebugOutput(std::wstring const& outText)
	{
		OutputDebugStringW(outText.data());
	}
}