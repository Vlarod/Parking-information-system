#include "Stall.h"



Stall::Stall(int id, int parkId, int state, int type, int x, int y, int deleted, std::string spz, std::string reservationStart, std::string reservationEnd, int orientation, int stallHeight, int stallWidth)
{
	this->id = id;
	this->parkId = parkId;
	this->state = state;
	this->type = type;
	this->x = x;
	this->y = y;
	this->deleted = deleted;
	this->spz = spz;
	this->reservationStart = reservationStart;
	this->reservationEnd = reservationEnd;
	this->orientation = orientation;
	this->stallHeight = stallHeight;
	this->stallWidth = stallWidth;
}

Stall::Stall(int id, int parkId, int state, int type, int x, int y, int deleted, int orientation, int stallHeight, int stallWidth)
{
	this->id = id;
	this->parkId = parkId;
	this->state = state;
	this->type = type;
	this->x = x;
	this->y = y;
	this->deleted = deleted;
	this->orientation = orientation;
	this->stallHeight = stallHeight;
	this->stallWidth = stallWidth;
}

Stall::Stall(int id, int x, int y)
{
	this->id = id;
	this->state = 0;
	this->type = 0;
	this->x = x;
	this->y = y;
}

Stall::Stall(int x, int y, int orientation, int stallHeight, int stallWidth)
{
	this->state = 0;
	this->type = 0;
	this->x = x;
	this->y = y;
	this->orientation = orientation;
	this->stallHeight = stallHeight;
	this->stallWidth = stallWidth;
}

Stall::Stall(int id, int x, int y, int orientation, int stallHeight, int stallWidth)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->orientation = orientation;
	this->stallHeight = stallHeight;
	this->stallWidth = stallWidth;
}

int Stall::getId()
{
	return id;
}

int Stall::getParkId()
{
	return parkId;
}

int Stall::getState()
{
	return state;
}

int Stall::getType()
{
	return type;
}

int Stall::getX()
{
	return x;
}

int Stall::getY()
{
	return y;
}

int Stall::getDeleted()
{
	return this->deleted;
}

std::string Stall::getSpz()
{
	return this->spz;
}

std::string Stall::getReservationStart()
{
	return this->reservationStart;
}

std::string Stall::getReservationEnd()
{
	return reservationEnd;
}

int Stall::getOrientation()
{
	return this->orientation;
}

int Stall::getStallHeight()
{
	return this->stallHeight;
}

int Stall::getStallWidth()
{
	return this->stallWidth;
}


void Stall::setStallType(int newType)
{
	this->type = newType;
}

void Stall::setSpz(std::string newSpz)
{
	this->spz = newSpz;
}

void Stall::setReservationStart(std::string newReservationStart)
{
	this->reservationStart = newReservationStart;
}

void Stall::setReservationEnd(std::string newReservationEnd)
{
	this->reservationEnd = newReservationEnd;
}

