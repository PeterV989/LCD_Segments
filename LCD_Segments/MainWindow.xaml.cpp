#include "pch.h"
#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include "DebugHelpers.h"
#include "MyDigit.h"
#include "ValueToText.h"
#include <sstream>
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>
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

	void MainWindow::OnLoaded(WF::IInspectable const&, MUX::RoutedEventArgs const&)
	{
		m_IsLoaded = true;

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

	// Take the calculated points (found in m_polygon)
	// and create the <Polygon>. Further, create the
	// list of X,Y coordinates, separated by a space,
	// as the <TextBlock> to prepare to copy them
	// to the clipboard.
	void MainWindow::LoadPoints(
		MUXS::Polygon const& poly,
		MUXC::TextBlock const& text,
		Seg seg)
	{
		if (poly == nullptr) return;
		if (poly.Points() == nullptr)
		{
			poly.Points(MUXM::PointCollection());
		}
		poly.Points().Clear();
		std::wstringstream woss;
		bool bFirst(true);
		woss << std::fixed << std::setprecision(0);
		for (int p = 0; p < m_polygon.Size(seg); p++)
		{
			WF::Point pnt = m_polygon.GetPoint(seg, p);
			if (!bFirst) woss << L" ";
			bFirst = false;
			woss << pnt.X << L"," << pnt.Y;
			poly.Points().Append(pnt);
		}
		winrt::hstring pointstring(woss.str());
		text.Text(pointstring);
	}

	void MainWindow::DrawDigit()
	{
		if (!m_IsLoaded) return;
		try {
			LoadPoints(A_Segment(), Points_A(), Seg::A);
			LoadPoints(B_Segment(), Points_B(), Seg::B);
			LoadPoints(C_Segment(), Points_C(), Seg::C);
			LoadPoints(D_Segment(), Points_D(), Seg::D);
			LoadPoints(E_Segment(), Points_E(), Seg::E);
			LoadPoints(F_Segment(), Points_F(), Seg::F);
			LoadPoints(G_Segment(), Points_G(), Seg::G);
		}
		catch (...) {
			std::cerr << "Caught an exception while debugging\n";
		}
	}

	void MainWindow::CopyToClipboard_Click([[maybe_unused]] WF::IInspectable const& sender, [[maybe_unused]] MUX::RoutedEventArgs const& e) const
	{

		std::wostringstream copyBlock;
		copyBlock << std::fixed << std::setprecision(0);
		auto root = Content().try_as<MUX::FrameworkElement>();
		if (root != nullptr)
		{
			copyBlock << L"<!-- Width: " << m_polygon.Width() << " Height: " << m_polygon.Height() << L" Slant: " << m_polygon.Slant() << L" -->\n";
			for (int i = static_cast<int>(Seg::A); i <= static_cast<int>(Seg::G); i++)
			{
				Seg seg = static_cast<Seg>(i);

				if (auto pointsBlock = root.FindName(L"Points_" + ToHString(seg)).try_as<MUXC::TextBlock>())
				{
					copyBlock << L"<Polygon x:Name=\"Segment_" << ToHString(seg) << L"\" ";
					copyBlock << L"Points=\"" << pointsBlock.Text() << L"\"/>\n";
				}
			}
			std::wstring wCopyBlock = copyBlock.str();
			if (wCopyBlock.size() > 0)
			{
				auto dataPackage = winrt::Windows::ApplicationModel::DataTransfer::DataPackage();
				dataPackage.SetText(wCopyBlock);
				winrt::Windows::ApplicationModel::DataTransfer::Clipboard::SetContent(dataPackage);
			}
		}
	}
}