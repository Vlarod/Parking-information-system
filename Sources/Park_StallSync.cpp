#include "Park_StallSync.h"



Park_StallSync::Park_StallSync(int parkId, oracle::occi::Timestamp updateTimestamp, oracle::occi::Timestamp insertTimestamp)
{
	this->parkId = parkId;
	this->updateTimestamp = updateTimestamp;
	this->insertTimestamp = insertTimestamp;
}

Park_StallSync::Park_StallSync(int parkId, int version, oracle::occi::Timestamp updateTimestamp, oracle::occi::Timestamp insertTimestamp)
{
	this->parkId = parkId;
	this->version = version;
	this->updateTimestamp = updateTimestamp;
	this->insertTimestamp = insertTimestamp;
}

int Park_StallSync::getParkoId()
{
	return parkId;
}

int Park_StallSync::getVersion()
{
	return version;
}

oracle::occi::Timestamp Park_StallSync::getUpdateTimestamp()
{
	return updateTimestamp;
}

void Park_StallSync::setUpdateTimestamp(oracle::occi::Timestamp newTimestamp)
{
	this->updateTimestamp = newTimestamp;
}

oracle::occi::Timestamp Park_StallSync::getInsertTimestamp()
{
	return insertTimestamp;
}

void Park_StallSync::setInsertTimestamp(oracle::occi::Timestamp newTimestamp)
{
	this->insertTimestamp = newTimestamp;
}

void Park_StallSync::setVersion(int newVersion)
{
	this->version = newVersion;
}
