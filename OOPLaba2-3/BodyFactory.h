#pragma once
#include "Ball.h"
#include "Parallelepiped.h"
#include "Cone.h"
#include <string>
#include <iostream>

namespace ShapeTypes
{
	const int PARALLELEPIPED = 1;
	const int CONE = 2;
	const int BALL = 3;

};

class BodyFactory
{
public:
	BodyFactory(std::ostream& out, std::istream& in) :
		_in(in),
		_out(out),
		_chooseFigureMessage("\n 1- Parallelepiped, 2-Cone, 3-Ball \n\n Select one of the shapes: "),
		_invalidTypeMessage("Invalid type!")
	{}
	~BodyFactory() = default;


	Body* Create()
	{
		_out << _chooseFigureMessage;
		int type;
		_in >> type;


		switch (type)
		{

		case(ShapeTypes::PARALLELEPIPED) : { return CreateParallelepiped(); break; }
		case(ShapeTypes::CONE) : {return CreateCone(); break; }
		case(ShapeTypes::BALL) : {return CreateBall(); break; }

		default:{_out << _invalidTypeMessage; return nullptr; }

		}

	};
private:
	Parallelepiped* CreateParallelepiped()
	{

		float widht, height, length;
		_out << "Enter parametrs of Parallelepiped \n";
		_out << "Width: ";
		_in >> widht;
		_out << "height: ";
		_in >> height;
		_out << "length: ";
		_in >> length;
		
		
		return new Parallelepiped(widht, height, length);

	}
	Cone *CreateCone()
	{
		float radius, generatrix, height;
		_out << "Enter parametrs of Cone \n";
		_out << "radius: ";
		_in >> radius;
		_out << "generatix: ";
		_in >> generatrix;
		_out << "height: ";
		_in >> height;
		return new Cone(radius, generatrix, height);

	}
	Ball *CreateBall()
	{
		float radius;
		_out << "Enter radius of Ball: ";
		_in >> radius;
		return new Ball(radius);
	}

	std::istream& _in;
	std::ostream& _out;
	const std::string _chooseFigureMessage;
	const std::string _invalidTypeMessage;
	const std::string _helpMessage;
};



