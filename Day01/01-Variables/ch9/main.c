#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x1, y1 , z1;
	int x2, y2, z2;
	int distance;
	
	printf("enter les cordonnes du 1er point (m): ");
	scanf("%d %d %d", &x1, &y1 , &z1);
	printf("enter les cordonnes du 2eme point (m): ");
	scanf("%d %d %d", &x2, &y2, &z2);
	
	distance = sqrt(pow(x2 - x1 , 2) + pow(y2 - y1, 2) + pow(z2- z1, 2));
	printf("la distance est: %d m", distance);
	
	return 0;
}
