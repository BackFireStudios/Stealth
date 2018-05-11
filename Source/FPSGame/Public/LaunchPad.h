// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPad.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UArrowComponent;

UCLASS()
class FPSGAME_API ALaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaunchPad();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComp;

	UFUNCTION()
	void OverlapLaunchPad(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	/* Total impulse added to the character on overlap
	Marked 'EditInstanceOnly' to allow in-level editing of this property per instance. */
	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
	float LaunchStrength;

	/* Angle added on top of actor rotation to launch the character.
	Marked 'EditInstanceOnly' to allow in-level editing of this property per instance. */
	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
	float LaunchPitchAngle;

	/* Effect to play when activating launch pad */
	UPROPERTY(EditDefaultsOnly, Category = "LaunchPad")
	UParticleSystem* ActivateLaunchPadEffect;

	
	
};
