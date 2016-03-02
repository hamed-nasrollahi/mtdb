// IMessageBoxWrapper.h: interface to hide
// the managed implementation from the dll client

#pragma once

#include <string>

#ifdef MANAGEDWRAPPER_EXPORTS
#define DLLAPI  __declspec(dllexport)
#else
#define DLLAPI  __declspec(dllimport)
//#pragma comment (lib, "MqlDbAdapter.lib") // if importing, link also
#endif

class DLLAPI IMqlAdaptor
{
public:
	virtual void  Init(std::string host, std::string database, std::string user, std::string password) = 0;

	// Class factory
	//static IMqlAdaptor   *CreateInstance();
	//static void          Destroy(IMqlAdaptor *instance);
};