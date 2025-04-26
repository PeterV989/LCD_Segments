#pragma once
#include "DebugHelpers.h"
#include "MyDigit.h"
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
        //void WidthSlider_ValueChanged(
        //    Windows::Foundation::IInspectable const& d,
        //    Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);

        //void HeightSlider_ValueChanged(
        //    Windows::Foundation::IInspectable const&,
        //    Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);

        //void SlantSlider_ValueChanged(
        //    Windows::Foundation::IInspectable const&,
        //    Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);
        void UpdateTimer(WF::IInspectable const&, WF::IInspectable const&);


        //void DrawDigit();
        //void UpdatePoints(winrt::Microsoft::UI::Xaml::Shapes::Polygon const& poly, MyPolygon const& polyPoints);

        winrt::LCD_Segments::implementation::MyDigit m_polygon;

    private:
        // event_token Loaded(RoutedEventHandler const& handler);

        winrt::Microsoft::UI::Xaml::DispatcherTimer m_DeferUpdateTimer;
        winrt::LCD_Segments::implementation::DebugHelpers m_dh;

        bool m_IsLoaded;
    };

}

namespace winrt::LCD_Segments::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
