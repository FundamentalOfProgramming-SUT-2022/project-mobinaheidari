#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
char clipboard[1000];
///////////////////////////////////////////////create file
int create_dir(char *name)
{
    int rc;

    rc = mkdir(name);
    if (rc != 0 && errno != EEXIST)
    {

        perror("mkdir");

    }
    if (rc != 0 && errno == EEXIST)
        printf("%s already exist.\n", name);

    return 0;
}
void createfile(char *s){


    int l=0;
    static int b;

    char a[100]={0};
    for(int i=0;i<strlen(s);i++){
        if (s[i]==' '){
            l++;
        }
        else if(s[i]=='/'){
            b++;
        }
    }
    b-=2;
    if (l>=3&&s[strlen(s)-1]!='"'){
        printf("invalid command");
        return 0;
    }
    int n;
   if (s[strlen(s)-1]=='"'){
    n=27;}
   else {n=26;}

    for (int i=n;i<strlen(s);i++){

static int j=0;

           if (j==strlen(s)){
            break;
           }

       if (s[i]!='"'){
        a[j]=s[i];

}
        if (s[i]=='/'){
                for (int k=0;k<strlen(a);k++){

                }
                if (b>=1){

                        b--;
            create_dir(&a);
            }

        }

        j++;
    }

FILE *fp;
fp=fopen(a,"w");
fclose(fp);



}
//////////////////////////////////////////////////////////////////insert
void insert(char* insert){
    ////////////////////////////////////////////////////////////////////////space
 int non_space_count = 0;


    for (int i = 0; insert[i] != '\0'; i++)
    {
        if (insert[i] != ' '||insert[i+1]!='-')
        {
            insert[non_space_count] = insert[i];
            non_space_count++;
        }
    }


    insert[non_space_count] = '\0';

/////////////////////////////////////////////////////////////////////////
int num=0;
char token_list[100][100];
char *token=strtok(insert,"-");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, "-");
   }
   for (int i=0;i<num;i++){
  //  printf("%s \n",token_list[i]);
   }
   ////////////////////////////////////////////////////////  "
   for (int i=0;i<num;i++){
        for (int j=0;token_list[i][j]!='\0';j++){
            if(token_list[i][j]=='"'&&token_list[i][j-1]!=92){
                    for (int k=j;k<strlen(token_list[i]);k++)
                token_list[i][k]=token_list[i][k+1];
            }
        }

   }
   //////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////text file
  FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[1]+13, "r");
    if(textfile == NULL){

      printf("File does not exist");
        return 1;}

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);



/////////////////////////////////////////// insert text
char strC[50];
int a=1,b,count=1,k=0,n=4;
int g=strlen(token_list[2]);
//printf("*%c",token_list[2][g]);

char c[4],c1;
char add2[100]={0};
for (int i=n;i<g;i++){
    add2[k]=token_list[2][i];
    k++;
}
int h=strlen(add2);
char add1[100]={0};


for (int i=0,j=0;i<h;i++,j++){

        if (add2[i]==92){

            if (add2[i+1]=='"'){

                    add1[j]=add2[i+1];

            i+=1;
                continue;
            }
            else if(add2[i+1]=='n'){

                add1[j]='\n';

            i+=1;
            continue;
            }
             else if (add2[i+1]==92){

            if (add2[i+2]=='n'){


                add1[j]=92;
                j++;
                add1[j]='n';

        i+=2;
        continue;
            }}
        }

    add1[j]=add2[i];


}




   //printf("%s",add1);


//////////////////////////////////  position
sscanf(token_list[3],"%s%d:%d",c,&a,&b);


for (int i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
        count++;
    }
    if (count ==a){

        int x = b+i+a-1;

strncpy(strC, text, x);
strC[x] = '\0';
strcat(strC,add1);
strcat(strC, text +x);
FILE *fp=fopen(token_list[1]+13,"w");
fprintf(fp,strC);
fclose(fp);
break;

    }
}
if(count<a){

 printf("Position isn't correct!");
 }

return 0;


}
void cat(char *str){
       ////////////////////////////////////////////////////////////////////////space
 int non_space_count = 0;


    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' '||str[i+1]!='-')
        {
            str[non_space_count] = str[i];
            non_space_count++;

        }
    }


    str[non_space_count] = '\0';

/////////////////////////////////////////////////////////////////////////
int num=0;

char token_list[100][100];
char *token=strtok(str,"-");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, "-");
   }
   for (int i=0;i<num;i++){

   }
   //////////////////////////////////////////////////////// "
   for (int i=0;i<num;i++){

        for (int j=0;token_list[i][j]!='\0';j++){
            if(token_list[i][j]=='"'&&token_list[i][j-1]!=92){
                    for (int k=j;k<strlen(token_list[i]);k++){
                token_list[i][k]=token_list[i][k+1];

                    }
            }
        }

   }
   //////////////////////////////////////////////////////////////
   //////////////////////////////////////////////////text file
  FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[1]+13, "r");
    if(textfile == NULL){

      printf("File does not exist");
        return 1;}

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    printf(text);

}
void remove1(char *str){
         ////////////////////////////////////////////////////////////////////////space
 int non_space_count = 0;


    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' '||str[i+1]!='-')
        {
            str[non_space_count] = str[i];
            non_space_count++;

        }
    }


    str[non_space_count] = '\0';

/////////////////////////////////////////////////////////////////////////

 int num=0;
   char token_list[50][100];
char *token=strtok(str,"-");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, "-");
   }

    //////////////////////////////////////////////////////// "
   for (int i=0;i<num;i++){

        for (int j=0;token_list[i][j]!='\0';j++){
            if(token_list[i][j]=='"'&&token_list[i][j-1]!=92){
                    for (int k=j;k<strlen(token_list[i]);k++){
                token_list[i][k]=token_list[i][k+1];

                    }
            }
        }

   }
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// text file
 FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[1]+13, "r");
    if(textfile == NULL)
        printf("File does not exist");

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

  //  printf(text);
    ////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////// position
    int a,b,c,k=0,count=1;
    char pos1[3],size[4];

    sscanf(token_list[2],"%s%d:%d",pos1,&a,&b);

    sscanf(token_list[3],"%s%d",size,&c);


    char copy[10];
    for (int i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
        count++;
    }
    if (count ==a){

        int x = b+i+1;

       if (token_list[4][0]=='f'){

                for (int j=x;j<strlen(text);j++){

            text[j]=text[j+c];

        }}
       if (token_list[4][0]=='b'){

        for (int j=x-c;j<strlen(text);j++){
            text[j]=text[j+c];
        }
       }

        FILE *fp=fopen(token_list[1]+13,"w");
        fprintf(fp,text);
        fclose(fp);


  break;
    }}
if(count<a){

 printf("Position isn't correct!");
 }


}
void copy(char *str){
    ///////////clipboard
   clipboard[1000]=NULL;
     ////////////////////////////////////////////////////////////////////////space
 int non_space_count = 0;


    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' '||str[i+1]!='-')
        {
            str[non_space_count] = str[i];
            non_space_count++;

        }
    }


    str[non_space_count] = '\0';

/////////////////////////////////////////////////////////////////////////

/////////// token_list
   int num=0;
   char token_list[50][100];
char *token=strtok(str,"-");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, "-");
   }
   for (int i=0;i<num;i++){
  //  printf("%s \n",token_list[i]);
   }
//////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////// "
   for (int i=0;i<num;i++){

        for (int j=0;token_list[i][j]!='\0';j++){
            if(token_list[i][j]=='"'&&token_list[i][j-1]!=92){
                    for (int k=j;k<strlen(token_list[i]);k++){
                token_list[i][k]=token_list[i][k+1];

                    }
            }
        }

   }
//////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////// text file
 FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[1]+13, "r");
    if(textfile == NULL)
        printf("File does not exist");

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

   // printf(text);
    ////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////// position
    int a,b,c,k=0,count=0;
    char pos1[4],size[4];

    sscanf(token_list[2],"%s%d:%d",pos1,&a,&b);

    sscanf(token_list[3],"%s%d",size,&c);

    a--;

    for (int i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
        count++;
    }
      if (count ==a){

        int x = b+i+1;

       if (token_list[4][0]=='f'){

                for (int j=x;j<x+c;j++){

            clipboard[k]=text[j];
            k++;

        }}
       if (token_list[4][0]=='b'){

        for (int j=x-c;j<x;j++){
            clipboard[k]=text[j];
            k++;
        }
       }

      //  printf("%s",clipboard);
  break;
    }}
    if(count<a){

 printf("Position isn't correct!");
 }


}
void paste(char *str){
       ////////////////////////////////////////////////////////////////////////space
 int non_space_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' '||str[i+1]!='-')
        {
            str[non_space_count] = str[i];
            non_space_count++;

        }
    }


    str[non_space_count] = '\0';

/////////////////////////////////////////////////////////////////////////

    ///////////
   int num=0;
   char token_list[50][100];
char *token=strtok(str,"-");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, "-");
   }
   for (int i=0;i<num;i++){
   // printf("%s \n",token_list[i]);
   }
    //////////////////////////////////////////////////////// "
   for (int i=0;i<num;i++){

        for (int j=0;token_list[i][j]!='\0';j++){
            if(token_list[i][j]=='"'&&token_list[i][j-1]!=92){
                    for (int k=j;k<strlen(token_list[i]);k++){
                token_list[i][k]=token_list[i][k+1];

                    }
            }
        }

   }
//////////////////////////////////////////////////////////////////////////

///////////////////////////////////////text file
 FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[1]+13, "r");
    if(textfile == NULL)
        return 1;

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

   // printf(text);
    /////////////////////////////////intsert
char addd[1000];
char strC[50];
int a,b,count=0;
char c[4];
sscanf(token_list[2],"%s%d:%d",c,&a,&b);

for (int i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
        count++;
    }
    if (count ==a-1){

        int x = b+i+1;

strncpy(strC, text, x);
strC[x] = '\0';

strcat(strC, clipboard);
strcat(strC, text +x);
FILE *fp=fopen(token_list[1]+13,"w");
fprintf(fp,strC);
fclose(fp);
break;

    }
}
 if(count<a){

 printf("Position isn't correct!");
 }
//printf(text);


}
void cut(char * str){
clipboard[1000]=NULL;
   ////////////////////////////////////////////////////////////////////////space
 int non_space_count = 0;


    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' '||str[i+1]!='-')
        {
            str[non_space_count] = str[i];
            non_space_count++;

        }
    }


    str[non_space_count] = '\0';

/////////////////////////////////////////////////////////////////////////

 int num=0;
   char token_list[50][100];
char *token=strtok(str,"-");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, "-");
   }
   for (int i=0;i<num;i++){
 //   printf("%s \n",token_list[i]);
   }
//////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////"
   for (int i=0;i<num;i++){

        for (int j=0;token_list[i][j]!='\0';j++){
            if(token_list[i][j]=='"'&&token_list[i][j-1]!=92){
                    for (int k=j;k<strlen(token_list[i]);k++){
                token_list[i][k]=token_list[i][k+1];

                    }
            }
        }

   }
//////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////// text file
 FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[1]+13, "r");
    if(textfile == NULL)
        printf("File does not exist");

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

  //  printf(text);
    ////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////// position
    int a,b,c,k=0,count=0;
    char pos1[4],size[4];

    sscanf(token_list[2],"%s%d:%d",pos1,&a,&b);

    sscanf(token_list[3],"%s%d",size,&c);

    a--;

    for (int i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
        count++;
    }
      if (count ==a){

        int x = b+i+1;

       if (token_list[4][0]=='f'){

                for (int j=x;j<x+c;j++){

            clipboard[k]=text[j];
            k++;

        }}
       if (token_list[4][0]=='b'){

        for (int j=x-c;j<x;j++){
            clipboard[k]=text[j];
            k++;
        }
       }

  break;
    }}
    ////////////////////////////////////////////////////////////delete
    count=0;
    int check=1,count2=0;
      for (int i=0;i<strlen(text);i++){
    if(text[i]=='\n'){
        count++;
    }
    if (count ==a){

        int x = b+i+1;

       if (token_list[4][0]=='f'){
            for(int j=i+1;j<i+b;j++){
                 if(text[j]='\n'){
                printf("Position isn't correct.");
                check=0;
                break;

            }
            }

                for (int j=x;j<strlen(text)&&check==1;j++){


            text[j]=text[j+c];

        }}
       if (token_list[4][0]=='b'){
            for(int j=i+1;j<i+b;j++){
                if(text[j]='\n'){


                    printf("Position isn't correct.");
                    check=0;
                    break;
                }
            }

        for (int j=x-c;j<strlen(text)&&check==1;j++){

            text[j]=text[j+c];
        }
       }

        printf("%s",text);
        FILE *fp=fopen(token_list[1]+13,"w");
       fprintf(fp,text);
        fclose(fp);

  break;
    }
      }

if(count<a){

 printf("Position isn't correct!");
 }

}
void compare(char *str){
//////////////////////////////////////////////delete "
 for (int i=0;i<strlen(str);i++){
    if(str[i]=='"'&&str[i-1]!=92){
        for (int k=i;k<strlen(str);k++){
            str[k]=str[k+1];
        }
    }}
  //  printf("%s",str);


////////////////////token_list .
int num=0;
char token_list[100][100];
char *token=strtok(str,".");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, ".");
   }
    int h1=strlen(token_list[1]);
   int h=strlen(token_list[0]);
   token_list[0][h]='.';
   token_list[0][h+1]='t';
   token_list[0][h+2]='x';
   token_list[0][h+3]='t';
   token_list[1][h1]='.';
   token_list[1][h1+1]='t';
   token_list[1][h1+2]='x';
   token_list[1][h1+3]='t';
   for (int i=0;i<num;i++){
  //  printf("%s \n",token_list[i]);
   }

   //////////////////////////////////////////////////////////text file 1
     //////////////////////////////////////////////////text file
  FILE    *textfile;
char    *text;
    long    numbytes;

    textfile = fopen(token_list[0]+8, "r");
    if(textfile == NULL)
    {
       printf("File does not exist");
    }

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

   // printf(text);

   /////////////////////////////////////////////////////////text file 2
     //////////////////////////////////////////////////textfile
  FILE    *textfile2;
char    *text2;
    long    numbytes2;

    textfile2 = fopen(token_list[1]+4, "r");
    if(textfile2 == NULL)
    {
        printf("File does not exist");
    }

    fseek(textfile2, 0L, SEEK_END);
    numbytes2 = ftell(textfile2);
    fseek(textfile2, 0L, SEEK_SET);

    text2 = (char*)calloc(numbytes2, sizeof(char));
    if(text2 == NULL)
        return 1;

    fread(text2, sizeof(char), numbytes2, textfile2);
    fclose(textfile2);

  //  printf(text2);

    ////////////////////token_list \n
int num1=0;
char token_list1[100][100];
char *token1=strtok(text,"\n");
while( token1 != NULL ) {
        strcpy(token_list1[num1], token1);
        num1++;

      token1 = strtok(NULL, "\n");
   }
   for (int i=0;i<num1;i++){
  //  printf("%s \n",token_list1[i]);
   }
   ////////////////////token_list \n text2
int num2=0,value;
char token_list2[100][100];
char *token2=strtok(text2,"\n");
while( token2 != NULL ) {
        strcpy(token_list2[num2], token2);
        num2++;

      token2 = strtok(NULL, "\n");
   }
   for (int i=0;i<num2;i++){
  // printf("%s \n",token_list2[i]);
   }
    ////////////////////////////compare

    int line=0,line2=0,i=0,j=0;

    for(int i=0;i<num1&&i<num2;i++){
        value=strcmp(token_list1[i],token_list2[i]);
        //printf("%s\n%s\n",token_list1[i],token_list2[i]);
        if(value!=0){
           printf("%d\n",i+1);
            printf("%s\n%s\n",token_list1[i],token_list2[i]);
            }

    }
    i++;
    if(i<num1-1){
        printf("%d %d\n",i+2,num1);
        for(i=i+1;i<=num1;i++){
            printf("%s\n",token_list1[i]);
        }
    }
    else if(i<num2-1){
        printf("%d %d\n",i+2,num2);
        for(i=i+1;i<=num2;i++){
            printf("%s\n",token_list2[i]);
        }
    }
    }
int main()
{
char str[1000]={0};
char str1[1000]={0};

while(1){
   gets(str);
   for(int i=0;i<strlen(str);i++){
    str1[i]=str[i];
   }
   int num=0;
char token_list[100][100];
char *token=strtok(str," ");
while( token != NULL ) {
        strcpy(token_list[num], token);
        num++;

      token = strtok(NULL, " ");
   }
   for (int i=0;i<num;i++){

   }
if(strcmp(token_list[0],"createfile")==0)
    createfile(&str1);
 else if(strcmp(token_list[0],"insertstr")==0){


    insert(&str1);}
 else if(strcmp(token_list[0],"cat")==0)
    cat(&str1);
else if (strcmp(token_list[0],"removestr")==0)
    remove1(&str1);
   else if(strcmp(token_list[0],"copystr")==0)
        copy(&str1);
   else if (strcmp(token_list[0],"pastestr")==0)
        paste(&str1);
  else  if (strcmp(token_list[0],"cutstr")==0)
        cut(&str1);
   else if(strcmp(token_list[0],"compare")==0)
        compare(&str1);
  else
    printf("invalid command");
}

}
