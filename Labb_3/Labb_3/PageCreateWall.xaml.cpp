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

		requestedRoom->addWall(newWall);
		if (requestedRoom->getVolume() == NULL)
			requestedRoom->setVolume(hej);

		//bra o kolla om förändringen går igenom dvs så att rummet finns när man går tillbaka i vyn.
		warningTextBlock->Text = "The wall has been added to your room";
		//Här borde man då kanske bli redirected till den föregående vyn? det verkar som att det fungerar
	}
}
