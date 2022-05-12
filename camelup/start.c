#include <stdio.h>
#include <stdlib.h>
#include "start.h"


int start()
{

    printf("\n\tBienvenue dans.......\n\n\n\n");




    printf("                __  \n");
    printf("                                 .--.      .'  `.  \n");
    printf("                               .' . :\\    /   :  L  \n");
    printf("                               F     :\\  /   . : |        .-._  \n");
    printf("                              /     :  \\/        J      .' ___\\  \n");
    printf("                             J     :   /      : : L    /--'   ``.  \n");
    printf("                             F      : J           |  .<'.o.  `-'>  \n");
    printf("                            /        J             L \\_>.   .--w)  \n");
    printf("                           J        /              \\_/|   . `-__|  \n");
    printf("                           F                        / `    -' /|)  \n");
    printf("                          |   :                    J   '        |  \n");
    printf("                         .'   ':                   |    .    :  \\  \n");
    printf("                        /                          J      :     |L  \n");
    printf("                       F                              |     \\   ||  \n");
    printf("                      F .                             |   :      |  \n");
    printf("                     F  |                             ; .   :  : F  \n");
    printf("                    /   |                                     : J  \n");
    printf("                   J    J             )                ;        F  \n");
    printf("                   |     L           /      .:'                J  \n");
    printf("                .-'F:     L        ./       :: :       .       F  \n");
    printf("                `-'F:     .\\    `:.J         :::.             J  \n");
    printf("                  J       ::\\    `:|        |::::\\            |  \n");
    printf("                  J        |:`.    J        :`:::\\            F  \n");
    printf("                   L   :':/ \\ `-`.  \\       : `:::|        .-'  \n");
    printf("                   |     /   L    >--\\         :::|`.    .-'  \n");
    printf("                   J    J    |    |   L     .  :::: :`, /  \n");
    printf("                    L   F    J    )   |        >::   : /  \n");
    printf("                    |  J      L   F   \\     .-.:'   . /  \n");
    printf("                    ): |     J   /     `-   | |   .--'  \n");
    printf("                    /  |     |: J        L  J J   )  \n");
    printf("                    L  |     |: |        L   F|   /  \n");
    printf("                    \\: J     \\:  L       \\  /  L |  \n");
    printf("                     L |      \\  |        F|   | )  \n");
    printf("                     J F       \\ J       J |   |J  \n");
    printf("                      L|        \\ \\      | |   | L  \n");
    printf("                      J L        \\ \\     F \\   F |  \n");
    printf("                       L\\         \\ \\   J   | J   L  \n");
    printf("                      /__\\_________)_`._)_  |_/   \\_____  \n");

    //art by Veronica Karlsson on asciiart.eu


    printf("\n\n\n\n");


    printf("________/\\\\\\\\\\\\\\\\\\____________________________________________________/\\\\\\\\\\\\_____/\\\\\\________/\\\\\\_______________  \n");
    printf(" _____/\\\\\\////////____________________________________________________\\////\\\\\\____\\/\\\\\\_______\\/\\\\\\_______________  \n");
    printf("  ___/\\\\\\/________________________________________________________________\\/\\\\\\____\\/\\\\\\_______\\/\\\\\\___/\\\\\\\\\\\\\\\\\\__  \n");
    printf("   __/\\\\\\______________/\\\\\\\\\\\\\\\\\\_______/\\\\\\\\\\__/\\\\\\\\\\_______/\\\\\\\\\\\\\\\\_____\\/\\\\\\____\\/\\\\\\_______\\/\\\\\\__/\\\\\\/////\\\\\\_  \n");
    printf("    _\\/\\\\\\_____________\\////////\\\\\\____/\\\\\\///\\\\\\\\\\///\\\\\\___/\\\\\\/////\\\\\\____\\/\\\\\\____\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\__  \n");
    printf("     _\\//\\\\\\______________/\\\\\\\\\\\\\\\\\\\\__\\/\\\\\\_\\//\\\\\\__\\/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\_____\\/\\\\\\____\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\//////___  \n");
    printf("      __\\///\\\\\\___________/\\\\\\/////\\\\\\__\\/\\\\\\__\\/\\\\\\__\\/\\\\\\_\\//\\\\///////______\\/\\\\\\____\\//\\\\\\______/\\\\\\__\\/\\\\\\_________  \n");
    printf("       ____\\////\\\\\\\\\\\\\\\\\\_\\//\\\\\\\\\\\\\\\\/\\\\_\\/\\\\\\__\\/\\\\\\__\\/\\\\\\__\\//\\\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\__\\///\\\\\\\\\\\\\\\\\\/___\\/\\\\\\_________  \n");
    printf("        _______\\/////////___\\////////\\//__\\///___\\///___\\///____\\//////////__\\/////////_____\\/////////_____\\///__________  \n");


    printf("\n\n\n\n");

    printf("\tAppuyez sur une touche pour continuer...");
    getchar();

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Dans cette version de CamelUp, vous n'interagissez qu'avec des nombres\n");
    printf("\nAppuyez sur une touche pour continuer...");
    getchar();

    printf("\nLes chameaux sont chacuns representes par un numero\nLes tuiles mirages par un 1 et les tuiles oasis par un 2");
    printf("\nAppuyez sur une touche pour continuer...");
    getchar();

    int nombre;     //nombre de joueurs
    printf("\nCombien de joueurs etes-vous ?");
    scanf("%d", &nombre);
    while(nombre<1)
    {
        printf("\nPetit malin... Entre un nombre superieur à 0");
        scanf("%d", &nombre);
    }

    printf("\nAppuyez sur une touche pour commencer la partie...");
    getchar();

    return nombre;
}
