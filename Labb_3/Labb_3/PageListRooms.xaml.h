//
// PageListRooms.xaml.h
// Declaration of the PageListRooms class
//

#pragma once

#include "PageListRooms.g.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PageListRooms sealed
	{
	public:
		PageListRooms();
	private:
		Platform::Collections::Vector<String^>^ storageName;
		void setRooms();
		void choseRoomListBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
	};
}