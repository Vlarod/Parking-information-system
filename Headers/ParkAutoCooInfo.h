#pragma once
class ParkAutoCooInfo
{
private:
	int parkId;
	int countFreeFree;
	int countFreeFull;
	int countReserveFree;
	int countReserveFull;
public:
	ParkAutoCooInfo();
	ParkAutoCooInfo(int parkId, int countFreeFree, int countFreeFull, int countReserveFree, int countReserveFull);

	int getParkId();
	int getCountFreeFree();
	int getCountFreeFull();
	int getCountReserveFree();
	int getCountReserveFull();
};

