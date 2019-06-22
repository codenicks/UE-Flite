// Fill out your copyright notice in the Description page of Project Settings.
#include "MyProject.h"
#include "lex_test.h"

// #include "../../Plugins/FliteTTSPlugin/ThirdParty/flite/include/flite.h"
// #include "../../Plugins/FliteTTSPlugin/ThirdParty/flite/include/cst_args.h"
// #include "../../Plugins/FliteTTSPlugin/ThirdParty/flite/lang/usenglish/usenglish.h"
// #include "../../Plugins/FliteTTSPlugin/ThirdParty/flite/lang/cmulex/cmu_lex.h"



Alex_test::Alex_test()
{

}

Alex_test::~Alex_test()
{
}

void Alex_test::citeste(FString str)
{
	
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	
	
	
	flite->writefile(str);
}
