#include <stdio.h>
#include <sys/ipc.h>	
#include <sys/shm.h>

int main(){

	/**Vars**/
	int shm_id;
	int pid;
	int* p_mem, *c_mem; 
	int status;
	int i;

	/**Shared Mmory**/
	shm_id = shmget(IPC_PRIVATE, 10*sizeof(int), IPC_CREAT|0777);

	if(shm_id < 0){
		printf("\nShared memory creation FAILED!!!\n");
		exit(1);
	} else {
		printf("\nShared memory CREATED.\n");
	}

	pid = fork();

	
	/**Processes using shared Memory**/
	if(pid == 0){ /**i.e. Child**/
		c_mem = (int*) shmat(shm_id, 0, 0);

		if((int) c_mem == -1){
			printf("\nAttaching memory to child FAILED!!!");
			exit(1);
		} else {
			printf("\nAttaching memory to child DONE.\n");
		}

		for( i=0; i< 10; i++){
			sleep(1);
			printf("\t\t\t Child reads: %d,%d\n",c_mem[0],c_mem[1]);
		}

		/* each process should "detach" itself from the
		shared memory after it is used */

		shmdt(c_mem);

	} else {	/**i.e. Parent**/
		p_mem = (int*) shmat(shm_id, 0, 0);
		
		if((int) p_mem == -1){
			printf("\nAttaching memory to parent FAILED!!!");
			exit(1);
		} else {
			printf("\nAttaching memory to parent DONE.\n");
		}

		p_mem[0] = 0; 
		p_mem[1] = 1;
		
		for( i=0; i< 15; i++){
			sleep(1);
			p_mem[0] = p_mem[0] + p_mem[1];
			p_mem[1] = p_mem[0] + p_mem[1];
			printf("Parent writes: %d,%d\n",p_mem[0],p_mem[1]);
		}

		wait(&status);
		shmdt(p_mem);

		shmctl(shm_id, IPC_RMID, 0);	

	}

}