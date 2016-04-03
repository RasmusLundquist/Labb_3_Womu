//
// PageListRooms.xaml.cpp
// Implementation of the PageListRooms class
//

#include "pch.h"
#include "PageListRooms.xaml.h"

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

PageListRooms::PageListRooms()
{
	InitializeComponent();
	setRooms();
	choseRoomListBox->ItemsSource = storageName;
}

void PageListRooms::setRooms(){
	storageName->Clear();
	StorageFolder^ localFile = ApplicationData::Current->LocalFolder;
	auto createFileTask = create_task(localFile->GetFilesAsync()).then([=](IVectorView<StorageFile^>^ filesInStorage) {
		for (auto x = filesInStorage->First(); x->HasCurrent; x->MoveNext()) {
			int i = 0;
			String^ name;
			StorageFile^ f;
			f = x->Current;
			name = f->Name;
			storageName->InsertAt(i, name);
			i++;
		}
	});
}


void Labb_3::PageListRooms::choseRoomListBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	Object^ a = choseRoomListBox->SelectedItem;
	Room b;
}
