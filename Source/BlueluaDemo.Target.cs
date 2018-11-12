// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BlueluaDemoTarget : TargetRules
{
	public BlueluaDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		bUseLoggingInShipping = true;

		ExtraModuleNames.AddRange( new string[] { "BlueluaDemo" } );
	}
}
