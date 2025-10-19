#include "ComfyHttpClient.h"
#include "Http.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

UComfyHttpClient::UComfyHttpClient()
{
	ServerURL = TEXT("http://192.168.1.247:8188");
}

void UComfyHttpClient::SendPrompt(const FString& PromptJSON)
{
	FString URL = BuildAPIURL(TEXT("prompt"));
	
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UComfyHttpClient::OnPromptResponseReceived);
	Request->SetURL(URL);
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetContentAsString(PromptJSON);
	Request->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Sending prompt to: %s"), *URL);
}

void UComfyHttpClient::GetQueueStatus()
{
	FString URL = BuildAPIURL(TEXT("queue"));
	
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UComfyHttpClient::OnQueueStatusResponseReceived);
	Request->SetURL(URL);
	Request->SetVerb(TEXT("GET"));
	Request->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Getting queue status from: %s"), *URL);
}

void UComfyHttpClient::GetHistory(const FString& PromptID)
{
	FString URL = BuildAPIURL(TEXT("history"));
	if (!PromptID.IsEmpty())
	{
		URL += FString::Printf(TEXT("/%s"), *PromptID);
	}
	
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UComfyHttpClient::OnHistoryResponseReceived);
	Request->SetURL(URL);
	Request->SetVerb(TEXT("GET"));
	Request->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Getting history from: %s"), *URL);
}

void UComfyHttpClient::InterruptQueue()
{
	FString URL = BuildAPIURL(TEXT("interrupt"));
	
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UComfyHttpClient::OnInterruptResponseReceived);
	Request->SetURL(URL);
	Request->SetVerb(TEXT("POST"));
	Request->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Interrupting queue at: %s"), *URL);
}

void UComfyHttpClient::GetSystemStats()
{
	FString URL = BuildAPIURL(TEXT("system_stats"));
	
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UComfyHttpClient::OnSystemStatsResponseReceived);
	Request->SetURL(URL);
	Request->SetVerb(TEXT("GET"));
	Request->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Getting system stats from: %s"), *URL);
}

void UComfyHttpClient::SetServerURL(const FString& NewServerURL)
{
	ServerURL = NewServerURL;
	UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Server URL updated to: %s"), *ServerURL);
}

void UComfyHttpClient::OnPromptResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		HandleHttpError(TEXT("Send Prompt"), TEXT("Request failed or invalid response"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Prompt sent successfully"));
	}
	else
	{
		HandleHttpError(TEXT("Send Prompt"), FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent));
	}
}

void UComfyHttpClient::OnQueueStatusResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		HandleHttpError(TEXT("Get Queue Status"), TEXT("Request failed or invalid response"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Queue status retrieved"));
	}
	else
	{
		HandleHttpError(TEXT("Get Queue Status"), FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent));
	}
}

void UComfyHttpClient::OnHistoryResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		HandleHttpError(TEXT("Get History"), TEXT("Request failed or invalid response"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] History retrieved"));
	}
	else
	{
		HandleHttpError(TEXT("Get History"), FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent));
	}
}

void UComfyHttpClient::OnInterruptResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		HandleHttpError(TEXT("Interrupt Queue"), TEXT("Request failed or invalid response"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] Queue interrupted successfully"));
	}
	else
	{
		HandleHttpError(TEXT("Interrupt Queue"), FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent));
	}
}

void UComfyHttpClient::OnSystemStatsResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		HandleHttpError(TEXT("Get System Stats"), TEXT("Request failed or invalid response"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Display, TEXT("[ComfyHTTP] System stats retrieved"));
	}
	else
	{
		HandleHttpError(TEXT("Get System Stats"), FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent));
	}
}

FString UComfyHttpClient::BuildAPIURL(const FString& Endpoint)
{
	FString URL = ServerURL;
	if (!URL.EndsWith(TEXT("/")))
	{
		URL += TEXT("/");
	}
	URL += Endpoint;
	return URL;
}

void UComfyHttpClient::HandleHttpError(const FString& Operation, const FString& ErrorMessage)
{
	FString FullErrorMessage = FString::Printf(TEXT("%s failed: %s"), *Operation, *ErrorMessage);
	UE_LOG(LogTemp, Error, TEXT("[ComfyHTTP] %s"), *FullErrorMessage);
	OnError.Broadcast(FullErrorMessage);
}
