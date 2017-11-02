#pragma once
#include "Body.h"
#include <fstream>
class Parallelepiped :public Body
{
public:
	Parallelepiped() {}
	Parallelepiped(float widht, float lenght, float height)
		: _width(widht),
		_length(lenght),
		_height(height)
	{}
	virtual ~Parallelepiped(){};

	friend std::istream& operator >>(std::istream& is, Parallelepiped&  parallelepiped);

	virtual float GetArea() override final//Площадь
	{
		return (2 * (_width *_length + _width * _height + _length * _height));
	}


	virtual float GetVolume() override final //Объем
	{
		return(_width * _length * _height);
	}

private:
	float  _width;
	float  _length;
	float  _height;

};
std::istream& operator >>(std::istream& is, Parallelepiped&  parallelepiped)
{
	is >> parallelepiped._width >> parallelepiped._length >> parallelepiped._height;;//задаем ширину, высоту и длинну.
	return is;
}
