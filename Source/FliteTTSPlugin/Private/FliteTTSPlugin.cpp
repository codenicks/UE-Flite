// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//#include "Runtime/Projects/Public/Interfaces/IPluginManager.h"
//#include "IPluginManager.h"
#pragma once
#include "FliteTTSPluginPrivatePCH.h"
#include "../Public/FliteTTSPlugin.h"
#include "../../../ThirdParty/flite/include/flite.h"
#include "../../../ThirdParty/flite/include/cst_args.h"
#include "../../../ThirdParty/flite/lang/usenglish/usenglish.h"
#include "../../../ThirdParty/flite/lang/cmulex/cmu_lex.h"
#include <stdio.h>
#include <string>
 
 
extern "C" {
	cst_voice *register_cmu_us_rms(const char *voxdir);
	void unregister_cmu_us_rms(cst_voice *v);
	void usenglish_init(cst_voice *v);
	cst_lexicon *cmulex_init(void);
	
}

#pragma warning(disable:4005)  



IMPLEMENT_MODULE( FFliteTTSPlugin, FliteTTSPlugin )

//FLITETTS_DEFINE(flite_init);

void* FFliteTTSPlugin::LibFlite = nullptr;
void* FFliteTTSPlugin::LibUsRms = nullptr;
//void* FFliteTTSPlugin::LibUsSlt = nullptr;

void FFliteTTSPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	const FString BaseDir = ".";// IPluginManager::Get().FindPlugin("FliteTTSPlugin")->GetBaseDir();
	const FString FliteDir = FPaths::Combine(*BaseDir, TEXT("ThirdParty"), TEXT("flite"));

	


#if PLATFORM_64BITS
	const FString LibDir = FPaths::Combine(*FliteDir, TEXT("Win64"));

	if (!LoadDependency(LibDir, TEXT("fliteDll"), LibFlite) ||
		!LoadDependency(LibDir, TEXT("cmu_us_rms"), LibUsRms)) 
	{
		ShutdownModule();
		return;// false;
	}
#else
	const FString LibDir = FPaths::Combine(*FliteDir, TEXT("Win32"));

	if (!LoadDependency(LibDir, TEXT("fliteDll"), LibFlite) ||
		!LoadDependency(LibDir, TEXT("cmu_us_rms"), LibUsRms)) 
	{
		ShutdownModule();
		return;// false;
}
#endif
	
	//flite_init();
    //cst_voice *v1 = register_cmu_us_rms(NULL);
   // flite_text_to_speech("FLITE is a great Talk to Speech library", v1, "play");
	
	/* cst_voice *v;
	flite_init();
	v = new_voice();
	cst_lexicon *lex;
	lex = cmu_lex_init();
	feat_set(v->features, "lexicon", lexicon_val(lex)); 

	cst_val *p;
	p = lex_lookup2(lex, "Hi, how are you ? 2", "n", NULL);
	val_print2(p);
	*/
	
	//char *string = "Hi, how are you ? 2";
	//char *str = new char[strlen(string)*5];  //NULL;
	
	//str = (char*)malloc(strlen(string) + 1);

	//val_prints2(p,str);

	
	//FString s20 = FString(UTF8_TO_TCHAR(str));
	UE_LOG(LogTemp, Warning, TEXT("Hi, how are you ?"));
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *s20);
}


void FFliteTTSPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	//FreeDependency(LibUsSlt);
	FreeDependency(LibUsRms);
	FreeDependency(LibFlite);

}

void FFliteTTSPlugin::FreeDependency(void*& Handle)
{
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
}


bool FFliteTTSPlugin::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		GLog->Logf(ELogVerbosity::Warning, TEXT("FliteTTSPlugin: Failed to load required library %s. Plug-in will not be functional."), *Lib);
		return false;
	}

	return true;
}





void FFliteTTSPlugin::writefile(FString str){
	/*
	cst_voice *v;
	flite_init();
	v = new_voice();
	cst_lexicon *lex;
	lex = cmu_lex_init();
	feat_set(v->features, "lexicon", lexicon_val(lex)); 
	
	//char* say="Fine, thanks";
	
	char* say = TCHAR_TO_UTF8(*str);
	cst_val *p;
	p = lex_lookup2(lex, say, "n", NULL);
	cst_fprintf20("");
	val_print2(p);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	*/
	
	




	 cst_voice *v;
    cst_wave *w;
    cst_utterance *u;
    const char *voice_pathname;
    const char *text;
    const char *outfile;

   
   
    voice_pathname = "E:\\utaloids\\flite\\cmu_us_rms.flitevox"; //argv[1]; /* pathname to .flitevox file */
    text = TCHAR_TO_UTF8(*str); //argv[2];           /* text to be synthesized */
    outfile = "play"; //argv[3];        /* output file (or "play" or "none") */
 
    /* Initialize Flite, and set up language and lexicon */
    flite_init();
    flite_add_lang("eng",usenglish_init,cmulex_init);
    flite_add_lang("usenglish",usenglish_init,cmulex_init);

    /* Load and select voice */
    v = flite_voice_select(voice_pathname);
    if (v == NULL)
    {
	UE_LOG(LogTemp, Warning, TEXT("failed to load voice"));
        
    }

    u = flite_synth_text(text,v);
    w = utt_wave(u);

    /* Play the resulting wave, save it to a filename, or do none of these */
    if (cst_streq(outfile,"play"))
        play_wave(w);
    else if (!cst_streq(outfile,"none")) 
       cst_wave_save_riff(w,outfile);
    delete_utterance(u); /* will delete w too */

}
