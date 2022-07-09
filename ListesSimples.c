#include<stdio.h>
#include<stdlib.h>


typedef struct ELEMENT{
    int info;
    struct ELEMENT *SUIV,
}ELEMENT;

ELEMENT *insererEnTete(ELEMENT *TETE,int x){
    ELEMENT *nouveau;
    nouveau=malloc(sizeof(ELEMENT));
    nouveau->info=x;
    //(*nouveau).info=x;
    nouveau->SUIV=TETE;
    TETE=nouveau;
    return TETE;
}

ELEMENT* insererAuMilieu(ELEMENT * TETE, int x, int y){
	if (TETE==NULL)
        return TETE;

	ELEMENT *parcours, *nouveau;
	parcours = TETE;
	while (parcours->info != x){
        parcours = parcours->SUIV;
        if(parcours==NULL){
            break;
        }
    }
	if(parcours==NULL){
        return TETE;
	}
	else{
        nouveau = malloc(sizeof (ELEMENT));
        nouveau -> info = y;
        nouveau -> SUIV = parcours->SUIV;
        parcours->SUIV= nouveau;
        return TETE;
	}
}

ELEMENT* insererEnQueue(ELEMENT* TETE, int x){
	if (TETE==NULL)
        TETE=insererEnTete(TETE,x);
    else{
        ELEMENT *nouveau, *parcours;
        nouveau = malloc(sizeof(ELEMENT));
        nouveau -> info = x;
        nouveau -> SUIV = NULL;
        parcours = TETE;
        while (parcours->SUIV!=NULL){
            parcours=parcours->SUIV;
        }
        parcours->SUIV=nouveau;
    }
	return TETE;
}

ELEMENT *supprimerEnTete(ELEMENT *TETE){
    if(TETE!=NULL){
        ELEMENT *temp = TETE;
        TETE=TETE->SUIV;
        free(temp);
    }
    return TETE;
}

ELEMENT *supprimerEnQueue(ELEMENT * TETE){
	if(TETE==NULL){
		return TETE;
	}
	if (TETE->SUIV==NULL){
		free(TETE);
		TETE =NULL;
		return TETE;
	}
	ELEMENT *Temp,*parcours;
	parcours = TETE;
	while(parcours->SUIV->SUIV != NULL){
		parcours = parcours->SUIV;
	}
	Temp = parcours->SUIV;
	parcours->SUIV = NULL;
	free(Temp);
	return TETE;
}


ELEMENT *supprimerAuMilieu(ELEMENT * TETE, int x){
	if(TETE==NULL){
		return TETE;
	}
	if (TETE->SUIV==NULL){
		if (TETE->info==x){
            free(TETE);
            TETE = NULL;
            return TETE;
		}
		else
            return TETEx
	}
	if(TETE->info==x)
        return supprimerEnTete(TETE);

	ELEMENT *temp,*parcours;
	parcours= TETE;
	while (parcours-> SUIV-> info != x){
		parcours = parcours->SUIV;
		if(parcours==NULL){
            break;
        }
	}
	if (parcours==NULL)
        return TETE;
    temp = parcours->SUIV;
    parcours->SUIV = parcours->SUIV->SUIV;
    free(temp);
    return TETE;
}

void afficherListe(ELEMENT *TETE){
	if(TETE==NULL){
		printf("votre liste est vide\n");
    }
	else{
		ELEMENT * parcours=TETE;
		printf("\n");
		while(parcours!=NULL){
			printf("<%d>\t",parcours->info);
			parcours=parcours->SUIV;
		}
		printf("\n");
	}
}

ELEMENT * supprimerDoublons(ELEMENT * TETE){
    if (TETE==NULL || TETE->SUIV==NULL)
        return TETE;
    ELEMENT * parcours = TETE;
    ELEMENT * supprime;
    while (parcours->SUIV!=NULL){
        if (parcours->info==parcours->SUIV->info){
            supprime=parcours->SUIV;
            parcours->SUIV=parcours->SUIV->SUIV;
            free(supprime);
        }
        else
            parcours=parcours->SUIV;
    }
    return TETE;
}

void main(){
    int choix, val, val2;
    ELEMENT * TETE;
    printf("\n----- Listes Simplement Chainees -----\n");
    while(1){
        printf("\n***** MENU *****\n");
        printf("1. Creer Une Liste Vide\n");
        printf("2. Inserer en tete de la liste\n");
        printf("3. Inserer au milieu de la liste\n");
        printf("4. Inserer en4 queue de la liste\n");
        printf("5. Supprimer en tete de la liste\n");
        printf("6. Supprimer au milieu de la liste\n");
        printf("7. Supprimer en queue de la liste\n");
        printf("8. Afficher la liste\n");
        printf("9. Supprimer doublons\n");
        printf("10. Quitter\n");

        printf("\nEntrer votre choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1: TETE = NULL;
                    printf("\nUne liste vide a ete cree");
                    break;
            case 2: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    TETE = insererEnTete(TETE,val);
                    break;
            case 3: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    printf("\nEntrer la valeur precedente: ");
                    scanf("%d", &val2);
                    TETE = insererAuMilieu(TETE,val2,val);
                    break;
            case 4: printf("\nEntrer la valeur a inserer: ");
                    scanf("%d", &val);
                    TETE = insererEnQueue(TETE,val);
                    break;
            case 5: TETE = supprimerEnTete(TETE);
                    break;
            case 6: printf("\nEntrer la valeur a supprimer: ");
                    scanf("%d", &val);
                    TETE = supprimerAuMilieu(TETE,val);
                    break;
            case 7: TETE = supprimerEnQueue(TETE);
                    break;
            case 8: afficherListe(TETE);
                    break;
            case 9: TETE = supprimerDoublons(TETE);
                    break;
            case 10: exit(0);
            default: printf("\nSVP Veuiller choisir parmi la liste des choix!!!\n");
      }
   }
   system ("pause");

}
