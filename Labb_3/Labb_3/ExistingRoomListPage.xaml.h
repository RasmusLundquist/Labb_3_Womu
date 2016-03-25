//
// ExistingRoomListPage.xaml.h
// Declaration of the ExistingRoomListPage class
//

#pragma once

#include "ExistingRoomListPage.g.h"
#include "Room.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ExistingRoomListPage sealed
	{
	public:
		ExistingRoomListPage();
	private:
		void RedirectRoom(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
	};
}
