#include "pch.h"
#include <string>
#include <iostream>
#include "MyDigit.h"
#if __has_include("MyDigit.g.cpp")
#include "MyDigit.g.cpp"
#endif

namespace winrt::LCD_Segments::implementation
{
	MyDigit::MyDigit()
	{
		// Give the starting dimensions of the segments
		// Each of the segments is built based on these
		// dimensions. The dimensions here actually
		// represent the endpoint, not the actual
		// dimension.
		m_width = 10.0f;
		m_height = 2.0f;
		m_slant = 0.0f;

		// create a vector for each of the segments. The
		// vector created here will store the (x,y) points
		// for the vertices of the polygon it represents.
		// The horizontal segments are created first.
		// Each of the vertical segments relies on the
		// adjacent horizontal polygons to define their
		// shape.
		m_segment = winrt::single_threaded_vector<MyPointCollection>();
		for (int seg = static_cast<int>(Seg::A); seg <= static_cast<int>(Seg::G); seg++)
		{
			m_segment.Append(winrt::single_threaded_vector<WF::Point>());
			m_segment.GetAt(seg).Clear();
		}
		BuildSegments();
	}

	void MyDigit::Width(float width)
	{
		m_width = width - 1.0f;
		BuildSegments();
	}

	void MyDigit::Height(float height)
	{
		m_height = height;
		BuildSegments();
	}

	void MyDigit::Slant(float slant)
	{
		m_slant = slant;
		BuildSegments();
	}


	void MyDigit::BuildSegments()
	{
		// Segments A, G, and D must be built first. The other four rely on their coordinates.
		Build(Seg::A);
		Build(Seg::G);
		Build(Seg::D);
		Build(Seg::B);
		Build(Seg::C);
		Build(Seg::E);
		Build(Seg::F);
	}

	void MyDigit::Build(Seg seg)
	{
		int segIndex = static_cast<int>(seg);
		m_segment.GetAt(segIndex).Clear();
		switch (seg)
		{
		case Seg::A:
			/***********************************************************
			* 0-------------------------------------------------------1
			*   \                                                   /
			*     3-----------------------------------------------2
			************************************************************/
			m_segment.GetAt(segIndex).Append(WF::Point(m_slant * 2.0f, 0.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_width, m_segment.GetAt(segIndex).GetAt(0).Y));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(1).X - m_height, m_segment.GetAt(segIndex).GetAt(1).Y + m_height));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_height, m_segment.GetAt(segIndex).GetAt(2).Y));
			break;

		case Seg::G:
			/***********************************************************
			*   / 1-----------------------------------------------2 \
			* 0                                                       3
			*   \ 5-----------------------------------------------4 /
			************************************************************/
			m_segment.GetAt(segIndex).Append(WF::Point(m_slant, m_width));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_height, m_segment.GetAt(segIndex).GetAt(0).Y - m_height / 2.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_width - m_height, m_segment.GetAt(segIndex).GetAt(1).Y));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_width, m_segment.GetAt(segIndex).GetAt(0).Y));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(2).X, m_segment.GetAt(segIndex).GetAt(2).Y + m_height));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(1).X, m_segment.GetAt(segIndex).GetAt(4).Y));
			break;

		case Seg::D:
			/***********************************************************
			*     3-----------------------------------------------2
			*   /                                                   \
			* 0-------------------------------------------------------1
			************************************************************/
			m_segment.GetAt(segIndex).Append(WF::Point(0.0f, m_width * 2.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_width, m_segment.GetAt(segIndex).GetAt(0).Y));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(1).X - m_height, m_segment.GetAt(segIndex).GetAt(1).Y - m_height));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(segIndex).GetAt(0).X + m_height, m_segment.GetAt(segIndex).GetAt(2).Y));
			break;

		case Seg::B:
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(1).X, m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(1).Y + 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(3).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(3).Y - 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(2).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(2).Y - 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(2).X, m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(2).Y + 1.0f));
			break;

		case Seg::C:
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(3).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(3).Y + 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(1).X, m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(1).Y - 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(2).X, m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(2).Y - 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(4).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(4).Y + 1.0f));
			break;

		case Seg::E:
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(0).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(0).Y + 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(5).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(5).Y + 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(3).X, m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(3).Y - 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(0).X, m_segment.GetAt(static_cast<int>(Seg::D)).GetAt(0).Y - 1.0f));
			break;

		case Seg::F:
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(0).X, m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(0).Y + 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(3).X, m_segment.GetAt(static_cast<int>(Seg::A)).GetAt(3).Y + 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(1).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(1).Y - 1.0f));
			m_segment.GetAt(segIndex).Append(WF::Point(m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(0).X, m_segment.GetAt(static_cast<int>(Seg::G)).GetAt(0).Y - 1.0f));
			break;
		}
	}

	int MyDigit::Size(Seg seg)
	{
		return m_segment.GetAt(static_cast<int>(seg)).Size();
	}

	WF::Point MyDigit::GetPoint(Seg seg, int point)
	{
		return WF::Point(m_segment.GetAt(static_cast<int>(seg)).GetAt(point));
	}
	winrt::hstring MyDigit::GetNodeString(Seg seg)
	{
		std::wostringstream woss;
		woss << std::fixed << std::setprecision(0);
		for (WF::Point p : m_segment.GetAt(static_cast<int>(seg)))
		{
			woss << p.X << L"," << p.Y << L" ";
		}
		winrt::hstring points(L"");
		std::wstring ret(woss.str());
		if (!ret.empty() && (ret.length() > 1))
			points = ret.substr(0, ret.length() - 1);
		return points;
	}

	winrt::hstring ToHString(Seg s)
	{
		switch (s)
		{
		case Seg::A: return L"A";
		case Seg::B: return L"B";
		case Seg::C: return L"C";
		case Seg::D: return L"D";
		case Seg::E: return L"E";
		case Seg::F: return L"F";
		case Seg::G: return L"G";
		default: return L"Unknown";
		};
	}
}