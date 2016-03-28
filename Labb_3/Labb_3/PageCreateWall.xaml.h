//
// PageCreateWall.xaml.h
// Declaration of the PageCreateWall class
//

#pragma once

#include "PageCreateWall.g.h"

namespace Labb_3
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PageCreateWall sealed
	{
		Room^ requestedRoom;
		

	public:
		PageCreateWall();
		void setWallImage(Windows::UI::Xaml::Controls::Image^ img);
		Windows::UI::Xaml::Controls::Image^ getWallImage();
		
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		void saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addImageButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		Windows::UI::Xaml::Controls::Image^ wallPicture;
		
	};
}
