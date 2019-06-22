#pragma once
#include "ModuleManager.h"

//DECLARE_LOG_CATEGORY_EXTERN(FliteTTSPlugin, Log, All);
class FLITETTSPLUGIN_API FFliteTTSPlugin : public IFliteTTSPlugin
{		
public:
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void writefile(FString str);

protected:
	static void FreeDependency(void*& Handle);
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void* LibFlite;
	static void* LibUsRms;
	//static void* LibUsSlt;
	static FString PluginDir;
};