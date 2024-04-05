int pinos[8] = {16,5,4,14,12,13,0,2};

int converterBinario(int num, int vet[]){
  int bin[8];
  int aux;
  int cont1 = 0;
  int contVet = 0;
  
  for(aux = 7; aux >= 0; aux--){
    if(num != 0){
      if(aux >= 1 ) {
        if(num % 2 == 0){
            bin[aux] = 0;
        }else{
            bin[aux] = 1;
            cont1++;
        }
        num = num / 2;
        contVet++;
      }
    }
  }
  
  for (aux = 1; aux <= 7; aux++){
       if(bin[1] == 2 && aux < 7){
         vet[aux] = bin[aux + 1];
       }else{
          vet[aux] = bin[aux];
       }
  }
  
  if(contVet <= 6){
    Serial.println(contVet);
    vet[7] = 0;
  }

  if((cont1 % 2) == 0){
  	  vet[0] = 0;
    	Serial.println(cont1);
  }else{
  	  vet[0] = 1;
    Serial.println(cont1);
  }

}

void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0){
  	char var = Serial.read();
    Serial.println(var);
    Serial.println(int(var));
    int vet[8];
    converterBinario(int(var), vet);
    for (int aux = 0; aux <= 7; aux++){
          Serial.print(vet[aux]);
          digitalWrite(pinos[aux],vet[aux]);
    }
    
    Serial.println("");
  }
}
