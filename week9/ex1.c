#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

typedef struct Frame{
  bool referenced;
  unsigned char lifetime;
  int page_number;

} Frame;

int main(){
  int framesize=3;
  int Hit = 0;
  int Miss = 0;
  int num=0;
  Frame frames[framesize];
  FILE *fp = fopen("data.txt", "r");
 

  for (int i = 0 ; i < framesize; i++) {
    frames[i].page_number = -1;
    frames[i].referenced = false;
    frames[i].lifetime = 0;
  }

  while (fscanf(fp, "%d", &num) == 1) {
    bool founded = false;
    for (int i = 0; i < framesize; i++) {
      if (num == frames[i].page_number) {
        frames[i].referenced = true;
        founded = true;
        Hit++;
      }
    }

    if(!founded){
        Miss++;

        unsigned char minSpan = frames[0].lifetime;
        int minIndex = 0;
        for(int j = 1; j < framesize; j++){
          if(frames[j].lifetime < minSpan){
            minSpan = frames[j].lifetime;
            minIndex = j;
          }
        }

        frames[minIndex].page_number = num;
        frames[minIndex].referenced = true;
    }
    for(int k = 0; k < framesize; k++){
        frames[k].lifetime >>= 1;
        if (frames[k].referenced) {
          frames[k].lifetime = frames[k].lifetime | (1 << (sizeof(frames[k].lifetime)*8-1));
        }
    }
  }

  fclose(fp);
  printf("\nHit = %d | Miss = %d\nHit/Miss Rate = %f\n",Hit, Miss, (float) Hit/Miss);

	return 0;
}
