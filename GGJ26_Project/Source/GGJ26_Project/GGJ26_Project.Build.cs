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
			"GGJ26_Project/Variant_Platforming",
			"GGJ26_Project/Variant_Platforming/Animation",
			"GGJ26_Project/Variant_Combat",
			"GGJ26_Project/Variant_Combat/AI",
			"GGJ26_Project/Variant_Combat/Animation",
			"GGJ26_Project/Variant_Combat/Gameplay",
			"GGJ26_Project/Variant_Combat/Interfaces",
			"GGJ26_Project/Variant_Combat/UI",
			"GGJ26_Project/Variant_SideScrolling",
			"GGJ26_Project/Variant_SideScrolling/AI",
			"GGJ26_Project/Variant_SideScrolling/Gameplay",
			"GGJ26_Project/Variant_SideScrolling/Interfaces",
			"GGJ26_Project/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
