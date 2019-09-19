#include <stdio.h>
#include <pthread.h>

void *print_message(void *t_id);

int main() 
{
	int n;

  	printf("Enter the number of threads: ");
  	scanf("%d", &n);

  	pthread_t A[n];
  	int flag;

  	for (int i = 0; i < n; i++)
  	{
   		printf("I am Thread %d.\n", i + 1);
		flag = pthread_create(&A[i], NULL, print_message, (void*)i);
  	}
	
  	return 0;
}

void *print_message(void *t_id)
{
  	int id = ((int) t_id) + 1;
  	printf("Message from Thread %d (ID = %d).\n", id, (int)pthread_self());
  	pthread_exit(NULL);
}

/*

If we enter 50 (number of threads), output will be:

I am Thread 1.
I am Thread 2.
I am Thread 3.
I am Thread 4.
I am Thread 5.
I am Thread 6.
I am Thread 7.
I am Thread 8.
I am Thread 9.
I am Thread 10.
I am Thread 11.
I am Thread 12.
I am Thread 13.
I am Thread 14.
I am Thread 15.
I am Thread 16.
I am Thread 17.
I am Thread 18.
I am Thread 19.
I am Thread 20.
I am Thread 21.
I am Thread 22.
I am Thread 23.
I am Thread 24.
I am Thread 25.
I am Thread 26.
I am Thread 27.
I am Thread 28.
I am Thread 29.
I am Thread 30.
I am Thread 31.
I am Thread 32.
I am Thread 33.
I am Thread 34.
Message from Thread 5 (ID = -1022458112).
Message from Thread 6 (ID = -1030850816).
Message from Thread 4 (ID = -1014065408).
Message from Thread 7 (ID = -1039243520).
Message from Thread 3 (ID = -1005672704).
Message from Thread 2 (ID = -997280000).
Message from Thread 9 (ID = -1056028928).
Message from Thread 8 (ID = -1047636224).
Message from Thread 10 (ID = -1064421632).
Message from Thread 12 (ID = -1081207040).
Message from Thread 13 (ID = -1089599744).
Message from Thread 14 (ID = -1097992448).
Message from Thread 11 (ID = -1072814336).
Message from Thread 15 (ID = -1106385152).
Message from Thread 1 (ID = -988887296).
Message from Thread 16 (ID = -1114777856).
Message from Thread 17 (ID = -1123170560).
Message from Thread 18 (ID = -1131563264).
Message from Thread 19 (ID = -1139955968).
Message from Thread 20 (ID = -1148348672).
Message from Thread 21 (ID = -1156741376).
Message from Thread 22 (ID = -1165134080).
Message from Thread 23 (ID = -1173526784).
Message from Thread 24 (ID = -1181919488).
Message from Thread 25 (ID = -1190312192).
Message from Thread 26 (ID = -1198704896).
Message from Thread 27 (ID = -1207097600).
Message from Thread 28 (ID = -1215490304).
Message from Thread 29 (ID = -1223883008).
Message from Thread 30 (ID = -1232275712).
Message from Thread 31 (ID = -1240668416).
Message from Thread 32 (ID = -1249061120).
Message from Thread 33 (ID = -1257453824).
I am Thread 35.
I am Thread 36.
I am Thread 37.
I am Thread 38.
I am Thread 39.
I am Thread 40.
I am Thread 41.
I am Thread 42.
I am Thread 43.
I am Thread 44.
I am Thread 45.
I am Thread 46.
I am Thread 47.
I am Thread 48.
I am Thread 49.
I am Thread 50.

*/