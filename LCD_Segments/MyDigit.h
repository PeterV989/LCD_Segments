#pragma once
#include "pch.h"
#include "DebugHelpers.h"
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <sstream>
#include <iomanip>

namespace WF = winrt::Windows::Foundation;
namespace WFC = WF::Collections;
namespace MUXM = winrt::Microsoft::UI::Xaml::Media;

namespace winrt::LCD_Segments::implementation
{
	using MyPointCollection = WFC::IVector<WF::Point>;
	using MySegments = WFC::IVector<MyPointCollection>;
	enum class Seg
	{
		A = 0,
		B = 1,
		C = 2,
		D = 3,
		E = 4,
		F = 5,
		G = 6
	};

	winrt::hstring ToHString(Seg);

	class MyDigit
	{
	public:
		MyDigit();
		const float Width() const { return m_width + 1.0f; }
		void Width(float width);
		const float Height() const { return m_height; }
		void Height(float height);
		const float Slant() const { return m_slant; }
		void Slant(float slant);
		int Size(Seg seg);
		WF::Point GetPoint(Seg seg, int point);
		winrt::hstring GetNodeString(Seg seg);
	private:
		DebugHelpers m_dh;
		void BuildSegments();
		void Build(Seg seg);
		float m_width;
		float m_height;
		float m_slant;
		MySegments m_segment{};
	};
}
