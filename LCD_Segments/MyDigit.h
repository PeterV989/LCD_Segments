#pragma once
#include "pch.h"
#include "DebugHelpers.h"

namespace winrt::LCD_Segments::implementation
{
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

		const MUXM::PointCollection A_Segment() const {
			return m_a_Segment;
		};;
		const MUXM::PointCollection B_Segment() const {
			return m_b_Segment;
		};
		const MUXM::PointCollection C_Segment() const {
			return m_c_Segment;
		};
		const MUXM::PointCollection D_Segment() const {
			return m_d_Segment;
		};
		const MUXM::PointCollection E_Segment() const {
			return m_e_Segment;
		};
		const MUXM::PointCollection F_Segment() const {
			return m_f_Segment;
		};
		const MUXM::PointCollection G_Segment() const {
			return m_g_Segment;
		};

		DebugHelpers m_dh;
	private:

		void BuildSegments();
		void BuildA();
		void BuildB();
		void BuildC();
		void BuildD();
		void BuildE();
		void BuildF();
		void BuildG();
		float m_width = 10.0;
		float m_height = 3.0;
		float m_slant = 0.0;

		Microsoft::UI::Xaml::Media::PointCollection m_a_Segment;
		Microsoft::UI::Xaml::Media::PointCollection m_b_Segment;
		Microsoft::UI::Xaml::Media::PointCollection m_c_Segment;
		Microsoft::UI::Xaml::Media::PointCollection m_d_Segment;
		Microsoft::UI::Xaml::Media::PointCollection m_e_Segment;
		Microsoft::UI::Xaml::Media::PointCollection m_f_Segment;
		Microsoft::UI::Xaml::Media::PointCollection m_g_Segment;

	};
}
