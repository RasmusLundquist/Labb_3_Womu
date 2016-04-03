//
// MagicOptionPage.xaml.cpp
// Implementation of the MagicOptionPage class
//

#include "pch.h"
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
using namespace Windows::Devices::Sensors;

using namespace Windows::Media::Capture;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml::Media::Imaging;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

/// <summary>
/// MagicOptionPage This page is the page navigated to when the user choses the magical option to add a wall.
/// </summary>
MagicOptionPage::MagicOptionPage()
{
	InitializeComponent();
}

/// <summary>
/// setWallImage method to enable to change the picture which is stored locally in order to save it whenever the user wants to save the w
/// </summary>
/// <param name="img">a Image pointer which represent the image of the wallwhich the user wants to save</param>
void MagicOptionPage::setWallImage(Windows::UI::Xaml::Controls::Image^ img) {
	wallPicture = img;
}

/// <summary>
/// getWallImage method to enable to retrieve the image which the user wants to save
/// </summary>
/// <return>returns a Image pointer to the image object which represents the image</return>
Windows::UI::Xaml::Controls::Image^ MagicOptionPage::getWallImage() {
	return wallPicture;
}

void MagicOptionPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	requestedRoom = (Room^)e->Parameter;

	manageCamera();
}

void Labb_3::MagicOptionPage::addImageButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	manageCamera();
}

/// <summary>
/// manageCamera method to start the camera for the user and let the user take a picture of a wall.
/// </summary>
void Labb_3::MagicOptionPage::manageCamera() {
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
				MagicOptionPage::setWallImage(something);
				//Visa bilden i framen på sidan
				cameraFrame->Content = something;
			});


		}
		else
		{
			return;
		}
	});


	Inclinometer^ gyro = Inclinometer::GetDefault();



	InclinometerReading^ direction = gyro->GetCurrentReading();

	double x = direction->PitchDegrees;
	double y = direction->RollDegrees;
	double z = direction->YawDegrees;

	auto currentOrientation = SimpleOrientationSensor::GetDefault()->GetCurrentOrientation();

	//Rotated90DegreesCounterclockwise
	auto val = SimpleOrientation::Rotated180DegreesCounterclockwise.ToString();

	if (y > 0 && y > 90) {
		this->titleTextBox->Text = "Floor";
		this->descTextBox->Text = "Suggested text: This is my beautiful floor!";
		this->areaTextBox->Text = "10";
		return;
	}
	if (y<0 && y > -90) {
		//detta är taket
		this->titleTextBox->Text = "Roof";
		this->descTextBox->Text = "Suggested text: This is my beautiful roof!";
		this->areaTextBox->Text = "10";
		return;
	}
	if ((x>= 179&& x <= 180) || (x <= -179 && x >= -180)) {
		//detta är höger vägg
		this->titleTextBox->Text = "Right Wall";
		this->descTextBox->Text = "Suggested text: This is my beautiful right wall!";
		this->areaTextBox->Text = "10";
		return;
	}
	if (x >= -1 && x <= 1) {
		//detta är vänster vägg
		this->titleTextBlock->Text = "Left wall";
		this->descTextBlock->Text = "Suggested text: This is my beautiful left wall!";
		this->areaTextBlock->Text = "10";
		return;
	}
	//Det är svårt att testa vilka riktningar som värdena har när man inte kan rotera telefonen i emulatorn hur man vill


		//This is 
}