#pragma once
#include "pch.h"
#include "DebugHelpers.h"

namespace winrt::LCD_Segments::implementation
{
	using Node = std::pair<float, float>;
	using MyPolygon = std::vector<Node>;

	class MyDigit
	{
	public:
		MyDigit();
		const float Width() const { return m_width + 1.0f; }
		void Width(float width) { m_width = width - 1.0f; }
		const float Height() const { return m_height + 1.0f; }
		void Height(float height) { m_height = height - 1.0f; }
		const float Slant() const { return m_slant; }
		void Slant(float slant) { m_slant = slant; }

		const MUXM::PointCollection LCD_Top();
		const MUXM::PointCollection LCD_Middle();
		const MUXM::PointCollection LCD_Bottom();

	private:
		float m_width = 10.0;
		float m_height = 3.0;
		float m_slant = 0.0;

		DebugHelpers m_dh;
	};
}
