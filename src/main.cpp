//Oliver Olsen s205443
//Nils Wulff   s223968

// 14a A member is a variable inside the struct
// 14b  The "struct.memeber" is the value of the member from the struct
// "*(struct).member" and "*struct.member" does more or less the same.
// They both get the value of the member, but the () is a more robust way of the expressin
// potentially preventing future errors.
// "struct->member" can acces function inside the struct
// 14c Struct Animal is created
// 14d
// 14e
// 14f



#include <Arduino.h>

struct Animals
  {
    String    family;
    float     weight;
    bool      alive;
    String    loc_cap;
    String    species;
  };


void printAnimals(struct Animals animal);
void swapWeight(struct Animals *animal_1, struct Animals *animal_2);


void setup() {
  Serial.begin(9600);
  


  struct Animals Hawk;
  Hawk.family = "Accipitridae";
  Hawk.weight =  1.2;
  Hawk.alive  = true;  
  Hawk.loc_cap = "Alberta - Canada";
  Hawk.species = "Buteo Jamaicensis";


  struct Animals Goat;
  Goat.family = "Bovidae";
  Goat.weight =  102.45;
  Goat.alive  = true;  
  Goat.loc_cap = "British Virgin Islands";
  Goat.species = "Capra Aegagrus Hircus";

  
  struct Animals Orca;
  Orca.family = "Bovidae";
  Orca.weight =  3578.68;
  Orca.alive  = false;  
  Orca.loc_cap = "Seaworld - Orlando";
  Orca.species = "Orcinus orca";

    Serial.println("Hawk:");
    printAnimals(Hawk);
    Serial.println();
    Serial.println();

    Serial.println("Goat:");
    printAnimals(Goat);
    Serial.println();
    Serial.println();

    Serial.println("Orca:");
    printAnimals(Orca);
    Serial.println();
    Serial.println();



    swapWeight(&Orca, &Hawk);


    Serial.println("Swapped Weight");
    Serial.println("Hawk:");
    printAnimals(Hawk);
    Serial.println();
    Serial.println();
    
    
    Serial.println("Orca:");
    printAnimals(Orca);
    Serial.println();
    Serial.println();

  
  

}

void loop() {
  
}



/**
 * @brief Prints the incoming animals corrosponding data
 * 
 * @param animal Info for the animal
 */
void printAnimals(struct Animals animal){
  Serial.println(animal.family);
  Serial.println(animal.weight);
  Serial.println(animal.alive);
  Serial.println(animal.loc_cap);
  Serial.println(animal.species);
}



/**
 * @brief Swaps the weight between two animals
 * 
 * @param animal_1 
 * @param animal_2 
 */
void swapWeight(struct Animals *animal_1, struct Animals *animal_2){
  float cache;

  // Briefly stores the weight of animal_1
  cache = animal_1 -> weight;

  animal_1 -> weight = animal_2 ->weight;
  animal_2 -> weight = cache;
  
}