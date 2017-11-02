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

	virtual float	GetArea()override final//�������
	{
		return (4 * PI * _radius*_radius);//������� ��� ��������� � ������������ �������
	};

	
	virtual  float	GetVolume()override final//�����
	{
		return (4 / 3 * _radius * PI);
	};

private:
	float _radius;

};

std::istream& operator >>(std::istream& is, Ball& ball)
{
	is >> ball._radius; //������ ������
	return is;
}

