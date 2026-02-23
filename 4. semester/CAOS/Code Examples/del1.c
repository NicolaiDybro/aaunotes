//
// Created by Nicolai Dybro Jensen on 10/06/2025.
//

#define MAXWORDLEN 16 //15+1
#define INPUTLENGTH 57
//one bin in the histogram per wordlength in input
#define BINS MAXWORDLEN
#define WORKERS 3
#define MAXWORKITEMS 10

char* input[INPUTLENGTH]={"Man","skal", "holde","tungen","lige","i","munden","når",
"man", "skriver","programmer", "med","parallelitet", "eller","med", "en", "bedre",
"term","concurrency" ,"Der","kan","være","mange","fælder","såsom","race","conditions",
"deadlocks","og", "udsultning","Det","er","derfor","vigtigt","at","man","sætter","sig",
"grundigt", "ind","i","hvordan","synkronisering","og","gensidig","udelukkelse",
"fungerer","og", "bedst", "anvendes", "så","ens","programmer","bliver","effektive","og",
"korrekte"};

int H_counts[BINS];
int lengths[INPUTLENGTH];
WorkPool todoItems;
WorkPool doneItems;
//FURTHER GLOBALS

void zeroArray(int*a,int len){
       for(int i=0;i<len;i++) a[i]=0; //fill a with 0-values
}

void mapper(WorkItem * workItem){
        for(int i=workItem->start;i<=workItem->end;i++)
                lengths[i]=strlen(input[i]);
}

void reduce(WorkItem * workItem, int* lengths, int*counts){
        for(int i=workItem->start;i<=workItem->end;i++) {
                int bin=lengths[i];
                counts[bin]++;
        }
}
void mergeCounts(int *H_counts, int* H_local, int len){     //merge local counts to global
        for(int i=0;i<len;i++)
                H_counts[i]+=H_local[i];
}

void * worker(void*args){
        WorkItem myWork;
        int moreWork=1;
        int H_local[BINS];

        while(moreWork) {
                getWork(&todoItems,&myWork);
                if(!isPoison(&myWork)) {
                    mapper(&myWork);
                    zeroArray(H_local,BINS);
                    reduce(&myWork,lengths,H_local);
                    mergeCounts(H_counts,H_local,BINS);
                    putWork(&doneItems,&myWork);//tell master that this portion is done
                }
                else //poison=>die
                    moreWork=0;
        }
        return NULL;
}


typedef struct {int start; int end; } WorkItem;
typedef struct {
        WorkItem workStorage[MAXWORKITEMS];
        int workCount;
} WorkPool;

void push(WorkPool * wp, WorkItem *workItem){
        wp->workStorage[wp->workCount]=*workItem;
        wp->workCount++;
}
void pop(WorkPool * wp, WorkItem *workItem){
        wp->workCount--;
        *workItem=wp->workStorage[wp->workCount];
}

void initWorkPool(WorkPool * wp){
        wp->workCount=0;
}

void getWork(WorkPool * wp, WorkItem * workItem){
        pop(wp,workItem);
}

void putWork(WorkPool * wp, WorkItem * workItem){
        push(wp,workItem);
}

int isPoison(WorkItem * workItem){return (workItem->start<0);}
void makePoison(WorkItem * workItem){workItem->start=-1;}
