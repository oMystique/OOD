#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"
#include <string>

using namespace std;

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay: public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data, string const &stationType) override
	{
		if (!stationType.empty())
		{
			cout << "Information from " << stationType << " station:" << endl;
		}

		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

struct Stats
{
	double m_minStat = std::numeric_limits<double>::infinity();
	double m_maxStat = -std::numeric_limits<double>::infinity();
	double m_accStat = 0;
	unsigned m_countAcc = 0;
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void SetStatsData(Stats &stat, double currentStat)
	{
		if (stat.m_minStat > currentStat)
		{
			stat.m_minStat = currentStat;
		}
		if (stat.m_maxStat < currentStat)
		{
			stat.m_maxStat = currentStat;
		}
		stat.m_accStat += currentStat;
		++stat.m_countAcc;
	}

	void PrintStatsData(Stats &stat, std::string const &statName)
	{
		std::cout << "Max " << statName << ": " << stat.m_maxStat << std::endl;
		std::cout << "Min " << statName << ": " << stat.m_minStat << std::endl;
		std::cout << "Average " << statName << ": " << (stat.m_accStat / stat.m_countAcc) << std::endl;
		std::cout << "----------------" << std::endl;
	}

	void Update(SWeatherInfo const& data, std::string const &stationType) override
	{
		if (!stationType.empty())
		{
			cout << "Information from " << stationType << " station:" << endl;
		}

		SetStatsData(m_tempStats, data.temperature);
		PrintStatsData(m_tempStats, "Temp");

		SetStatsData(m_humidityStats, data.humidity);
		PrintStatsData(m_humidityStats, "Humidity");

		SetStatsData(m_pressureStats, data.pressure);
		PrintStatsData(m_pressureStats, "Pressure");
	}
private:
	Stats m_tempStats;
	Stats m_humidityStats;
	Stats m_pressureStats;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	CWeatherData(std::string stationType = "") : CObservable(stationType) 
	{}
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;	
	double m_pressure = 760.0;	
};
