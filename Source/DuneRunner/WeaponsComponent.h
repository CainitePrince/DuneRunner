// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeneratorComponent.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNERUNNER_API UWeaponsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponsComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RateOfFire;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float PowerConsumption;

	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	float Damage;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool Fire();

private:
	UGeneratorComponent* _generator;
	double _nextFireTime;
};
