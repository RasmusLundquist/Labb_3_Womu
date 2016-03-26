//
// PageUpdateRoom.xaml.cpp
// Implementation of the PageUpdateRoom class
//

#include "pch.h"
#include "PageUpdateRoom.xaml.h"

using namespace Labb_3;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

#include <stdlib.h>

PageUpdateRoom::PageUpdateRoom()
{
	
	InitializeComponent();
	this->NavigationCacheMode = Windows::UI::Xaml::Navigation::NavigationCacheMode::Enabled;
}


void Labb_3::PageUpdateRoom::textBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}


void Labb_3::PageUpdateRoom::saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	

	if (roomNameTextBox->Text == nullptr || detailsRoomTextBox->Text == nullptr) {
		String^ warning = "Please enter a title and detailed description for your room!";
		warningTextBlock->Text = warning;
	}

	else {
		if (currentRoom == nullptr) {
			currentRoom = ref new Room();
		}
		
		
		currentRoom->setTitle(roomNameTextBox->Text);
		currentRoom->setDetailedDesc(detailsRoomTextBox->Text);
		//We are suposed to save the room to the file in the flash memory though
		//Handle this here
		//But in the meantime it's "saved" locally
		roomList.push_back(currentRoom);
		warningTextBlock->Text = "Your room has been saved!";


		//Also this should contain function for calculating the area
		//First we must handle adding the walls to the room though
		//Since we wanted to calculate the area just once depending on the area for the first added wall
	}


}


void Labb_3::PageUpdateRoom::manualButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (currentRoom == nullptr) {
		currentRoom = ref new Room();
	}

	currentRoom->setTitle(roomNameTextBox->Text);
	currentRoom->setDetailedDesc(detailsRoomTextBox->Text);

	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PageCreateWall::typeid),currentRoom);
}
