//
// PageUpdateRoom.xaml.h
// Declaration of the PageUpdateRoom class
//

#pragma once

#include "PageUpdateRoom.g.h"
#include "Room.h"
#include "PageCreateWall.g.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PageUpdateRoom sealed
	{
	public:
		PageUpdateRoom();
	private:
		void textBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		std::list<Room> roomList;
		void manualButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		Room currentRoom;
	};
}
