#pragma once
#include "BaseComponent.h"
class PropertyDouble :
	public BaseComponent
{
public:
	PropertyDouble();
	~PropertyDouble();

	//Returns the data as a vector.
	std::vector<double> getData();
	double getData(int);

	//Edit the data.
	void addData(double);
	virtual void deleteData();
	void deleteData(double);
	virtual void deleteDataPosition(int);
	void changeData(double, int);

private:
	std::vector<double> data;
};
