#include "WeatherData.h"
#include <memory>

int main()
{
	CWeatherData wd("outer");

	shared_ptr<CDisplay> display = make_shared<CDisplay>();
	wd.RegisterObserver(display.get(), 3);

	shared_ptr<CStatsDisplay> statsDisplay = make_shared<CStatsDisplay>();
	wd.RegisterObserver(statsDisplay.get(), 2);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(statsDisplay.get());

	wd.SetMeasurements(10, 0.8, 761);
	wd.SetMeasurements(-10, 0.8, 761);
	return 0;
}