#include<stdio.h>

//Function declaration for GCV
float gcv(float, float, float, float);

//Function declaration for NCV
float ncv(float, float, float);

void main(){
    printf("This is a calculator for Gross Calorific Value (GCV) and Net Calorific Value (NCV)\nEnter the percentage value of the elements in the given fuel\n");
    float carbon, hydrogen, oxygen, sulphur, latentHeat = 587, GCV;
    printf("Carbon: ");
    scanf("%f", &carbon);
    printf("Hydrogen: ");
    scanf("%f", &hydrogen);
    printf("Oxygen: ");
    scanf("%f", &oxygen);
    printf("Sulphur: ");
    scanf("%f", &sulphur);
    printf("Latent Heat of condensation of steam (default: 587 cal/g): ");
    scanf("%f", &latentHeat);
    GCV = gcv(carbon, hydrogen, oxygen, sulphur);  //function call
    printf("Gross Calorific Value (GCV) = %.2f kcal/kg\n", GCV);
    printf("Net Calorific Value (NCV) = %.2f kcal/kg\n", ncv(GCV, hydrogen, latentHeat));
}

//Function definition for GCV
float gcv(float carbon, float hydrogen, float oxygen, float sulphur){
    return (8080*carbon+34500*(hydrogen-oxygen/8)+2240*sulphur)/100;
}

//Function definition for NCV
float ncv(float GCV, float hydrogen, float latentHeat){
    return GCV-9*hydrogen*latentHeat/100;
}