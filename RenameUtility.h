// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "RenameUtility.generated.h"

/**
 * 
 */
UCLASS()
class RENAMING_PROJECT_API URenameUtility : public UAssetActionUtility
{
	GENERATED_BODY()

public:

	/**
	* 選択中のアセットの名前変換
	* @param SearchPattern - 検索パターン 
	* @param ReplacePattern - 置換パターン
	* @param SearchCase - 無視するケース
	**/
	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase);

private:
	/**
	* スクリーンへのメッセージ表示
	* @param Message - メッセージ
	* @param Color - メッセージに使用する色
	**/
	void PrintToScreen(FString Message, FColor Color);

	/** 
	* ユーザーへのフィードバック
	* @param Method - 使用されたメソッド
	* @param Counter - 変換されたアセット数
	**/
	void GiveFeedback(FString Method, uint32 Counter);
};
