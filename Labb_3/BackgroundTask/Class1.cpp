#include "pch.h"
#include "Class1.h"
//
//using namespace BackgroundTask;
//using namespace Platform;
//using namespace Windows::ApplicationModel::Background;
//using namespace Windows::Devices::Geolocation;
//using namespace Windows::Devices::Geolocation::Geofencing;
//using namespace Concurrency;
//using namespace Windows::Globalization::DateTimeFormatting;
//using namespace Windows::Storage;
//using namespace Windows::Foundation;
//using namespace Windows::Data::Json;
//using namespace Windows::Data::Xml::Dom;
//
BackgroundTask::Class1::Class1()
{
}

//void BackgroundTask::Class1::Run(IBackgroundTaskInstance ^ instance)
//{
//	Agile<BackgroundTaskDeferral> deferral(instance->GetDeferral);
//	instance->Canceled += ref new BackgroundTaskCanceledEventHandler(this, &Class1::OnCancelled);
//	Geolocator^ locator = ref new Geolocator();
//	task<Geoposition^> positioningTask(locator->GetGeopositionAsync(), positioningTaskSource.get_token());
//
//	positioningTask.then([this, deferral, locator](task<Geoposition^> getTask) {
//		DateTimeFormatter^ formatter = ref new DateTimeFormatter("longtime");
//		auto settings = ApplicationData::Current->LocalSettings;
//		try {
//			Geoposition^ pos = getTask.get();
//			
//			settings->Values->Insert("Status", "Time: " + formatter->Format(pos->Coordinate->Timestamp));
//			settings->Values->Insert("Latitude", pos->Coordinate->Point->Position.Latitude.ToString());
//			settings->Values->Insert("Longitude", pos->Coordinate->Point->Position.Longitude.ToString());
//			settings->Values->Insert("Accuracy", pos->Coordinate->Accuracy.ToString());
//		}
//		catch (Platform::AccessDeniedException^) {
//			settings->Values->Insert("Status", "Disabled");
//			settings->Values->Insert("Latitude", "No data");
//			settings->Values->Insert("Longitude", "No data");
//		}
//		catch (Exception^ e) {
//			settings->Values->Insert("Latitude", "No data");
//			settings->Values->Insert("Longitude", "No data");
//			settings->Values->Insert("Accuracy", "No data");
//#if (WINAPI_FAMILY == WINAPI_FAMILY_PC_APP)
//			if (e->HResult == HRESULT_FROM_WIN32(WAIT_TIMEOUT))
//				settings->Values->Insert("Status", "Failed to access locationing sensors, it's possible that there are none available.");
//			else
//#endif
//				settings->Values->Insert("Status", e->ToString());
//		}
//			deferral->Complete();
//	});
//}
//
//void BackgroundTask::Class1::OnCancelled(IBackgroundTaskInstance^ instance, BackgroundTaskCancellationReason r) {
//
//}
//
//void BackgroundTask::GeofenceBackground::Run(Windows::ApplicationModel::Background::IBackgroundTaskInstance ^ instance)
//{
//	throw ref new Platform::NotImplementedException();
//}
