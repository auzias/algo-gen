#include "util.h"

void exit_error (const char *msg, const int err_num)
{
    fprintf (stderr, ANSI_RED);
    fprintf (stderr, msg);
    fprintf (stderr, ANSI_RESET);
    fprintf (stderr, "\n");
    exit (err_num);
}

void message (const char *msg)
{
    fprintf (stdout, ANSI_GREEN);
    fprintf (stdout, msg);
    fprintf (stdout, ANSI_RESET);
    fprintf (stdout, "\n");
}

void fill_coordinates (int coordinates[NUMBER_OF_TOWNS][2])
{
  int i = 0;
  coordinates[i][0] = 35;
  coordinates[i++][1] = 130;
  coordinates[i][0] = 65;
  coordinates[i++][1] = 108;
  coordinates[i][0] = 99;
  coordinates[i++][1] = 388;
  coordinates[i][0] = 112;
  coordinates[i++][1] = 127;
  coordinates[i][0] = 116;
  coordinates[i++][1] = 197;
  coordinates[i][0] = 120;
  coordinates[i++][1] = 149;
  coordinates[i][0] = 125;
  coordinates[i++][1] = 250;
  coordinates[i][0] = 128;
  coordinates[i++][1] = 72;
  coordinates[i][0] = 128;
  coordinates[i++][1] = 276;
  coordinates[i][0] = 139;
  coordinates[i++][1] = 320;
  coordinates[i][0] = 145;
  coordinates[i++][1] = 402;
  coordinates[i][0] = 165;
  coordinates[i++][1] = 99;
  coordinates[i][0] = 178;
  coordinates[i++][1] = 234;
  coordinates[i][0] = 187;
  coordinates[i++][1] = 196;
  coordinates[i][0] = 207;
  coordinates[i++][1] = 391;
  coordinates[i][0] = 208;
  coordinates[i++][1] = 274;
  coordinates[i][0] = 214;
  coordinates[i++][1] = 88;
  coordinates[i][0] = 226;
  coordinates[i++][1] = 139;
  coordinates[i][0] = 241;
  coordinates[i++][1] = 111;
  coordinates[i][0] = 252;
  coordinates[i++][1] = 14;
  coordinates[i][0] = 253;
  coordinates[i++][1] = 414;
  coordinates[i][0] = 255;
  coordinates[i++][1] = 64;
  coordinates[i][0] = 256;
  coordinates[i++][1] = 212;
  coordinates[i][0] = 260;
  coordinates[i++][1] = 443;
  coordinates[i][0] = 264;
  coordinates[i++][1] = 33;
  coordinates[i][0] = 284;
  coordinates[i++][1] = 286;
  coordinates[i][0] = 291;
  coordinates[i++][1] = 182;
  coordinates[i][0] = 295;
  coordinates[i++][1] = 397;
  coordinates[i][0] = 315;
  coordinates[i++][1] = 388;
  coordinates[i][0] = 318;
  coordinates[i++][1] = 105;
  coordinates[i][0] = 335;
  coordinates[i++][1] = 378;
  coordinates[i][0] = 336;
  coordinates[i++][1] = 284;
  coordinates[i][0] = 341;
  coordinates[i++][1] = 254;
  coordinates[i][0] = 355;
  coordinates[i++][1] = 412;
  coordinates[i][0] = 358;
  coordinates[i++][1] = 183;
  coordinates[i][0] = 370;
  coordinates[i++][1] = 315;
  coordinates[i][0] = 371;
  coordinates[i++][1] = 422;
  coordinates[i][0] = 378;
  coordinates[i++][1] = 207;
  coordinates[i][0] = 382;
  coordinates[i++][1] = 112;
  coordinates[i][0] = 384;
  coordinates[i++][1] = 287;
  coordinates[i][0] = 386;
  coordinates[i++][1] = 133;
  coordinates[i][0] = 386;
  coordinates[i++][1] = 268;
  coordinates[i][0] = 417;
  coordinates[i++][1] = 169;
  coordinates[i][0] = 433;
  coordinates[i++][1] = 387;
  coordinates[i][0] = 435;
  coordinates[i][1] = 136;
}

void fill_names (char** town_names)
{
  int i = 0;
  town_names[i++] = "Brest";
  town_names[i++] = "Perros-Guirec";
  town_names[i++] = "Biarritz";
  town_names[i++] = "St-Malo";
  town_names[i++] = "Nantes";
  town_names[i++] = "Rennes";
  town_names[i++] = "La-Rochelle";
  town_names[i++] = "Cherbourg";
  town_names[i++] = "Royan";
  town_names[i++] = "Bordeaux";
  town_names[i++] = "Pau";
  town_names[i++] = "Caen";
  town_names[i++] = "Poitiers";
  town_names[i++] = "Tours";
  town_names[i++] = "Toulouse";
  town_names[i++] = "Limoges";
  town_names[i++] = "Rouen";
  town_names[i++] = "Chartres";
  town_names[i++] = "Paris";
  town_names[i++] = "Calais";
  town_names[i++] = "Carcassonne";
  town_names[i++] = "Amiens";
  town_names[i++] = "Bourges";
  town_names[i++] = "Perpignan";
  town_names[i++] = "Lille";
  town_names[i++] = "Clermont-Ferrand";
  town_names[i++] = "Auxerre";
  town_names[i++] = "Montpellier";
  town_names[i++] = "Nîmes";
  town_names[i++] = "Reims";
  town_names[i++] = "Avignon";
  town_names[i++] = "Lyon";
  town_names[i++] = "Mâcon";
  town_names[i++] = "Marseille";
  town_names[i++] = "Dijon";
  town_names[i++] = "Grenoble";
  town_names[i++] = "Toulon";
  town_names[i++] = "Besançon";
  town_names[i++] = "Metz";
  town_names[i++] = "Chambéry";
  town_names[i++] = "Nancy";
  town_names[i++] = "Annecy";
  town_names[i++] = "Colmar";
  town_names[i++] = "Nice";
  town_names[i] = "Strasbourg";
}
