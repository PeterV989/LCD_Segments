#pragma once

#include "pch.h"
#include <string>

namespace winrt::LCD_Segments::implementation
{
namespace MUXM = winrt::Microsoft::UI::Xaml::Media;

	class DebugHelpers
	{
	public:
		DebugHelpers();
		void DebugOutput(winrt::hstring const& outText);
		void DebugOutput(winrt::hstring const& name, winrt::hstring const& outDesc, MUXM::Brush const& br);
		void DebugOutput(std::wstring const& outText);
	};
}