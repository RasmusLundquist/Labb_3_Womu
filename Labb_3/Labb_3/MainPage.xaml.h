//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "PageUpdateRoom.g.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void RedirectUpdate(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void RedirectNewRoom(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
