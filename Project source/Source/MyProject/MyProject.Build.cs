// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyProject : ModuleRules
{
	public MyProject(ReadOnlyTargetRules Target) : base(Target)
	{	//PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "FliteTTSPlugin" });
	
	 //PrivateDependencyModuleNames.AddRange(new string[] { "FliteTTSPlugin" });
	 //PrivateIncludePathModuleNames.AddRange(new string[] { "FliteTTSPlugin" });
	 //Definitions.Add("_CRT_SECURE_NO_WARNINGS");
	  
	}
}
