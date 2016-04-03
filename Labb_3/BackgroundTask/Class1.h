#pragma once

namespace BackgroundTask
{
	public ref class Class1 sealed
  {
		Concurrency::cancellation_token_source positioningTaskSource;
	public:
		Class1();
		//virtual void Run(Windows::ApplicationModel::Background::IBackgroundTaskInstance^ instance);
		//void OnCancelled(IBackgroundTaskInstance^ instance, BackgroundTaskCancellationReason r);
    };

	//public ref class GeofenceBackground sealed : public Windows::ApplicationModel::Background::IBackgroundTask {
	//	
	//public:
	//	virtual void Run(Windows::ApplicationModel::Background::IBackgroundTaskInstance^ instance);
	//};
}
