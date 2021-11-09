#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int Places=0;
typedef enum bool_t {false_t,true_t} bool_t;
typedef struct
{
    int id;
    bool_t busy;
    char* name;
    char* surname;
} ticket_t;
void sortAlph(char* surname);
void showReservdPlace(ticket_t* ticket,int cntReservd);
bool_t destroy(ticket_t* ptr);
void* init(int sizeStruct);
bool_t showCountFreePlace(ticket_t* ticket,int cntTicket);
void showFreePlace(ticket_t* ticket,int cntTicket);
bool_t reservPlace(ticket_t* ticket,int cntTicket);
bool_t deleteReservPlace(ticket_t* ticket,int cntTicket);
FILE* uploadStruct(ticket_t* ticket,int cntTicket);
void saveStruct(FILE *fp,ticket_t *ticket,int cntTicket,bool_t change);
int main(int argc, char** argv)
{
    bool_t change = false_t;
    ticket_t* mallPTR;
    mallPTR=init(12);
    bool_t check=true_t;
    int choose;
    ticket_t* ptrTick;
    ptrTick=mallPTR;
    FILE *fp;
    fp = uploadStruct(ptrTick,12);

    while(check){
            printf("1. Show count free place.\n2. Show list free place.\n3. Show reservd place(alph sort).\n4. Reservd place.\n5. Delete reservd place.\n6.Quit.\n");
            scanf("%d",&choose);
            while(getchar()!='\n');
        switch(choose){
    case 1:showCountFreePlace(ptrTick,12);
            break;
    case 2:showFreePlace(ptrTick,12);
            break;
    case 3:showReservdPlace(ptrTick,Places);
            break;
    case 4:
        if(reservPlace(ptrTick,12)){
            change = true_t;
            printf("He reservd\n");
        }else{
        printf("Error\n");
        }
            break;
    case 5:deleteReservPlace(ptrTick,12);
            change=true_t;
            break;
    case 6:check=false_t;
            break;
        default:printf("Try again\n");
        break;
        }

    }
    saveStruct(fp,ptrTick,12,change);
    if(destroy(mallPTR)==true_t)
    {
        printf("Struct delete\n");
    }
    else
    {
        printf("ERROR\n");
    }
}
bool_t showCountFreePlace(ticket_t* ticket,int cntTicket)
{
    int free=cntTicket-Places;
    printf("Free %d place\n",free);
    if(free!=0)
    {
        return true_t;
    }
    else
    {
        return false_t;
    }
}
void showFreePlace(ticket_t* ticket,int cntTicket)
{
    int cnt=Places;
    ticket_t* ptr=NULL;
    ptr=ticket;
    ptr+=cnt;
    char *answ;
    answ=(char*)malloc(10*sizeof(char));
     if(ptr->busy==0){
            answ="free";
        }else{
        answ="busy";
        }
        if(cnt==12){
            printf("All reservd\n");
        }
    while(cnt<cntTicket)
    {
        printf("id:%d busy %s name %s surname %s\n",ptr->id,answ,ptr->name,ptr->surname);
        ptr++;
        cnt++;
    }
}
void* init(int sizeStruct)
{
    ticket_t *ptr=(ticket_t*)malloc(sizeStruct*sizeof(ticket_t));
    ptr->name=(char*)malloc(40);
    ptr->surname=(char*)malloc(40);
    ticket_t *ptrtemp;
    ptrtemp=ptr;
    int cnt=0;
    while(cnt<sizeStruct)
    {
        ptrtemp->id=cnt+1;
        ptrtemp->busy=false_t;
        ptrtemp->name=NULL;
        ptrtemp->surname=NULL;
        ptrtemp++;
        cnt++;
    }
    return (ticket_t*)ptr;
}
bool_t destroy(ticket_t* ptr)
{
    free(ptr);
    return true_t;
}
bool_t reservPlace(ticket_t* ticket,int cntTicket)
{
    ticket_t* ptrTemp=NULL;
    ptrTemp=ticket;
    bool_t an;
    an=showCountFreePlace(ticket,cntTicket);
    if(an)
    {
        ptrTemp+=Places;
        ptrTemp->id=Places+1;
        ptrTemp->busy=true_t;
        printf("Input name\n");
        scanf("%s",&ptrTemp->name);
        printf("Input surname\n");
        scanf("%s",&ptrTemp->surname);
        Places++;
        return true_t;
    }

}
void showReservdPlace(ticket_t* ticket,int cntReservd)
{
    if(cntReservd==0){
        printf("All free\n");
    }
    ticket_t* ptrTemp=NULL;
    ptrTemp=ticket;
    int cnt=cntReservd;
    char *answ;
    answ=(char*)malloc(10*sizeof(char));
    while(cnt!=0)
    {
        if(ptrTemp->busy==1){

            answ="busy";
        }else{
            answ="free";
        }

        printf("id %d busy %s name %s surname %s\n",ptrTemp->id,answ,&ptrTemp->name,&ptrTemp->surname);
        ptrTemp++;
        cnt--;
    }

}
bool_t deleteReservPlace(ticket_t* ticket,int cntTicket){
    if(Places==0){
        printf("List clear\n");
        return false_t;
    }
    ticket_t *tmpPtr=NULL;
    tmpPtr=ticket;
    int id;
printf("Input id for delete:\n");
scanf("%d",&id);
while(tmpPtr->id!=id){
        if(cntTicket==0){
            printf("We no found him\n");
            break;
        }
    tmpPtr++;
    cntTicket--;
}
if(tmpPtr->id==id&&tmpPtr->name!=NULL){
    tmpPtr->busy=false_t;
    printf("We delete %s %s\n",&tmpPtr->name,&tmpPtr->surname);
    tmpPtr->name=NULL;
    tmpPtr->surname=NULL;
    Places--;
    return true_t;
}else{
printf("This id free\n");
}
}
FILE* uploadStruct(ticket_t* ticket,int cntTicket){
    ticket_t *ptrTMP=NULL;
    ptrTMP=ticket;
    FILE *fp;
    int cnt=0;
    if((fp=fopen("struct.bin","rb+"))==NULL){
        if((fp=fopen("struct.bin","w+"))==NULL){
            printf("ERR\n");
        }else{
        printf("FILE create\n");
        while(cnt<cntTicket){
            fwrite(ptrTMP,sizeof(ticket_t),1,fp);
            ptrTMP++;
            cnt++;
        }

        ticket_t tmp;
        ticket_t *pt=NULL;
        pt=&tmp;
        rewind(fp);
        printf("FILE:\n");
        while(fread(pt,sizeof(ticket_t),1,fp)!=NULL){

            printf("id %d busy %d name %s surname %s\n",tmp.id,tmp.busy,tmp.name,tmp.surname);
        }
        rewind(fp);
        return fp;
        }
    }else{
        if((fp=fopen("struct.bin","r+"))==NULL){
            printf("ERR\n");
        }else{
        printf("FILE open for rewrite\n");
        ticket_t tmp;
        ticket_t *pt=NULL;
        pt=&tmp;
        printf("FILE:\n");
        while(fread(pt,sizeof(ticket_t),1,fp)!=NULL){

            printf("id %d busy %d name %s surname %s\n",tmp.id,tmp.busy,&tmp.name,&tmp.surname);
        }
        rewind(fp);
        return fp;

        }
    }

}
void saveStruct(FILE *fp,ticket_t *ticket,int cntTicket,bool_t change){
    ticket_t *ptrTMP=NULL;
    ptrTMP=ticket;
    if(change == true_t){
    while(cntTicket!=0){
    fwrite(ptrTMP,sizeof(ticket_t),1,fp);
    cntTicket--;
    ptrTMP++;
    }
    printf("Struct save\n");
    }else{printf("Struct no change\n");}
    fclose(fp);
}
