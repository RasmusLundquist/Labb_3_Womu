//
// MagicOptionPage.xaml.h
// Declaration of the MagicOptionPage class
//

#pragma once

#include "MagicOptionPage.g.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MagicOptionPage sealed
	{

		Room^ requestedRoom;

	public:
		MagicOptionPage();

		void setWallImage(Windows::UI::Xaml::Controls::Image^ img);
		Windows::UI::Xaml::Controls::Image^ getWallImage();
		void manageCamera();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		Windows::UI::Xaml::Controls::Image^ wallPicture;
		void addImageButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
