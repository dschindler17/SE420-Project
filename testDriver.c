#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eagleEye.h"
#define TESTOPTIONSFR "\n1: Acceptance Test ai (FR1-Standard Read/Write)\n2: Acceptance Test aii (FR2-Gray-Scale Transform)\n3: Acceptance Test aiii (FR3/4-Blur Transform)\n4: Acceptance Test [NOT INCLUDED] aiv (FR6-Edge-Detection)\n"
#define TESTOPTIONSPR "5: Acceptance Test bi (PR1-Read Latency)\n6: Acceptance Test bii (PR2-Standard Transform Latency)\n7: Acceptance Test biii [NOT INCLUDED](PR3-Edge-Detection Latency)\n8: Acceptance Test [NOT INCLUDED] biv (PR5 CPU Usage)\n"
#define TESTOPTIONSEUR "9: Acceptance Test ci (EUR1-Invalid Location)\n10: Acceptance Test cii (EUR2-Incompatible Type)\n11: Acceptance Test [NOT INCLUDED] ciii (EUR3-Open Preview)\n12: Acceptance Test  civ (EUR4-Pipeline)\n"

int main()
{
  char menuOption;
  char frOptions[sizeof(TESTOPTIONSFR)] = TESTOPTIONSFR, prOptions[sizeof(TESTOPTIONSPR)] = TESTOPTIONSPR, eurOptions[sizeof(TESTOPTIONSEUR)] = TESTOPTIONSEUR;
  printf("Please select which test you would like to perform.");
  printf("%s%s%s",frOptions, prOptions, eurOptions);
  printf("\nSelection: ");
  scanf(" %d", &menuOption);
  switch (menuOption){
    case 1:
      readWriteTest();
	  break;
    case 2:
      grayTest();
	  break;
    case 3:
      blurTest();
	  break;
    case 4:
      //Edge-Detection Test
	  break;
    case 5:
      readLatencyTest();
	  break;
    case 6:
      transformLatencyTest();
	  break;
    case 7:
      //Edge-Detection Latency Test
	  break;
    case 8:
      //CPU Usage Test
	  break;
    case 9:
      invalidLocation();
	  break;
    case 10:
      invalidType();
	  break;
    case 11:
      //Open Preview Test
	  break;
    case 12:
      pipeTest();
	  break;
	default:
	  printf("\nIncorrect Input.\n");
    }
}