/*
 * msgq.cpp
 *
 *  Created on: 21-May-2020
 *      Author: admin
 */




/* Filename: msgq_send.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 0x2222

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int msgsend(char * msgstr) {
   struct my_msgbuf buf;
   int msqid;
   int len;
/*    key_t key;
   //system("touch msgq.txt");

  if ((key = ftok("msgq.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }*/

   if ((msqid = msgget(KEY, PERMS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
   //printf("message queue: ready to send messages.\n");
   //printf("Enter lines of text, ^D to quit:\n");
   buf.mtype = 1; /* we don't really care in this case */

   /*while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
      len = strlen(buf.mtext);
       remove newline at end, if it exists
      if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
      if (msgsnd(msqid, &buf, len+1, 0) == -1)  +1 for '\0'
      perror("msgsnd");
   }*/
   strcpy(buf.mtext, msgstr);
   len = strlen(buf.mtext);
   if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
	   perror("msgsnd");

   /*if (msgctl(msqid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
   }
   printf("message queue: done sending messages.\n");
   */
   return 0;
}


/*Following is the code from message receiving process (retrieving message from queue) – File: msgq_recv.c

 Filename: msgq_recv.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf buf1;
char * msgreceive(void) {

   int msqid;
   int toend;
 /*  key_t key;

 if ((key = ftok("msgq.txt", 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
*/
   if ((msqid = msgget(KEY, PERMS)) == -1) { /* connect to the queue */
      perror("msgget");
      exit(1);
   }
 //  printf("message queue: ready to receive messages.\n");

   //for(;;) { /* normally receiving never ends but just to make conclusion
             /* this program ends wuth string of end */
      if (msgrcv(msqid, &buf1, sizeof(buf1.mtext), 0, 0) == -1) {
         perror("msgrcv");
         exit(1);
      }
     // printf("recvd: \"%s\"\n", buf.mtext);
     // toend = strcmp(buf.mtext,"end");
     // if (toend == 0)
     // break;
  // }
  // printf("message queue: done receiving messages.\n");
  // system("rm msgq.txt");
   return buf1.mtext;
}
