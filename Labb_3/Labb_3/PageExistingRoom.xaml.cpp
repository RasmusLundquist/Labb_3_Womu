﻿//
// PageExistingRoom.xaml.cpp
// Implementation of the PageExistingRoom class
//

#include "pch.h"
#include "PageExistingRoom.xaml.h"

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

PageExistingRoom::PageExistingRoom()
{
	InitializeComponent();
	
}


void Labb_3::PageExistingRoom::Redirect_Update(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(PageUpdateRoom::typeid));
}


void Labb_3::PageExistingRoom::goBackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
}
