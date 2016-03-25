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
	Wall^ room = (Wall^)e->Parameter;
}
