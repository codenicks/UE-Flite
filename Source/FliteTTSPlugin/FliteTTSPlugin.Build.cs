// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
using System.IO;
namespace UnrealBuildTool.Rules
{
	public class FliteTTSPlugin : ModuleRules
	{
		
		private string ModulePath
        {
            get { return ModuleDirectory; }
        }

        private string BaseDirectory
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "..", "..")); }
        }
		
		public FliteTTSPlugin(ReadOnlyTargetRules Target) : base(Target)
		{
			bEnableUndefinedIdentifierWarnings = false;
			PublicIncludePaths.AddRange(
				new string[] {
					"FliteTTSPlugin/Private",
					"FliteTTSPlugin/Public",
                    "FliteTTSPlugin/ThirdParty/flite/include",// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{	"Core", 
				    "CoreUObject", 
				    "Engine", 
				    "InputCore",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
				
            
			if (Target.Platform == UnrealTargetPlatform.Win32)
            {
                string FliteDirectory = Path.Combine(BaseDirectory, "ThirdParty", "flite", "lib");
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "fliteDll.dll")));
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_rms.dll")));
               // RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_slt.dll")));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"flite.lib"));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"libflite-cmulex.lib"));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"libflite-usenglish.lib"));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"cmu_us_rms.lib"));
            }
            else if (Target.Platform == UnrealTargetPlatform.Win64)
            {               
                string FliteDirectory = Path.Combine(BaseDirectory, "ThirdParty", "flite", "lib");
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "fliteDll.dll")));
				RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_rms.dll")));
               // RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(FliteDirectory, "cmu_us_slt.dll")));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"flite.lib"));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"libflite-cmulex.lib"));
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"libflite-usenglish.lib"));;
				PublicAdditionalLibraries.Add(Path.Combine(FliteDirectory,"cmu_us_rms.lib"));
		   }
			else
			{
				// Linux, Mac, WinRT: not supported
			}
		}
	}
}