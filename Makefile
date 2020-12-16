all:main1.c
	gcc -pthread -o main1 main1.c

clean:
		$(RM) main1