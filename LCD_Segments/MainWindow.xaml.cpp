#include "pch.h"
#include "DebugHelpers.h"
#include "MyDigit.h"
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
	//namespace MUX = winrt::Microsoft::UI::Xaml;
	//namespace MUXC = MUX::Controls;
	//namespace MUXS = MUX::Shapes;
	//namespace MUXM = MUX::Media;
	//namespace WF = winrt::Windows::Foundation;

	MainWindow::MainWindow()
	{
		m_IsLoaded = false;
		InitializeComponent();
	}

	void MainWindow::OnLoaded(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
	{
		m_IsLoaded = true;
		//auto topSeg = TopSegment();
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

		m_DeferUpdateTimer = MUX::DispatcherTimer();
		m_DeferUpdateTimer.Interval(WF::TimeSpan{ std::chrono::milliseconds(250) });
		m_DeferUpdateTimer.Tick({ this, &MainWindow::UpdateTimer });

		//auto sw = SliderWidth().as<MUXC::Slider>();
		//sw.ValueChanged({ this, &MainWindow::WidthSlider_ValueChanged });
		//m_polygon.Width(static_cast<float>(sw.Value()));
		//WidthSliderValue().Text(L"" + std::to_wstring(static_cast<int>(m_polygon.Width())));

		//auto sh = SliderHeight().as<MUXC::Slider>();
		//sh.ValueChanged({ this, &MainWindow::HeightSlider_ValueChanged });
		//m_polygon.Height(static_cast<float>(sh.Value()));
		//HeightSliderValue().Text(L"" + std::to_wstring(static_cast<int>(m_polygon.Height())));

		//auto ss = SliderSlant().as<MUXC::Slider>();
		//ss.ValueChanged({ this, &MainWindow::SlantSlider_ValueChanged });
		//m_polygon.Slant(static_cast<float>(ss.Value()));
		//SlantSliderValue().Text(L"" + std::to_wstring(static_cast<int>(m_polygon.Slant())));

		//DrawDigit();
	}

	void MainWindow::UpdateTimer(WF::IInspectable const&, WF::IInspectable const&)
	{
		m_dh.DebugOutput(L"UpdateTimer Start\n");
		m_DeferUpdateTimer.Stop();
		float fVal;

		fVal = static_cast<float>(SliderWidth().Value());
		//m_polygon.Width(fVal);
//		WidthSliderValue().Text(L"" + std::to_wstring(static_cast<int>(fVal)));

		fVal = static_cast<float>(SliderHeight().Value());
		//m_polygon.Height(fVal);
//		HeightSliderValue().Text(L"" + std::to_wstring(static_cast<int>(fVal)));

		fVal = static_cast<float>(SliderSlant().Value());
		//m_polygon.Slant(fVal);
//		SlantSliderValue().Text(L"" + std::to_wstring(static_cast<int>(fVal)));

		//DrawDigit();
		m_dh.DebugOutput(L"UpdateTimer Finished\n");
	}

	//void MainWindow::WidthSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const&)
	//{
	//	if (m_IsLoaded)
	//	{
	//		m_DeferUpdateTimer.Stop();
	//		m_DeferUpdateTimer.Start();
	//	}
	//}

	//void MainWindow::HeightSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const&)
	//{
	//	if (m_IsLoaded)
	//	{
	//		m_DeferUpdateTimer.Stop();
	//		m_DeferUpdateTimer.Start();
	//	}
	//}

	//void MainWindow::SlantSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const&)
	//{
	//	if (m_IsLoaded)
	//	{
	//		m_DeferUpdateTimer.Stop();
	//		m_DeferUpdateTimer.Start();
	//	}
	//}

	//void MainWindow::DrawDigit()
	//{
	//	try {
	//		if (m_IsLoaded && (TopSegment() != nullptr))
	//		{
	//			if (TopSegment().Points() != nullptr)
	//			{
	//				TopSegment().Points().Clear();
	//			}
	//			else
	//			{
	//				TopSegment().Points(MUXD::Poi
	//			}
	//			TopSegment().Points(m_polygon.LCD_Top());
	//		}
	//	}
	//	catch (...) {
	//		std::cerr << "Caught an exception while debugging\n";
	//	}
	//}

	//void MainWindow::UpdatePoints(MUXS::Polygon const& poly, MyPolygon const& polyNodes)
	//{
	//	//poly.Points = MUXM::PointCollection();
	//	if (poly != nullptr)
	//	{
	//		auto pc = MUXM::PointCollection();
	//		for (auto const point : polyNodes)
	//		{
	//			pc.Append(WF::Point(point.first, point.second));
	//		}
	//		poly.Points(pc);
	//	}
	//}

}
