#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int year, months, days;
	long hours, minutes, seconds;
	
	printf("Donner le nombre d`annees: ");
	scanf("%d", &year);
	
	months = year * 12;
	days = year * 365;
	hours = days * 24;
	minutes = hours * 60;
	seconds = minutes * 60;
	
    printf("\nConversion pour %d année(s):\n", year);
    printf("Mois: %d\n", months);
    printf("Jours: %d\n", days);
    printf("Heures: %ld\n", hours);
    printf("Minutes: %ld\n", minutes);
    printf("Secondes: %ld\n", seconds);
	return 0;
}
