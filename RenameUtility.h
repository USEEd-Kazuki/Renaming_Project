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
	* �I�𒆂̃A�Z�b�g�̖��O�ϊ�
	* @param SearchPattern - �����p�^�[�� 
	* @param ReplacePattern - �u���p�^�[��
	* @param SearchCase - ��������P�[�X
	**/
	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase);

private:
	/**
	* �X�N���[���ւ̃��b�Z�[�W�\��
	* @param Message - ���b�Z�[�W
	* @param Color - ���b�Z�[�W�Ɏg�p����F
	**/
	void PrintToScreen(FString Message, FColor Color);

	/** 
	* ���[�U�[�ւ̃t�B�[�h�o�b�N
	* @param Method - �g�p���ꂽ���\�b�h
	* @param Counter - �ϊ����ꂽ�A�Z�b�g��
	**/
	void GiveFeedback(FString Method, uint32 Counter);
};
