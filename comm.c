#include "comm.h"
#include <math.h>
#include <stdio.h>
#include <curl/curl.h>

//This function takes in RMS values of 1 second, each is calculated by 16000/80=200
//samples, but the function wille-calculate 8-pieces of RMS values
//each corresponding to 200 samples or 125ms of sound

void sendToServer(double rms[]){
		double fast[8], sum;
		int i,j;
		CURL *curl;
		CURLcode res;
		char post[1000];
		for(i=0; i<8; i++){
			for(j=0, sum=0; j<10; j++){
				sum += rms[j+i*10]*rms[j+i*10]*200;
			}
			fast[i] = sqrt(sum/2000);
		}
		sprintf(post, "data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", fast[0],fast[1],fast[2],fast[3],fast[4],fast[5],fast[6],fast[7]);
		curl_global_init(CURL_GLOBAL_ALL);
		curl = curl_easy_init();
		if(curl){
			curl_easy_setopt(curl, CURLOPT_URL, URL);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
			res = curl_easy_perform(curl);
			if(res != CURLE_OK){
				fprintf(stderr, "curl_easy_perform() failed: %s\n",	curl_easy_strerror(res));
				curl_easy_cleanup(curl);
		}
		curl_global_cleanup();
		}
}
