#pragma once
#include "pch.h"

namespace winrt::LCD_Segments::implementation
{

	class MyDigit
	{
	public:
		MyDigit();
		const float Width() const { return m_width + 1; }
		void Width(float width) { m_width = width - 1; }
		const float Height() const { return m_height + 1; }
		void Height(float height) { m_height = height - 1; }
		const float Slant() const { return m_slant + 1; }
		void Slant(float slant) { m_slant = slant - 1; }

		const winrt::Microsoft::UI::Xaml::Media::PointCollection Top();
		const winrt::Microsoft::UI::Xaml::Media::PointCollection Middle();
		const winrt::Microsoft::UI::Xaml::Media::PointCollection Bottom();

	private:
		float m_width = 10.0;
		float m_height = 3.0;
		float m_slant = 0.0;

	};
}
