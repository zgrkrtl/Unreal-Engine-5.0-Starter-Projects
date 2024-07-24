// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATurret : public ABasePawn
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void
	BeginPlay() override;

private:
	class ATank *Tank;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 1000.f;

	FTimerHandle FireTimerHandle;
	float fireRate = 2.f;
	void checkFireCondition();

	bool InFireRange();
};