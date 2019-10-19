// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"


//////////////////////////////////////////////////////////////////////////
// ABaseCharacter

ABaseCharacter::ABaseCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &ABaseCharacter::LeftClickPressed);
	PlayerInputComponent->BindAction("LeftClick", IE_Released, this, &ABaseCharacter::LeftClickReleased);
	PlayerInputComponent->BindAction("RightClick", IE_Pressed, this, &ABaseCharacter::RightClickPressed);
	PlayerInputComponent->BindAction("RightClick", IE_Released, this, &ABaseCharacter::RightClickReleased);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABaseCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABaseCharacter::LookUpAtRate);

	// VR headset functionality
	//PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ABaseCharacter::OnResetVR);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	//AnimBP = GetMesh()->GetAnimInstance();
}
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Controller)
	{
		Direction = (FRotator(FVector(InputZ, InputX, 0).Rotation())-(FollowCamera->GetComponentRotation() - GetCapsuleComponent()->GetComponentRotation())).Yaw;
		//AddMovementInput(FRotator(0.0, GetControlRotation().Yaw, 0.0).Vector().ForwardVector, InputZ);
		AddMovementInput(FRotationMatrix(FRotator(0.0, GetControlRotation().Yaw, 0.0)).GetUnitAxis(EAxis::X), InputZ);
	}
}

void ABaseCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::MoveForward(float Value)
{
	if (Controller)
	{
		if (Value != 0.0f)
		{
			InputZ = Value;
		}
		else { InputZ = 0.0; }
	}
}
void ABaseCharacter::MoveRight(float Value)
{
	if (Controller)
	{
		if (Value != 0.0f)
		{
			InputX = Value;
			//AddMovementInput(FRotator(0.0, GetControlRotation().Yaw, 0.0).Vector().RightVector, InputX);
			AddMovementInput(FRotationMatrix(FRotator(0.0, GetControlRotation().Yaw, 0.0)).GetUnitAxis(EAxis::Y), InputX);
		}
		else { InputX = 0.0; }
	}
}

void ABaseCharacter::LeftClickPressed()
{

}
void ABaseCharacter::LeftClickReleased()
{

}

void ABaseCharacter::RightClickPressed()
{

}
void ABaseCharacter::RightClickReleased()
{

}
