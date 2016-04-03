//
// PageUpdateRoom.xaml.cpp
// Implementation of the PageUpdateRoom class
//

#include "pch.h"
#include "PageUpdateRoom.xaml.h"
#include <string>
#include "LocationHandler.h"
#include "MagicOptionPage.xaml.h"

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
using namespace Windows::Storage;
using namespace Concurrency;


// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

#include <stdlib.h>

PageUpdateRoom::PageUpdateRoom()
{
	
	InitializeComponent();
	this->NavigationCacheMode = Windows::UI::Xaml::Navigation::NavigationCacheMode::Enabled;
	if (currentRoom != nullptr) {

		listBox->ItemsSource = currentRoom->getWalls();
	}
}


void Labb_3::PageUpdateRoom::textBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}

void PageUpdateRoom::OnNavigatedTo(NavigationEventArgs^ e) {

	if (currentRoom != nullptr) {
		if (!currentRoom->isEmpty()) {
			//Skriv ut väggarna
		}
	}
	else currentRoom = ref new Room();

}


void Labb_3::PageUpdateRoom::saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	StorageFolder^ localFile = ApplicationData::Current->LocalFolder;
	String^ fileName = roomNameTextBox->Text;

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

		task<StorageFile^>(localFile->CreateFileAsync(fileName, CreationCollisionOption::ReplaceExisting)).then([this](StorageFile^ newFile) {
			String^ fileInformation;
			
			fileInformation += currentRoom->getTitle()+ "\n";
			fileInformation += currentRoom->getDetailedDesc() + "\n";
			//fileInformation += currentRoom->getLatitude().ToString + "\n";
			//fileInformation += currentRoom->getLongitude().ToString + "\n";
			
			//Convert the double for the volume into a std::string
			std::string str = std::to_string(currentRoom->getVolume()).c_str();
			
			//Conver the std::string into a Platform::String^
			std::wstring wid_str = std::wstring(str.begin(), str.end());
			const wchar_t* w_char = wid_str.c_str();
			Platform::String^ p_string = ref new Platform::String(w_char);


			fileInformation += p_string + "\n";

			int i = 0;

			while (!currentRoom->isEmpty()) {
				Wall^ loopWall = currentRoom->getWall(i);
				fileInformation += loopWall->getTitle() + "\n";
				fileInformation += loopWall->getDetailedDesc() + "\n";
				fileInformation += loopWall->getArea() + "\n";
				i++;
			}

			create_task(FileIO::WriteTextAsync(newFile, fileInformation)).then([this](task<void> task) {
				/*LocationHandler^ lHandle = ref new LocationHandler();

				lHandle->addLocation(currentRoom);*/
			});
		});

		roomList.push_back(currentRoom);
		warningTextBlock->Text = "Your room has been saved!";

		roomNameTextBox->Text = "";
		detailsRoomTextBox->Text = "";

		currentRoom = nullptr;
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


void Labb_3::PageUpdateRoom::autoButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (currentRoom == nullptr) {
		currentRoom = ref new Room();
	}

	currentRoom->setTitle(roomNameTextBox->Text);
	currentRoom->setDetailedDesc(detailsRoomTextBox->Text);

	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(MagicOptionPage::typeid), currentRoom);

}
