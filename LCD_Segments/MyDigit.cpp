#include "pch.h"
#include <string>
#include <iostream>
#include "MyDigit.h"

namespace WF = winrt::Windows::Foundation;
namespace MUXM = winrt::Microsoft::UI::Xaml::Media;

namespace winrt::LCD_Segments::implementation
{
	MyDigit::MyDigit()
	{
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
		BuildA();
		BuildG();
		BuildD();
		BuildB();
		BuildC();
		BuildE();
		BuildF();
	}

	void MyDigit::BuildA()
	{
		/***********************************************************
		* 0-------------------------------------------------------1
		*   \                                                   /
		*     3-----------------------------------------------2
		************************************************************/
		m_a_Segment.Clear();
		m_a_Segment.Append(WF::Point(m_slant * 2.0f, 0.0f));
		m_a_Segment.Append(WF::Point(m_a_Segment.GetAt(0).X + m_width, m_a_Segment.GetAt(0).Y));
		m_a_Segment.Append(WF::Point(m_a_Segment.GetAt(1).X - m_height, m_a_Segment.GetAt(1).Y + m_height));
		m_a_Segment.Append(WF::Point(m_a_Segment.GetAt(0).X + m_height, m_a_Segment.GetAt(2).Y));
	}

	void MyDigit::BuildG()
	{
		/***********************************************************
		*   / 1-----------------------------------------------2 \
		* 0                                                       3
		*   \ 5-----------------------------------------------4 /
		************************************************************/
		m_g_Segment.Clear();
		m_g_Segment.Append(WF::Point(m_slant, m_width));
		m_g_Segment.Append(WF::Point(m_g_Segment.GetAt(0).X + m_height, m_g_Segment.GetAt(0).Y - m_height / 2.0f));
		m_g_Segment.Append(WF::Point(m_g_Segment.GetAt(0).X + m_width - m_height, m_g_Segment.GetAt(1).Y));
		m_g_Segment.Append(WF::Point(m_g_Segment.GetAt(0).X + m_width, m_g_Segment.GetAt(0).Y));
		m_g_Segment.Append(WF::Point(m_g_Segment.GetAt(2).X, m_g_Segment.GetAt(2).Y + m_height));
		m_g_Segment.Append(WF::Point(m_g_Segment.GetAt(1).X, m_g_Segment.GetAt(4).Y));
	}

	void MyDigit::BuildD()
	{
		/***********************************************************
		*     3-----------------------------------------------2
		*   /                                                   \
		* 0-------------------------------------------------------1
		************************************************************/
		m_d_Segment.Clear();
		m_d_Segment.Append(WF::Point(0.0f, m_width * 2.0f ));
		m_d_Segment.Append(WF::Point(m_d_Segment.GetAt(0).X + m_width, m_d_Segment.GetAt(0).Y));
		m_d_Segment.Append(WF::Point(m_d_Segment.GetAt(1).X - m_height, m_d_Segment.GetAt(1).Y - m_height));
		m_d_Segment.Append(WF::Point(m_d_Segment.GetAt(0).X + m_height, m_d_Segment.GetAt(2).Y));
	}

	void MyDigit::BuildB()
	{
		m_b_Segment.Clear();
		m_b_Segment.Append(WF::Point(m_a_Segment.GetAt(1).X, m_a_Segment.GetAt(1).Y));
		m_b_Segment.Append(WF::Point(m_g_Segment.GetAt(3).X, m_g_Segment.GetAt(3).Y));
		m_b_Segment.Append(WF::Point(m_g_Segment.GetAt(2).X, m_g_Segment.GetAt(2).Y));
		m_b_Segment.Append(WF::Point(m_a_Segment.GetAt(2).X, m_a_Segment.GetAt(2).Y));
	}

	void MyDigit::BuildC()
	{
		m_c_Segment.Clear();
		m_c_Segment.Append(WF::Point(m_g_Segment.GetAt(3).X, m_g_Segment.GetAt(3).Y));
		m_c_Segment.Append(WF::Point(m_d_Segment.GetAt(1).X, m_d_Segment.GetAt(1).Y));
		m_c_Segment.Append(WF::Point(m_d_Segment.GetAt(2).X, m_d_Segment.GetAt(2).Y));
		m_c_Segment.Append(WF::Point(m_g_Segment.GetAt(4).X, m_g_Segment.GetAt(4).Y));
	}

	void MyDigit::BuildE()
	{
		m_e_Segment.Clear();
		m_e_Segment.Append(WF::Point(m_g_Segment.GetAt(0).X, m_g_Segment.GetAt(0).Y));
		m_e_Segment.Append(WF::Point(m_g_Segment.GetAt(5).X, m_g_Segment.GetAt(5).Y));
		m_e_Segment.Append(WF::Point(m_d_Segment.GetAt(3).X, m_d_Segment.GetAt(3).Y));
		m_e_Segment.Append(WF::Point(m_d_Segment.GetAt(0).X, m_d_Segment.GetAt(0).Y));
	}

	void MyDigit::BuildF()
	{
		m_f_Segment.Clear();
		m_f_Segment.Append(WF::Point(m_a_Segment.GetAt(0).X, m_a_Segment.GetAt(0).Y));
		m_f_Segment.Append(WF::Point(m_a_Segment.GetAt(3).X, m_a_Segment.GetAt(3).Y));
		m_f_Segment.Append(WF::Point(m_g_Segment.GetAt(1).X, m_g_Segment.GetAt(1).Y));
		m_f_Segment.Append(WF::Point(m_g_Segment.GetAt(0).X, m_g_Segment.GetAt(0).Y));
	}
}