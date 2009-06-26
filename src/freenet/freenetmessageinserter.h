#ifndef _freenetmessageinserter_
#define _freenetmessageinserter_

#include "freenetconnection.h"
#include "ifcpconnected.h"
#include "ifcpmessagehandler.h"
#include "iperiodicprocessor.h"
#include "../flipeventhandler.h"
#include "../idatabase.h"
#include "../ilogger.h"

#include <string>
#include <map>

class FreenetMessageInserter:public IFCPConnected,public IFCPMessageHandler,public IPeriodicProcessor,public IDatabase,public ILogger,public FLIPEventHandler
{
public:
	FreenetMessageInserter(FreenetConnection *connection, FCPv2::Connection *fcp);
	~FreenetMessageInserter();

	void FCPConnected();
	void FCPDisconnected();
	const bool HandleFCPMessage(FCPv2::Message &message);
	void Process();

	const bool HandleFLIPEvent(const FLIPEvent &flipevent);

private:
	void StartInsert(const int localidentityid, const std::string &channel, const std::string &message);

	std::string m_messagebase;
	std::map<int,std::string> m_identitykeys;

};

#endif	// _freenetmessageinserter_