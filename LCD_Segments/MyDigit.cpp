#include "pch.h"
#include "MyDigit.h"

namespace WF = winrt::Windows::Foundation;
namespace MUXM = winrt::Microsoft::UI::Xaml::Media;

namespace winrt::LCD_Segments::implementation
{
	MyDigit::MyDigit()
	{

	}

	const MUXM::PointCollection MyDigit::LCD_Top()
	{
		m_dh.DebugOutput(L"MyDigit::LCD_Top Start\n");

		auto polygon = MUXM::PointCollection();

		polygon.Append(WF::Point(m_slant * 2.0f, 0.0f ));
		polygon.Append(WF::Point(polygon.GetAt(0).X + m_width, polygon.GetAt(0).Y));
		polygon.Append(WF::Point(polygon.GetAt(1).X - m_height, polygon.GetAt(1).Y + m_height));
		polygon.Append(WF::Point(polygon.GetAt(0).X + m_height, polygon.GetAt(2).Y));
		polygon.Append(WF::Point(polygon.GetAt(0)));

		m_dh.DebugOutput(L"MyDigit::LCD_Top Finish\n");
		return polygon;
	}

	const MUXM::PointCollection MyDigit::LCD_Middle()
	{
		auto polygon = MUXM::PointCollection();

		polygon.Append(WF::Point(m_slant, m_width));
		polygon.Append(WF::Point(polygon.GetAt(0).X + m_height, polygon.GetAt(0).Y - m_height / 2.0f));
		polygon.Append(WF::Point(polygon.GetAt(1).X + m_width - m_height * 2.0f, polygon.GetAt(1).Y));
		polygon.Append(WF::Point(polygon.GetAt(0).X + m_width, polygon.GetAt(0).Y));
		polygon.Append(WF::Point(polygon.GetAt(2).X, polygon.GetAt(2).Y + m_height));
		polygon.Append(WF::Point(polygon.GetAt(1).X, polygon.GetAt(4).Y));
		polygon.Append(WF::Point(polygon.GetAt(0)));

		return polygon;

	}

	const MUXM::PointCollection MyDigit::LCD_Bottom()
	{
		auto polygon = MUXM::PointCollection();

		polygon.Append(WF::Point(0.0f, m_width * 2.0f ));
		polygon.Append(WF::Point(polygon.GetAt(0).X + m_width, polygon.GetAt(0).Y));
		polygon.Append(WF::Point(polygon.GetAt(1).X - m_height, polygon.GetAt(1).Y - m_height));
		polygon.Append(WF::Point(m_height, polygon.GetAt(2).Y));
		polygon.Append(WF::Point(polygon.GetAt(0)));

		return polygon;
	}
}