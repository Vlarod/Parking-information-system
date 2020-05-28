#pragma once
#include <string>
class Park
{
private:
	int id;
	std::string name;
	std::string adress;
	int capacity;
	int status;
	double latitude;
	double longtitude;
public:
	Park(int id, std::string name, std::string adress, int capacity, int status);
	Park(int id, std::string name, std::string adress, int capacity, int status, double latitude, double longtitude);
	Park();

	int getId();
	std::string getName();
	std::string getAdress();
	int getCapacity();
	int getStatus();
	double getLatitude();
	double getLongtitude();

	void setId(int newId);
	void setName(std::string newName);
	void setAdress(std::string newAdress);
	void setCapacity(int newCapacity);
	void setStatus(int newStatus);
};

