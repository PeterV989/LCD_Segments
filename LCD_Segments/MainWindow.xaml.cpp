#include "pch.h"
#include "MyDigit.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::LCD_Segments::implementation
{
	namespace MUX = winrt::Microsoft::UI::Xaml;
	namespace MUXC = MUX::Controls;
	namespace MUXS = MUX::Shapes;
	namespace MUXM = MUX::Media;
	namespace WF = winrt::Windows::Foundation;

	MainWindow::MainWindow()
	{
		InitializeComponent();
		auto sw = SliderWidth().as<MUXC::Slider>();
		sw.ValueChanged({ this, &MainWindow::WidthSlider_ValueChanged });
		m_polygon.Width(static_cast<float>(sw.Value()));
		WidthSliderValue().Text(L"" + std::to_wstring(static_cast<int>(m_polygon.Width())));

		auto sh = SliderHeight().as<MUXC::Slider>();
		sh.ValueChanged({ this, &MainWindow::HeightSlider_ValueChanged });
		m_polygon.Height(static_cast<float>(sh.Value()));
		HeightSliderValue().Text(L"" + std::to_wstring(static_cast<int>(m_polygon.Height())));

		auto ss = SliderSlant().as<MUXC::Slider>();
		ss.ValueChanged({ this, &MainWindow::SlantSlider_ValueChanged });
		m_polygon.Slant(static_cast<float>(ss.Value()));
		SlantSliderValue().Text(L"" + std::to_wstring(m_polygon.Slant()));
	}

	void MainWindow::WidthSlider_ValueChanged(WF::IInspectable const& d, MUXC::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		m_polygon.Width(static_cast<float>(e.NewValue()));
		WidthSliderValue().Text(L"" + std::to_wstring(m_polygon.Width()));
		if (auto ctl = d.try_as<MUXS::Polygon>())
		{
			UpdatePoints(ctl, m_polygon.Top());
		}
	}

	void MainWindow::HeightSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		m_polygon.Height(static_cast<float>(e.NewValue()));
		HeightSliderValue().Text(L"" + std::to_wstring(m_polygon.Height()));
		// UpdateSlant(angle);
	}

	void MainWindow::SlantSlider_ValueChanged(WF::IInspectable const&, MUXC::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		m_polygon.Slant(static_cast<float>(e.NewValue()));
		SlantSliderValue().Text(L"" + std::to_wstring(m_polygon.Slant()));
		// UpdateSlant(angle);
	}

	void MainWindow::DrawDigit()
	{

	}

	void MainWindow::UpdatePoints(MUXS::Polygon const& poly, const MUXM::PointCollection& polyNodes)
	{
		poly.Points().Clear();
		for (auto const point : polyNodes)
		{
			poly.Points().Append(point);
		}
	}

}
