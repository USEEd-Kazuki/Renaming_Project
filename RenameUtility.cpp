// Fill out your copyright notice in the Description page of Project Settings.

#include "RenameUtility.h"
#include "EditorUtilityLibrary.h"

void URenameUtility::RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase)
{
	// 存在チェック
	if (SearchPattern.IsEmpty() || SearchPattern.Equals(ReplacePattern, SearchCase)) 
	{
		return;
	}

	// 選択中のアセットを取得
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

	uint32 Counter = 0;

	// 名前変換が必要か確認
	for (UObject* SelectedObject : SelectedObjects) 
	{
		if (ensure(SelectedObject)) 
		{
			FString AssetName = SelectedObject->GetName();
			if (AssetName.Contains(SearchPattern, SearchCase))
			{
				FString NewName = AssetName.Replace(*SearchPattern, *ReplacePattern, SearchCase);
				UEditorUtilityLibrary::RenameAsset(SelectedObject, NewName);
				++Counter;
			}
		}
	}

	GiveFeedback(TEXT("Renamed"), Counter);
}

void URenameUtility::PrintToScreen(FString Message, FColor Color)
{
	if (ensure(GEngine)) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}

void URenameUtility::GiveFeedback(FString Method, uint32 Counter)
{
	FString Message = FString("No matching files found");
	FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
	if (Counter > 0)
	{
		Message = Method.AppendChar(' ');
		Message.AppendInt(Counter);
		Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));
	}
	PrintToScreen(Message, Color);
}
