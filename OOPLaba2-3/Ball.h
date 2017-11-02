#pragma once
#include "Body.h"
#include <fstream>
class Ball :public Body
{
public:
	Ball() = default;
	Ball(float rad) :_radius(rad){}

	virtual ~Ball(){};

	friend std::istream& operator >>(std::istream& is, Ball& ball);

	virtual float	GetArea()override final//Площадь
	{
		return (4 * PI * _radius*_radius);//Быстрее чем обращение к библиотечной функции
	};

	
	virtual  float	GetVolume()override final//Объем
	{
		return (4 / 3 * _radius * PI);
	};

private:
	float _radius;

};

std::istream& operator >>(std::istream& is, Ball& ball)
{
	is >> ball._radius; //задаем радиус
	return is;
}

