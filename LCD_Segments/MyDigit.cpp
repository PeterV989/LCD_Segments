#include "pch.h"
#include "MyDigit.h"

namespace WF = winrt::Windows::Foundation;
namespace MUXM = winrt::Microsoft::UI::Xaml::Media;

namespace winrt::LCD_Segments::implementation
{
	MyDigit::MyDigit()
	{

	}

	const MUXM::PointCollection MyDigit::Top()
	{

		MUXM::PointCollection polygon;

		polygon.Append(WF::Point{ m_slant * 2.0f, 0.0f });
		polygon.Append(WF::Point{ polygon.GetAt(0).X + m_width, polygon.GetAt(0).Y });
		polygon.Append(WF::Point{ polygon.GetAt(polygon.Size() - 1).X - m_height, polygon.GetAt(polygon.Size() - 1).Y + m_height});
		polygon.Append(WF::Point{ polygon.GetAt(0).X + m_height, polygon.GetAt(0).Y + m_height });
		polygon.Append(polygon.GetAt(0));

		return polygon;
	}

	const MUXM::PointCollection MyDigit::Middle()
	{
		MUXM::PointCollection polygon;

		polygon.Append(WF::Point{ m_slant * 2.0f, m_height * 2.0f });
		polygon.Append(WF::Point{ polygon.GetAt(0).X + m_height, polygon.GetAt(0).Y - m_height });
		polygon.Append(WF::Point{ polygon.GetAt(polygon.Size() - 1).X + m_width - m_height * 2.0f, polygon.GetAt(polygon.Size() - 1).Y });
		polygon.Append(WF::Point{ polygon.GetAt(0).X + m_width, polygon.GetAt(0).Y });
		polygon.Append(polygon.GetAt(0));

		return polygon;

	}

	const MUXM::PointCollection MyDigit::Bottom()
	{
		MUXM::PointCollection polygon;

		polygon.Append(WF::Point{ m_slant * 2.0f, m_height * 2.0f });
		polygon.Append(WF::Point{ polygon.GetAt(0).X + m_height, polygon.GetAt(0).Y - m_height });
		polygon.Append(WF::Point{ polygon.GetAt(polygon.Size() - 1).X + m_width - m_height * 2, polygon.GetAt(polygon.Size() - 1).Y });
		polygon.Append(WF::Point{ polygon.GetAt(0).X + m_width, polygon.GetAt(0).Y });
		polygon.Append(polygon.GetAt(0));

		return polygon;
	}
}