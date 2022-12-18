#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct liste
{
    char*x;
    struct liste*next;
};

struct kelimelist
{
    char*z;
    int adet;
    struct kelimelist*sonraki;
};
typedef struct liste node;
typedef struct kelimelist dugum;

void ekle(char *deger1)
{
    node*curr=(node*)malloc(sizeof(node));
    curr->x = deger1;
    node *tmp = (node*)malloc(sizeof(node));
    tmp->next = NULL;
    curr->next = tmp;
    printf("1 listeye Eklenen Kelime : %s\n",curr->x);
    curr = curr->next;
    node*curr2=(node*)malloc(sizeof(node));
    curr2->x = deger1;
    node *tmp2 = (node*)malloc(sizeof(node));
    tmp2->next = NULL;
    curr2->next = tmp2;
    printf("2 listeye Eklenen Kelime : %s\n",curr2->x);
    curr2 = curr2->next;
    //aramayap(curr,curr2);
}


void ayir(char*satir)
{

    char *kelime = NULL;
    kelime = strtok (satir," ");
    while (kelime != NULL)
    {
        ekle(kelime);
        kelime = strtok (NULL, " ");
    }

}
void basaekle(dugum*a,int sayi,char*kelime)
{
    dugum*temp=(dugum*)malloc(sizeof(dugum));
    temp->adet=sayi;
    temp->z=kelime;
    temp->sonraki=a;
    a=temp;
    printf("%s:%d\n",temp->z,temp->adet);
    //return temp;

}
void sonaekle(dugum*a,int sayi,char*kelime)
{
    dugum*temp=(dugum*)malloc(sizeof(dugum));
    temp->adet=sayi;
    temp->z=kelime;
    temp->sonraki=NULL;
    dugum *temp2=a;
    while(temp2->sonraki!=NULL)
    {
        temp2=temp2->sonraki;
    }
    temp2->sonraki=temp;
    //return temp;
    printf("%s:%d\n",temp->z,temp->adet);
}
void arayaekle(dugum*onceki,int sayi,char*kelime)
{
    dugum* temp=(dugum*)malloc(sizeof(dugum));
    temp->adet=sayi;
    temp->z=kelime;
    temp->sonraki=onceki->sonraki;
    onceki->sonraki=temp;
    //return temp;
    printf("%s:%d\n",temp->z,temp->adet);
}
void aramayap(node*root, node*iter)
{
    int say=0;
    char kelime[50];

    while(root!=NULL)
    {
        if(root->x==iter->x)
        {
            say++;
        }
        else
        {
            iter->next;
        }

    }
    dugum* r=(dugum*)malloc(sizeof(dugum*));
    if(r==NULL)//kelimelist bossa
    {
        r->sonraki=NULL;
        r->z=root->x;
        r->adet=say;
    }
    else if(r->sonraki==NULL)//bir dugum vardir
    {
        if(r->adet>say)
        {
            root->x=kelime;
            sonaekle(&root,say,kelime);
        }
        else if(r->adet<say)
        {
            root->x=kelime;
            basaekle(&root,say,kelime);
        }
        else
        {
            root->x=kelime;
            sonaekle(&root,say,kelime);
        }
    }

    else if(r->sonraki->sonraki!=NULL)
    {
        dugum *val=r;
        while(val->sonraki!=NULL && val->sonraki->adet>say)
        {
            val->z=kelime;
            arayaekle(val,say,kelime);
            val=val->sonraki;
        }
    }


}

void dosyaOkuListeOlustur()
{
    FILE *fp = fopen("metin.txt","r");
    char satir[1000];
    while (fgets( satir, sizeof(satir), fp ))
    {
        ayir(satir);
    }

}
int main()
{
    dosyaOkuListeOlustur();
    node* curr = (node*)malloc(sizeof(node));
    node*curr2 = (node*)malloc(sizeof(node));
    curr->next = NULL;
    node*head = curr;
    curr2=(node*)malloc(sizeof(node));
    curr2->next=NULL;
    node*head2=curr2;
    aramayap(curr,curr2);
    return 0;
}
