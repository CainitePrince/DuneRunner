// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratorComponent.h"

// Sets default values for this component's properties
UGeneratorComponent::UGeneratorComponent() : 
	Capacity(100.0f),
	AvailablePower(0.0f),
	ProductionPerSecond(10.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGeneratorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGeneratorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AvailablePower = FMath::Clamp(AvailablePower + ProductionPerSecond * DeltaTime, 0, Capacity);
}

void UGeneratorComponent::UsePower(float power)
{
	AvailablePower -= power;
}


