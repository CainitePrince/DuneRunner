// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneratorComponent.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AfterburnerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNERUNNER_API UAfterburnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAfterburnerComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpeedRatio;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PowerConsumption;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CooldownTime;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool Use();

	UFUNCTION(BlueprintCallable)
	bool IsFiring();

private:
	UGeneratorComponent* _generator;
	float _nextFireTime;
	bool _isFiring;
};
