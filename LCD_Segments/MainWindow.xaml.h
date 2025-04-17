#pragma once

#include "MainWindow.g.h"

namespace winrt::LCD_Segments::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        // Event Handler(s)
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
        void UpdatePoints(winrt::Microsoft::UI::Xaml::Shapes::Polygon const& poly, winrt::Microsoft::UI::Xaml::Media::PointCollection const& polyPoints);

        winrt::LCD_Segments::implementation::MyDigit m_polygon;
    };

}

namespace winrt::LCD_Segments::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
