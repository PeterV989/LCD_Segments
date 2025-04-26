#pragma once
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Microsoft.UI.Xaml.Data.h>
#include <string>
#include <sstream>
#include <iomanip>
#include "ValueToText.g.h"

namespace winrt::LCD_Segments::implementation
{
	namespace WF = winrt::Windows::Foundation;
	namespace WUX = winrt::Windows::UI::Xaml;
	namespace WUXD = winrt::Windows::UI::Xaml::Data;
	namespace WUXI = winrt::Windows::UI::Xaml::Interop;

	struct ValueToText : ValueToTextT<ValueToText>
	{
		ValueToText() = default;

		WF::IInspectable Convert(
			WF::IInspectable const& value,
			WUXI::TypeName const& targetType,
			WF::IInspectable const& parameter,
			winrt::hstring const& culture);

		WF::IInspectable ConvertBack(
			WF::IInspectable const& value,
			WUXI::TypeName const& targetType,
			WF::IInspectable const& parameter,
			winrt::hstring const& culture);
	};
}

namespace winrt::LCD_Segments::factory_implementation
{
	struct ValueToText : ValueToTextT<ValueToText, implementation::ValueToText>
	{
	};
}
