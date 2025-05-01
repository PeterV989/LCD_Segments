#pragma once
#include "DebugHelpers.h"
#include "MyDigit.h"
#include "ValueToText.h"
#include "MainWindow.g.h"

    namespace MUX = winrt::Microsoft::UI::Xaml;
    namespace MUXC = MUX::Controls;
    namespace MUXCP = MUXC::Primitives;
    namespace MUXS = MUX::Shapes;
    namespace MUXM = MUX::Media;
    namespace WF = winrt::Windows::Foundation;
    namespace WU = winrt::Windows::UI;

namespace winrt::LCD_Segments::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        // Event Handler(s)
        void OnLoaded(WF::IInspectable const&, MUX::RoutedEventArgs const&);
        void WidthSlider_ValueChanged(
            WF::IInspectable const& d,
            MUXCP::RangeBaseValueChangedEventArgs const& e);

        void HeightSlider_ValueChanged(
            WF::IInspectable const&,
            MUXCP::RangeBaseValueChangedEventArgs const& e);

        void SlantSlider_ValueChanged(
            WF::IInspectable const&,
            MUXCP::RangeBaseValueChangedEventArgs const& e);

        void LoadPoints(
            MUXS::Polygon const& poly,
            MUXC::TextBlock const& text,
            Seg seg);


        void DrawDigit();

        MyDigit m_polygon;

    private:
        // event_token Loaded(RoutedEventHandler const& handler);

        DebugHelpers m_dh;

        bool m_IsLoaded{false};
    public:
        void CopyToClipboard_Click(WF::IInspectable const& sender, MUX::RoutedEventArgs const& e) const;
    };

}

namespace winrt::LCD_Segments::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
