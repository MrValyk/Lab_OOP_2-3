#pragma once
#include "Body.h"
#include "BodyFactory.h"
#include <iostream>
#include <sstream>
#include <vector>

class App
{
public:
	App() : _bodyFactory(std::cout, std::cin) {}
	void Run()
	{
		unsigned int action;
		do
		{
			Menu();
			if (!Read(action))
			{
				ShowInputError();
				continue;
			}

			switch (action)
			{
			case SHAPE:
			{
				AddShape();
				break;
			}
			case SHOWSHAPE:
			{
				ShowParametrsShape();//показывает на экран
				break;
			}
			case CLEARSHAPE:
			{
				ClearShape();
				break;
			}

			default:
				ShowInputError();
			}
		} while (true);

	}

private:
	static const int SHAPE = 1;
	static const int SHOWSHAPE = 2;
	static const int CLEARSHAPE = 3;

	template<class T>
	bool Read(T& res)
	{
		std::string s;
		std::cin >> s;
		std::istringstream sin(s);
		if ((!(sin >> res)) || (!sin.eof()))
		{
			return false;
		}
		return true;
	}
	void Menu()
	{
		std::cout << "Menu:" << std::endl;
		std::cout << "\n";
		std::cout << SHAPE << ".AddShape " << std::endl;
		std::cout << "----------------------\n";
		std::cout << SHOWSHAPE << ".Show Parametrs Shape" << std::endl;
		std::cout << "----------------------\n";
		std::cout << CLEARSHAPE << ".ClearShape" << std::endl;
		std::cout << "----------------------\n";
		std::cout << "Select one of the menu items:  ";
	}

	void AddShape()
	{
		Body* myshape = _bodyFactory.Create();
		_myShape.push_back(myshape);

	}
	void	ShowParametrsShape()
	{
		for (std::vector<Body*>::iterator it = _myShape.begin(); it != _myShape.end(); it++)
		{
			std::cout << "\n";
			std::cout<< "S="<<(*it)->GetArea()<<"  "<<"V="<<(*it)->GetVolume() <<std::endl;
			std::cout << "\n";
		}

	}
	void ClearShape()
	{
		_myShape.clear();
	}

	void	ShowInputError()
	{
		std::cout << std::endl;
		std::cout << "Error,incorrect input " << std::endl;
	}

private:
	BodyFactory _bodyFactory;
	std::vector <Body*> _myShape;
};
