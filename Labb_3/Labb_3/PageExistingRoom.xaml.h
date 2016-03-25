//
// PageExistingRoom.xaml.h
// Declaration of the PageExistingRoom class
//

#pragma once

#include "PageExistingRoom.g.h"
#include "PageUpdateRoom.g.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PageExistingRoom sealed
	{
	public:
		PageExistingRoom();
	private:
		void Redirect_Update(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
