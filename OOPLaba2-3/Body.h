#pragma once


class Body 
{
public:
	Body() = default;
	virtual ~Body(){};
	virtual float	GetArea() = 0; //�������
	virtual  float	GetVolume() = 0;//�����
};
static const float PI = 3.1415926535;