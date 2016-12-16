
int statsMenu(int choiceMenu, char key) // AFFICHAGE MENU DES STATISTIQUES
{
        system("clear");
        printf("\n\n\n\n               WELCOME TO STATISTICS MENU \n\n\n\n\n\n\nWhat do you want to do ?\n\n1. Statistics display\n2. Quit\n");
	key = getch(); // fonctionne comme un scanf sans besoin d'appuyer sur entrée pour éxecuter la fonction
	system("setterm -cursor off"); // cache le curseur blanc qui clignote
	while(1) // boucle infinie
		{
			if (key == 50) // sur la table ASCII, 2 correspond à 50, alors i on presse 2 :
			{
				system("clear");
				system("setterm -cursor on"); // remet le curseur blanc qui clignote
				exit(0); // arrêt du processus
		        }
			else if (key == 49) // sur la table ASCII, 1 correspond à 49, alors si on presse 1 :
			{
				choiceMenu= 1;
				return choiceMenu; //renvoie 1 comme choix menu
			}
			else // SINON, attend que l'on rentre 1 ou 2 en redemmandant
			{
				key = getch();
			}
		}
}

int* readHistTri(int nb_static,int nb_dynamic,int nb_interactive,int nb_total) // LECTURE DU FICHIER OÙ LES NOMBRES STOCKÉS DES CHOIX ÉCRANS SONT TRIÉ
{
        FILE* fileHistTri = NULL; // On initialise le pointeur qui va lire le fichier à NULL
        int current_charact = 0; // représente le caractère actuel
        fileHistTri = fopen("histTrie.txt", "r"); // le pointeur ouvre le fichier demandé (histTrie)

        if (fileHistTri != NULL) // si le pointeur trouve le fichier et l'ouvre, boucle de lecture de caractère un à un
        {
                current_charact = fgetc(fileHistTri); // On lit le caractère que le pointeur pointe
                while(current_charact != EOF)  // Faire tant que fin du fichier non atteint (EOF)
                {
                        if(current_charact=='1') // Si on a un 1, le b_static et le nb_total augmentent
                        {
                                nb_static ++ ;
                                nb_total ++;
                        }
                        else if(current_charact=='2') // Si on a un 2, le nb_dynamic et le nb_total augmentent
                        {
                                nb_dynamic ++;
                                nb_total ++;
                        }
                        else if(current_charact=='3') // Si on a un 3, le nb_interactive et le nb_total augmentent
                        {
                                nb_interactive ++;
                                nb_total ++;
                        }
                        current_charact = fgetc(fileHistTri);   // On redemande de lire le caractère qui est pointé par le pointeur pour la boucle
                }
        }
        fclose(fileHistTri); // fermeture du fichier (histTrie)
        int *statistic; // tableau stockant les nombre pour pouvoir les renvoyer
        statistic = malloc(4*sizeof(int)); // alloue la mémoire pour le tableau de 4 cases
        statistic[0] = nb_static; // stockage dans la case 0
        statistic[1] = nb_dynamic; // stockage dans la case 1
        statistic[2] = nb_interactive; // stockage dans la case 2
        statistic[3] = nb_total; // stockage dans la case 3
        return statistic;
}

void displayStats(int *statistic) // AFFICHER LES STATS
{
        system("clear");

        printf("\n\n\n\nNumber of static screen choices : %d/ %d", statistic[0], statistic[3]);
        printf("\nNumber of dynamic screen choices : %d/ %d", statistic[1], statistic[3]);
        printf("\nNumber of interactive screen choices : %d/ %d", statistic[2], statistic[3]);
        printf("\nNumber of screen choices : %d\n\n\n", statistic[3]);
	printf("\n\n\n\n\n\nTAP SPACE TO QUIT");
}
