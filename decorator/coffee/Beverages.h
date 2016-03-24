#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description) 
	{}

	double GetCost() const override 
	{
		return 60; 
	}
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(unsigned portionType) 
		:CCoffee("Capuccino") ,
		m_portionType(portionType)
	{}

	double GetCost() const override 
	{
		if (m_portionType == 2)
		{
			return 120;
		}
		return 80;
	}
private:
	unsigned m_portionType;
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(unsigned portionType = 1) 
		:CCoffee("Latte") ,
		m_portionType(portionType)
	{}

	double GetCost() const override 
	{
		if (m_portionType == 2)
		{
			return 130;
		}
		return 90;
	}
private:
	unsigned m_portionType;
};

enum class TeaType
{
	classicBlack,
	classicGreen,
	carcade,
	chefir
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(TeaType teaType = TeaType::classicBlack) 
		:CBeverage("Tea"),
		m_teaType(teaType)
	{}

	double GetCost() const override 
	{
		return 30; 
	}
private:
	TeaType m_teaType;
};


enum class MilkshakePortionType
{
	small = 50,
	medium = 60,
	big = 80
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(MilkshakePortionType portionType = MilkshakePortionType::medium) 
		:CBeverage("Milkshake") ,
		m_portionType(portionType)
	{}

	double GetCost() const override 
	{ 
		return static_cast<int>(m_portionType);
	}
private:
	MilkshakePortionType m_portionType;
};
