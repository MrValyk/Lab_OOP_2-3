#pragma once
#include "Body.h"
#include <fstream>
class Cone :public Body
{
public:
	Cone()=default;
	Cone(float radius, float generatrix, float height)
		: _radius(radius),
		_generatrix(generatrix),
		_height(height)
	{}
	virtual ~Cone(){};

	friend std::istream& operator >>(std::istream& is, Cone& cone);


	virtual float GetArea() override final      //Площадь 
	{
		return (2 * PI *_radius*(_radius + _generatrix));
	};

	
	virtual  float	GetVolume()  override final  //Объем
	{
		return(   (PI * _radius *_radius * _height) /3 );
	};

private:
	float _radius;
	float _generatrix;	// образующая
	float _height;

};
std::istream& operator >>(std::istream& is, Cone& cone)
{
	is >> cone._radius >> cone._generatrix >> cone._height;; //задаем радиус, высоту и образующую.
	return is;
}




