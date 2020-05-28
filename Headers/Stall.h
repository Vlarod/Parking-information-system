#pragma once
#include <string>
#include <occi.h>

class Stall
{
private:
	int id;
	int parkId;
	int state;
	int type;
	int x;
	int y;
	int deleted;
	std::string spz;
	std::string reservationStart;
	std::string reservationEnd;
	int orientation;
	int stallHeight;
	int stallWidth;

public:
	Stall(int id, int parkId, int state, int type, int x, int y, int deleted, std::string spz, std::string reservationStart, std::string reservationEnd, int orientation, int stallHeight, int stallWidth);
	Stall(int id, int parkId, int state, int type, int x, int y, int deleted, int orientation, int stallHeight, int stallWidth);
	Stall(int id, int x, int y);
	Stall(int x, int y, int orientation, int stallHeight, int stallWidth);
	Stall(int id, int x, int y, int orientation, int stallHeight, int stallWidth);

	int getId();
	int getParkId();
	int getState();
	int getType();
	int getX();
	int getY();
	int getDeleted();
	std::string getSpz();
	std::string getReservationStart();
	std::string getReservationEnd();
	int getOrientation();
	int getStallHeight();
	int getStallWidth();

	void setStallType(int newType);
	void setSpz(std::string newSpz);
	void setReservationStart(std::string newReservationStart);
	void setReservationEnd(std::string newReservationEnd);
};

