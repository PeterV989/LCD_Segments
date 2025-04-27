#include "pch.h"
#include <sstream>
#include <iomanip>
#include "ValueToText.h"
#if __has_include("ValueToText.g.cpp")
#include "ValueToText.g.cpp"
#endif

namespace winrt::LCD_Segments::implementation
{
	ValueToText::ValueToText()
	{

	}

	WF::IInspectable ValueToText::Convert(
		[[maybe_unused]] WF::IInspectable const& value,
		WUXI::TypeName const&,
		[[maybe_unused]] WF::IInspectable const& parameter,
		winrt::hstring const&)
	{
		double valueDouble = 0;
		int decimalPlaces = 0;
		if (value != nullptr)
		{
			auto valueProperty = value.try_as<WF::IPropertyValue>();
			if (valueProperty != nullptr)
			{
				if (valueProperty.Type() == WF::PropertyType::Double)
				{
					valueDouble = valueProperty.GetDouble();
					if (parameter != nullptr)
					{
						auto paramStr = parameter.as<winrt::hstring>();
						try
						{
							decimalPlaces = std::stoi(paramStr.c_str());
							if (decimalPlaces < 0) decimalPlaces = 0;
						}
						catch (const std::invalid_argument&)
						{
							// use default
						}
						catch (const std::out_of_range&)
						{
							//use default
						}
					}
				}
			}
		}
		std::wstringstream wss;
		wss << std::fixed << std::setprecision(decimalPlaces) << valueDouble;
		std::wstring converted = wss.str();
		return winrt::box_value(winrt::hstring(converted));
	}

	WF::IInspectable ValueToText::ConvertBack(
		[[maybe_unused]] WF::IInspectable const& value,
		WUXI::TypeName const&,
		[[maybe_unused]] WF::IInspectable const& parameter,
		winrt::hstring const&)
	{
		return WUX::DependencyProperty::UnsetValue();
	}
}