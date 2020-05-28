#include "ParkAutoCooInfo.h"



ParkAutoCooInfo::ParkAutoCooInfo()
{
}

ParkAutoCooInfo::ParkAutoCooInfo(int parkId, int countFreeFree, int countFreeFull, int countReserveFree, int countReserveFull)
{
	this->parkId = parkId;
	this->countFreeFree = countFreeFree;
	this->countFreeFull = countFreeFull;
	this->countReserveFree = countReserveFree;
	this->countReserveFull = countReserveFull;
}

int ParkAutoCooInfo::getParkId()
{
	return parkId;
}

int ParkAutoCooInfo::getCountFreeFree()
{
	return countFreeFree;
}

int ParkAutoCooInfo::getCountFreeFull()
{
	return this->countFreeFull;
}

int ParkAutoCooInfo::getCountReserveFree()
{
	return this->countReserveFree;
}

int ParkAutoCooInfo::getCountReserveFull()
{
	return this->countReserveFull;
}
