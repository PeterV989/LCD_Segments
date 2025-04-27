#pragma once
#include "DebugHelpers.h"
#include "MyDigit.h"
#include "ValueToText.h"
#include "MainWindow.g.h"

    namespace MUX = winrt::Microsoft::UI::Xaml;
    namespace MUXC = MUX::Controls;
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
            Windows::Foundation::IInspectable const& d,
            Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);

        void HeightSlider_ValueChanged(
            Windows::Foundation::IInspectable const&,
            Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);

        void SlantSlider_ValueChanged(
            Windows::Foundation::IInspectable const&,
            Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);


        void DrawDigit();

        MyDigit m_polygon;

    private:
        // event_token Loaded(RoutedEventHandler const& handler);

        DebugHelpers m_dh;

        bool m_IsLoaded{false};
    };

}

namespace winrt::LCD_Segments::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
