#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int main(){
	printf("Give Total disk space: ");
	int a,f;
	char *x;
	scanf("%d",&a);
	int disk[a];
	for(int i=0;i<a;i++){disk[i]=0;}
	char *name[a];
	while(0==0){
	printf("\n\n1: ADD FILE\n2: DELETE FILE\n3: RENAME\n4: FRAGMENTATION\n5: TOTAL FREE SPACE\n6: ADDRESS OF FREE LOCATION\n7: HOW I AM STORING FILE NAME\n8: HOW I AM OCCUPING SPACE\n9: EXIT\n->>>> ");
	scanf("%d",&f);
	char file[20];
	switch(f){
		case 1:int size;
			printf("GIVE SIZE: ");
			scanf("%d",&size);
			printf("FILE NAME: ");
			scanf("%s",file);
			int l=strlen(file);
			x = (char *)malloc(l + 1);
			strcpy(x, file);
			int flag=0;
            int pos;
            int check=0;
            for(int i=0;i<a;i++){
            	if(disk[i]==0){
            		check++;
            		if(check==size){
            			pos=i;
            			flag=1;
            			break;
            		}
            	}
            	if(disk[i]==1){
            		check=0;
            	}
            }
            if(flag == 0){
                printf("--------Sorry------\n");
            	printf("Space not available\n");
            	printf("-------------------\n");
            }
            else{
            	for(int i=pos-size+1;i<pos+1;i++){
            		disk[i]=1;
            		name[i]=x;
            	}
            }
			
			break;
		case 2:
			printf("FILE NAME: ");
			scanf("%s",file);
			char *c;
			l=strlen(file);
			x = (char *)malloc(l + 1);
			strcpy(x, file);
			
        	for(int i=0;i<a;i++){
        	    c=name[i];
        	    if(c!=NULL){
        		if((strcmp(c,x))==0){
        			disk[i]=0;
        			name[i]=NULL;
        		}}
        	}
			
			break;
		case 3:
		    printf("OLD FILE NAME: ");
			scanf("%s",file);
			char nfile[20];
			char *y;
			printf("NEW FILE NAME: ");
			scanf("%s",nfile);
			//char *c;
			l=strlen(file);
			x = (char *)malloc(l + 1);
			strcpy(x, file);
			
			y = (char *)malloc(strlen(nfile) + 1);
			strcpy(y, nfile);
			
        	for(int i=0;i<a;i++){
        	    c=name[i];
        	    if(c!=NULL){
        		if((strcmp(c,x))==0){
        			disk[i]=0;
        			name[i]=y;
        		}}
        	}
		    break;
		case 4:
		    int m=0,frag=0;
		    for(int i=0;i<a;i++){
		        if(disk[i]==0){
		            m++;
		        }
		        if(m!=0 && (disk[i]==1||i==a-1)){
		            frag++;
		            m=0;
		        }
		    }
		    printf("Fragmentated area left = %d\n",frag);
		    break;
		   
		case 5:
		    int area=0;
		    for(int i=0;i<a;i++){
		        if(disk[i]==0){
		            area++;
		        }
		    }
		    printf("Total free space/Wasted space = %d\n",area);
		    break;
		case 6:
		    printf("Address of free Location\n");
		    for(int i=0;i<a;i++){
		        if(disk[i]==0){
		            printf("- %d - ",i);
		        }
		    }
		    printf("\n");
		    break;
		case 7:
		
		    printf("This is how I am storing file name to stimulate a file system \n");
		    for(int i=0;i<a;i++){
		        printf("- %s -",name[i]);
		    }
		    break;
		case 8:
		
		    printf("This is how I am storing file space utilization to stimulate a file system \n");
		    for(int i=0;i<a;i++){
		        printf("- %d -",disk[i]);
		    }
		    break;
		case 9:
		    
		    double end=0;
		    for(int i=0;i<a;i++){
		        if(disk[i]==0){
		            end++;
		            
		        }
		    }
		    printf("Average Wasted space in percent = %f ",end/a*100);
		    return 0;
		default:printf("Invalid Value");
	}}
	
}
