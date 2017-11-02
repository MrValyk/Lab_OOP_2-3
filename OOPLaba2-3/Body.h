#pragma once


class Body 
{
public:
	Body() = default;
	virtual ~Body(){};
	virtual float	GetArea() = 0; //ֿכמשאהü
	virtual  float	GetVolume() = 0;//־בתול
};
static const float PI = 3.1415926535;