//
// PageCreateWall.xaml.cpp
// Implementation of the PageCreateWall class
//

#include "pch.h"
#include "PageCreateWall.xaml.h"

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
using namespace Windows::Media::Capture;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml::Media::Imaging;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

PageCreateWall::PageCreateWall()
{
	InitializeComponent();
}

void PageCreateWall::OnNavigatedTo(NavigationEventArgs^ e)
{
	requestedRoom = (Room^)e->Parameter;
}


void Labb_3::PageCreateWall::saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Wall^ newWall = ref new Wall();

	if (areaTextBlock->Text == nullptr || titleTextBox->Text == nullptr || descTextBox->Text == nullptr)
		warningTextBlock->Text = "Please enter Text, Title and Description for your wall!";
	else {
		//How do we convert the textblock to double?


		Platform::String^ platform_string = areaTextBox->Text;
		const wchar_t* wide_chars = platform_string->Data();
		char chars[512];
		wcstombs(chars, wide_chars, 512);

		double hej = atof(chars);

		newWall->setArea(hej);

		newWall->setDetailedDesc(descTextBox->Text);
		newWall->setTitle(titleTextBox->Text);
		//7Göra typ en if sats här för att kolla om det finns en bild men just nu fakkar vs med mig
		newWall->setWallImage(wallPicture);

		requestedRoom->addWall(newWall);
		if (requestedRoom->getVolume() == NULL)
			requestedRoom->setVolume(hej);
		

		//bra o kolla om förändringen går igenom dvs så att rummet finns när man går tillbaka i vyn.
		warningTextBlock->Text = "The wall has been added to your room";
		//Här borde man då kanske bli redirected till den föregående vyn? det verkar som att det fungerar
	}
}

///Use this function to set a image stored locally
void Labb_3::PageCreateWall::setWallImage(Image^ img) {
	wallPicture = img;
}

///Use this function whenever we are going to add image to the created wall before we add it to the room
Windows::UI::Xaml::Controls::Image^ Labb_3::PageCreateWall::getWallImage() {
	return wallPicture;
}

void Labb_3::PageCreateWall::addImageButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	CameraCaptureUI^ dialog = ref new CameraCaptureUI();

	concurrency::task<StorageFile^>(dialog->CaptureFileAsync(CameraCaptureUIMode::Photo)).then([this](StorageFile^ file)
	{
		if (nullptr != file)
		{
			concurrency::task<Streams::IRandomAccessStream^>(file->OpenAsync(FileAccessMode::Read)).then([this](Streams::IRandomAccessStream^ stream)
			{
				BitmapImage^ bitmapImage = ref new BitmapImage();
				bitmapImage->SetSource(stream);
				Image^ something = ref new Image();
				
				something->Source = bitmapImage;
				//Spara bilden i klassen så att vi kommer åt den när vi ska spara väggen
				PageCreateWall::setWallImage(something);
				//Visa bilden i framen på sidan
				cameraFrame->Content = something;
			});

			
		}
		else
		{
			return;
		}
	});

}
