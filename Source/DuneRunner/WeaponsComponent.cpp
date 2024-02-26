// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponsComponent.h"

// Sets default values for this component's properties
UWeaponsComponent::UWeaponsComponent() :
	RateOfFire(0.0f),
	PowerConsumption(0.0f),
	_generator(nullptr),
	_nextFireTime(0.0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UWeaponsComponent::BeginPlay()
{
	Super::BeginPlay();

	_generator = GetOwner()->FindComponentByClass<UGeneratorComponent>();
}


// Called every frame
void UWeaponsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UWeaponsComponent::Fire()
{
	double time = FApp::GetCurrentTime();

	if (time >= _nextFireTime && PowerConsumption <= _generator->AvailablePower)
	{
		_generator->AvailablePower -= PowerConsumption;
		_nextFireTime = time + (1.0 / RateOfFire);

		UE_LOG(LogTemp, Log, TEXT("Time: %f, NextFireTime: %f"), time, _nextFireTime);

		return true;
	}

	return false;
}

