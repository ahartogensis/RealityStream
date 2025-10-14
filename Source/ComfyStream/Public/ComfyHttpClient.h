#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "ComfyStreamTypes.h"
#include "ComfyHttpClient.generated.h"

/**
 * HTTP client for ComfyUI server communication
 * Used for sending prompts, checking status, and other HTTP operations
 */
UCLASS()
class COMFYSTREAM_API UComfyHttpClient : public UObject
{
	GENERATED_BODY()

public:
	UComfyHttpClient();

	// Events
	UPROPERTY(BlueprintAssignable)
	FOnError OnError;

	// Configuration
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ComfyHTTP")
	FString ServerURL = TEXT("http://192.168.1.247:8001");

	// HTTP functions
	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	void SendPrompt(const FString& PromptJSON);

	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	void GetQueueStatus();

	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	void GetHistory(const FString& PromptID = TEXT(""));

	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	void InterruptQueue();

	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	void GetSystemStats();

	// Utility functions
	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	void SetServerURL(const FString& NewServerURL);

	UFUNCTION(BlueprintCallable, Category = "ComfyHTTP")
	FString GetServerURL() const { return ServerURL; }

private:
	// HTTP request handlers
	void OnPromptResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnQueueStatusResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnHistoryResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnInterruptResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnSystemStatsResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	// Internal functions
	FString BuildAPIURL(const FString& Endpoint);
	void HandleHttpError(const FString& Operation, const FString& ErrorMessage);
};
