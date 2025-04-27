#include "pch.h"
#include "DebugHelpers.h"
#include "MyDigit.h"
#include "ValueToText.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <chrono>
#include <iostream>
#include <stdexcept>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::LCD_Segments::implementation
{
	MainWindow::MainWindow()
	{
		m_IsLoaded = false;
		InitializeComponent();
	}

	void MainWindow::OnLoaded(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
	{
		m_IsLoaded = true;
		//auto topSeg = A_Segment();
		//MUXM::SolidColorBrush brush;
		//WU::Color brushColor{ 0, 0, 0, 0 };

		//if (auto stroke = topSeg.Stroke().try_as<MUXM::SolidColorBrush>())
		//{
		//	brush = stroke;
		//	brushColor = stroke.Color();
		//}
		//else
		//{
		//	brush = nullptr;
		//}

		auto sw = SliderWidth().as<MUXC::Slider>();
		sw.ValueChanged({ this, &MainWindow::WidthSlider_ValueChanged });
		m_polygon.Width(static_cast<float>(sw.Value()));

		auto sh = SliderHeight().as<MUXC::Slider>();
		sh.ValueChanged({ this, &MainWindow::HeightSlider_ValueChanged });
		m_polygon.Height(static_cast<float>(sh.Value()));

		auto ss = SliderSlant().as<MUXC::Slider>();
		ss.ValueChanged({ this, &MainWindow::SlantSlider_ValueChanged });
		m_polygon.Slant(static_cast<float>(ss.Value()));

		DrawDigit();
	}

	void MainWindow::WidthSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		auto newValue = static_cast<float>(e.NewValue());
		if (newValue != m_polygon.Width())
		{
			m_polygon.Width(newValue);
			DrawDigit();
		}
	}

	void MainWindow::HeightSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		auto newValue = static_cast<float>(e.NewValue());
		if (newValue != m_polygon.Height())
		{
			m_polygon.Height(newValue);
			DrawDigit();
		}
	}

	void MainWindow::SlantSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		auto newValue = static_cast<float>(e.NewValue());
		if (newValue != m_polygon.Slant())
		{
			m_polygon.Slant(newValue);
			DrawDigit();
		}
	}

	void MainWindow::DrawDigit()
	{
		try {
			if (m_IsLoaded)
			{
				if (A_Segment() != nullptr)
				{
					if (A_Segment().Points() != nullptr)
					{
						A_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.A_Segment())
					{
						A_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_A().Text(PointsList);

				}
				if (B_Segment() != nullptr)
				{
					if (B_Segment().Points() != nullptr)
					{
						B_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.B_Segment())
					{
						B_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_B().Text(PointsList);
				}
				if (C_Segment() != nullptr)
				{
					if (C_Segment().Points() != nullptr)
					{
						C_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.C_Segment())
					{
						C_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_C().Text(PointsList);
				}
				if (D_Segment() != nullptr)
				{
					if (D_Segment().Points() != nullptr)
					{
						D_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.D_Segment())
					{
						D_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_D().Text(PointsList);
				}
				if (E_Segment() != nullptr)
				{
					if (E_Segment().Points() != nullptr)
					{
						E_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.E_Segment())
					{
						E_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_E().Text(PointsList);
				}
				if (F_Segment() != nullptr)
				{
					if (F_Segment().Points() != nullptr)
					{
						F_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.F_Segment())
					{
						F_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_F().Text(PointsList);
				}
				if (G_Segment() != nullptr)
				{
					if (G_Segment().Points() != nullptr)
					{
						G_Segment().Points().Clear();
					}
					winrt::hstring PointsList = L"";
					for (auto const p : m_polygon.G_Segment())
					{
						G_Segment().Points().Append(WF::Point(p.X, p.Y));
						if (PointsList.size() > 0) PointsList = PointsList + L" ";
						PointsList = PointsList + std::to_wstring(static_cast<int>(p.X)) + L"," + std::to_wstring(static_cast<int>(p.Y));
					}
					Points_G().Text(PointsList);
				}
			}
		}
		catch (...) {
			std::cerr << "Caught an exception while debugging\n";
		}
	}

}
