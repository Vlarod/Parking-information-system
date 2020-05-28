#pragma once
#include <string>
#include <occi.h>
class Park_StallSync
{
private:
	int parkId;
	int version;
	oracle::occi::Timestamp updateTimestamp;
	oracle::occi::Timestamp insertTimestamp;
public:
	Park_StallSync(int parkId, oracle::occi::Timestamp updateTimestamp, oracle::occi::Timestamp insertTimestamp);
	Park_StallSync(int parkId, int version, oracle::occi::Timestamp updateTimestamp, oracle::occi::Timestamp insertTimestamp);

	int getParkoId();
	int getVersion();
	oracle::occi::Timestamp getUpdateTimestamp();
	oracle::occi::Timestamp getInsertTimestamp();

	void setUpdateTimestamp(oracle::occi::Timestamp newTimestamp);
	void setInsertTimestamp(oracle::occi::Timestamp newTimestamp);
	void setVersion(int newVersion);
};

