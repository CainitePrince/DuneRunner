// Fill out your copyright notice in the Description page of Project Settings.


#include "AfterburnerComponent.h"

// Sets default values for this component's properties
UAfterburnerComponent::UAfterburnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAfterburnerComponent::BeginPlay()
{
	Super::BeginPlay();

	_generator = GetOwner()->FindComponentByClass<UGeneratorComponent>();
}


// Called every frame
void UAfterburnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UAfterburnerComponent::Use()
{
	double deltaTime = FApp::GetDeltaTime();
	double time = FApp::GetCurrentTime();

	float consumption = PowerConsumption * deltaTime;

	if ((consumption) <= _generator->AvailablePower && time >= _nextFireTime)
	{
		_generator->AvailablePower -= consumption;

		//UE_LOG(LogTemp, Log, TEXT("Consumption: %f, Power: %f"), consumption, _generator->AvailablePower);

		return true;
	}
	else
	{
		_nextFireTime = time + 0.2f;
	}

	return false;
}

