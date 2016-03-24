#pragma once

#include <set>
#include <functional>
#include <map>
/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data, std::string const &stationType) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> * observer, int priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> * observer) = 0;
};


// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	CObservable(std::string const &stationType) :
		m_stationType(stationType)
	{};

	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType * observer, int priority) override
	{
		m_observers.emplace(priority, observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		auto observers = m_observers;
		for (auto it = observers.rbegin(); it != observers.rend(); ++it)
		{
			it->second->Update(data, m_stationType);
		}
	}

	void RemoveObserver(ObserverType * observer) override
	{
		for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			if (it->second == observer)
			{
				m_observers.erase(it);
				break;
			}
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::map<int, ObserverType*> m_observers;
	std::string m_stationType;
};
