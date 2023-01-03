#include "Vector4d.h"

Vector4d::Vector4d(int px1, int py1, int px2, int py2)
{
	this->px1 = px1;
	this->py1 = py1;
	this->px2 = px2;
	this->py2 = py2;
}

void Vector4d::setValues(int px1, int py1, int px2, int py2)
{
	this->px1 = px1;
	this->py1 = py1;
	this->px2 = px2;
	this->py2 = py2;
}