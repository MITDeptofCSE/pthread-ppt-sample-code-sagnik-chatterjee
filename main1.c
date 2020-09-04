#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum; // this data is shared by the thread(s)
void *runner(void *param); // the thread 

int main(int argc, char *argv[])
{
pthread_t tid; // the thread identifier *I
pthread_attr_t attr; // set of thread attributes

if (argc != 2) {
    fprintf(stderr,"usage: a.out <integer value>\n");
    return -1;
}
if (atoi(argv[1]) < 0) {
    fprintf(stderr,"%d must be>= 0\n",atoi(argv[1]));
    return -1;
}
// get the default attributes *I
pthread_attr_init(&attr);
// create the thread *I
pthread_create(&tid,&attr,runner,argv[1]);
// wait for the thread to exit *I
pthread_join(tid,NULL);
printf("sum = %d\n",sum);

return 0;
}
// The thread will begin control in this function
void *runner(void *param){
int upper= atoi(param);
sum = 0;
for (int i = 1; i <= upper; i++)
sum += i;
pthread_exit ( 0) ;
}