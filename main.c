#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    int i=0,j, choix1, choix2,x=-1,valeur_i;
	int nbrclient=0, n=0,num;
	float Montant;
	char CIN[10];
typedef struct{	
    char cin[10];
	char nome[40];
	char prenom[40];

	float montant;
}donnes;

donnes client[1000];
donnes t;

void afficher(){
	for(i=0;i<nbrclient;i++)
	{
		printf("%s\t%s\t%s\t%.2f\n",client[i].cin, client[i].nome, client[i].prenom, client[i].montant);		
	}
	}
int recherche()
	{
		printf("Entrez CIN de compte: ");
        scanf("%s",CIN);
		for(i=0;i<n+nbrclient;i++)
		{	
	      if((strcmp(client[i].cin,CIN))==0)
		  {
			x=i;
		    break;
		  }
		}
		return x;
	}
	
	void ascendant(){
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(client[i].montant>client[j].montant)
				{
					t= client[i];
           	 		client[i]=client[j];
           	 		client[j]=t;
				}
			}
		}
	}
	
	void descendant(){
		for(i=0;i<n-1;i++)
		{
         	for(j=i+1;j<n;j++)
			   {
           	 		if(client[i].montant<client[j].montant)
						{
           	 			   t= client[i];
           	 			   client[i]=client[j];
           	 			   client[j]=t;
						}
				} 	
		}
	}
int main() {
	menu:
	printf("\t\t\t --MAIN MENU-- :\n");
	printf("1-Cree un compte:\n2-Cree plusieurs comptes:\n3-Operation:\n4-Affichage:\n5-Fidelisation\n6-Quitter l application\n\n");
	printf("Donnez votre choix :  ");
	scanf("%d",&choix1);
	switch(choix1){
		case 1:	
			printf("cin: ");
			scanf("%s",client[n].cin);  
            printf("\nNom : ");
            scanf("%s",client[n].nome);
            printf("\nPrenom : ");
            scanf("%s",client[n].prenom);
            printf("\nMontant : ");
            scanf("%f",&client[n].montant);
			n++;
			 
		goto menu;
		
			break;
	
			case 2:
			printf("veuiller entrer le nombre des clients :\n");
			scanf("%d",&nbrclient);
			for(i=n;i<n+nbrclient;i++){
				printf("cin: ");
				scanf("%s",client[i].cin);
	            printf("\nNom : ");
	            scanf("%s",client[i].nome);
	            printf("\nPrenom : ");
	            scanf("%s",client[i].prenom);
	            printf("\nMontant : ");
	            scanf("%f",&client[i].montant);
			}
		 n+=nbrclient;

			
		   	
		    goto menu;	
			break;
		
			case 3:
				printf("1-Depot:\n");
				printf("2-Retrait: \n");
				printf("Entrer le type d_operation : \n");
			    scanf("%d",&choix2);
			    switch(choix2)
				{		    	
				case 1:{

					if(recherche()!=-1)
					{
						printf("Entrez le montant  ");
						scanf("%f",&Montant);
						client[valeur_i].montant+=Montant;
					}else
					{
						printf("Il y a aucun compte!");
					}
					afficher();
				goto menu;
				};break;
			case 2:
				printf("veuillez entrer la cin:  ");
				scanf("%s",CIN);
				if(recherche()!=-1){
					printf("Entrez le montant ");
					scanf("%f",&Montant);
					client[valeur_i].montant-=Montant;
				}else{
					printf("Il ya aucun compte!\n");
				}
				afficher();
				goto menu;
				break;
		}	
			case 4:
			printf("\t1-Par Ordre Ascendant\n\t2-Par Ordre Descendant\n\t3-Par Ordre Ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
			printf("\t4-Par Ordre Descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n\t5-Recherche par CIN\n");
			printf("Donnez le choix : ");
         	scanf("%d",&choix2);
         	 switch(choix2){
         	 	case 1:
         	 		 ascendant();
         	 		 afficher();
					  goto menu;
				break;
         	 	case 2:
         	 			descendant();
					  afficher();
					  
					  
					  goto menu;
         	 	break;
         	 	case 3:
         	 		printf("Entrez un chiffre : ");
             	    scanf("%f",&Montant);
             	    ascendant();
                for(i=0;i<n;i++)
				{
         			if(client[i].montant>Montant)
					 {
         				printf("%s\t%s\t%s\t%.2f\n",client[i].cin, client[i].nome, client[i].prenom, client[i].montant);
					 }
		     	}
		        goto menu;
         	 	break;
         	 	case 4:
         	 		{
         	 			printf("Entrez un chiffre pour l_operation: ");
             	        scanf("%f",&Montant);
             	        descendant();
		                for(i=0;i<n;i++)
						{
		         			if(client[i].montant>Montant)
							 {
		         				printf("%s\t%s\t%s\t%.2f\n",client[i].cin, client[i].nome, client[i].prenom, client[i].montant);
							 }
				     	}
		       		 goto menu;
					};break;
         	 	
         	 	case 5:
         	         recherche();
         	         if(recherche()!=-1){
         	         	printf("le compt exist\n");
         	         	printf("CIN : %s ,Nom : %s ,Prenom : %s ,Montan : %.2f ,",client[x].cin,client[x].nome,client[x].prenom,client[x].montant);
					   }
					   else
					   {
					   		printf("Il y a aucun compte.");
					   }
					   goto menu;
         	 	break;
			  }
			break;
			case 5:{
				printf("1.3% pour les 3 premiers montants supérieurs");
				descendant();
				for(i=0;i<3;i++)
				{
					client[i].montant=	client[i].montant+(client[i].montant*0.013);
				}
				goto menu;
				
			};break;
			case 6:{
				printf("Quiter");	
		
			};break;
			default:printf("Incorecte");
		
}		
	return 0;
}

