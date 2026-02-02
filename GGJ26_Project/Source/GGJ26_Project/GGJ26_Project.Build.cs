// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GGJ26_Project : ModuleRules
{
	public GGJ26_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
            "Core",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
            "InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GGJ26_Project",
            "GGJ26_Project/Abilities",
			"GGJ26_Project/Characters",
            "GGJ26_Project/Collectables",
            "GGJ26_Project/Controllers",
            "GGJ26_Project/GameMode"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
