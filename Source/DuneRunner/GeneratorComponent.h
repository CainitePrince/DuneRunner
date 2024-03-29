// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GeneratorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNERUNNER_API UGeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGeneratorComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Capacity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AvailablePower;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ProductionPerSecond;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UsePower(float power);
};
