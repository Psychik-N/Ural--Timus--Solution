#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define PI 3.1415926535897932384626433

int lat1, lat2, lat3, lon1, lon2, lon3, trash;
char latc, lonc;

long double latf, lats, lonf, lons;
long double sq(double x){
return x*x;
}

int main(void){
scanf("Message #%d.\nReceived at %d:%d:%d.\nCurrent ship's coordinates are\n%d^%d'%d\" %cL\nand %d^%d'%d\" %cL.\n",
&trash, &trash, &trash, &trash, &lat1, &lat2, &lat3, &latc, &lon1, &lon2, &lon3, &lonc);
lats = (latc=='N'?1:-1)*(lat1 + (lat2 + lat3/60.0)/60.0)*PI/180.0;
lons = (lonc=='W'?-1:1)*(lon1 + (lon2 + lon3/60.0)/60.0)*PI/180.0;


scanf("An iceberg was noticed at\n%d^%d'%d\" %cL\nand %d^%d'%d\" %cL.",
&lat1, &lat2, &lat3, &latc, &lon1, &lon2, &lon3, &lonc);
latf = (latc=='N'?1:-1)*(lat1 + (lat2 + lat3/60.0)/60.0)*PI/180.0;
lonf = (lonc=='W'?-1:1)*(lon1 + (lon2 + lon3/60.0)/60.0)*PI/180.0;

double dlon = lonf - lons, dlat = latf - lats;

double a = acos(sin(lats)*sin(latf) + cos(lats)*cos(latf)*cos(dlon));
double len = 3437.5*a;
printf("The distance to the iceberg: %.2lf miles.\n", len);
if(100.00-len>0.005)
printf("DANGER!\n");
return 0;
}
