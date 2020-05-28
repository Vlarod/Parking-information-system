#include "Park.h"



Park::Park(int id, std::string name, std::string adress, int capacity, int status)
{
	this->id = id;
	this->name = name;
	this->adress = adress;
	this->capacity = capacity;
	this->status = status;
}

Park::Park(int id, std::string name, std::string adress, int capacity, int status, double latitude, double longtitude)
{
	this->id = id;
	this->name = name;
	this->adress = adress;
	this->capacity = capacity;
	this->status = status;
	this->latitude = latitude;
	this->longtitude = longtitude;
}

Park::Park()
{
}

int Park::getId()
{
	return this->id;
}

std::string Park::getName()
{
	return this->name;
}

std::string Park::getAdress()
{
	return adress;
}

int Park::getCapacity()
{
	return capacity;
}

int Park::getStatus()
{
	return status;
}

double Park::getLatitude()
{
	return this->latitude;
}

double Park::getLongtitude()
{
	return this->longtitude;
}

void Park::setId(int newId)
{
	this->id = newId;
}

void Park::setName(std::string newName)
{
	this->name = newName;
}

void Park::setAdress(std::string newAdress)
{
	this->adress = newAdress;
}

void Park::setCapacity(int newCapacity)
{
	this->capacity = newCapacity;
}

void Park::setStatus(int newStatus)
{
	this->status = newStatus;
}
