const int led_vermelho = 5;			//
const int led_verde = 6;			//
const int led_amarelo = 7;			//
char led;					//

void setup() {
  pinMode(led_vermelho, OUTPUT);		//
  pinMode(led_verde, OUTPUT);			//
  pinMode(led_amarelo, OUTPUT);			//
  Serial.begin(115200); 			// Definição da velocide de transmissão em 115200 bps
}

void loop() {
  if (Serial.available()) {			//
    led = Serial.read();			//
    if(led == 'R') { 				// Led vermelho - red
      digitalWrite(led_vermelho, HIGH); 	// Acende led
    }
    else if(led == 'r') { 				// Led vermelho - red
      digitalWrite(led_vermelho, 0); 	// Apaga led
    }
    if (led == 'G') { 				// Led verde - green
      digitalWrite(led_verde, HIGH); 		// Acende led
      }
    else if (led == 'g') { 				// Led verde - green
      digitalWrite(led_verde, 0); 		// Apagae led
    }
    if (led == 'Y') { 				// Led amarelo - yellow
      digitalWrite(led_amarelo, HIGH); 		// Acende led
      }
    else if (led == 'y') { 				// Led amarelo - yellow
      digitalWrite(led_amarelo, 0); 		// Apaga led
    }
    if (led == 'T') { 				// Led todos - yellow
      digitalWrite(led_verde, HIGH); 		// Acende led
      digitalWrite(led_vermelho, HIGH); 		// Acende led
      digitalWrite(led_amarelo, HIGH); 		// Acende led
      }
    else if (led == 't') { 				// Led amarelo - yellow
      digitalWrite(led_verde, 0); 		// Apaga led
      digitalWrite(led_vermelho, 0); 		// Apaga led
      digitalWrite(led_amarelo, 0); 		// Apaga led
    }
  }
}
