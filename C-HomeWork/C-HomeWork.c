#include <stdio.h>
#include <stdlib.h>
#include <time.h> //import time library 




	int randomnumber(int *d); //decleration of randomnumber function
		

	void running_game(int *attempt, int input, int *answer); //decleration of running_game function

	
		

	int main() //functions begin main program execution
	{	
		int restart; // integer variable that start game
		printf("Do you wish to start game [Y = 1/ N = 0]:");
		scanf("%d",&restart); // get restart value from user
		char term1, term2; /* two char variables using for controling scanf function inputs */ 
		int max_value; // integer variable that using for games maximum value
		int input; // integer variable that store user's inputs
		int attempt_count = 0; /* integer variable that store user's attemps */
		srand(time(0)); // execute srand function which changes rand() functions variables when program first time executed

			if(restart == 0){ // condition that control restart value if it is zero program print "Thank you goodbye"
			printf("\nThank you goodbye.");
			
		}
			
				
			
				
			while(restart != 0) // while loop running game if user start game and restart game 
			{
	

		printf("Please give a maximum range value:\n"); // print "Please give a maximum range value:"

			if(scanf("%d%c",&max_value,&term1) != 2 || term1 != '\n'){ /* if condition that check max_value input if user input's char or more than one integer program will be terminated */
				printf("Sorry I cannot execute that program because you entered non-integer value next time please give me an integer.\n\a");
				return -1; // indicates unsuccesful termination program does not be executed after this line
				
			}

		int a = randomnumber(&max_value); // initialize integer a to randomnumber() output and integer a is correct answer

			printf("Please give your answer:\n");

				if (scanf("%d%c",&input,&term2) != 2 || term2 != '\n') /* if condition that check input input if user input's char or more than one integer program will be terminated */
				{
					printf("Sorry I cannot execute that program because you entered non-integer value next time please give me an integer.\n\a");
					return -1; // indicates unsuccesful termination program does not be executed after this line
				}
					

					if (input > max_value) /* if condition that check user's input if input variable greater than max_value program print "Your input value will not be greater than maximum value."
					and program get another input value from user */ 
					{
						printf("Your input value will not be greater than maximum value.\n\a");
						input = 0; // change input variables value to 0
					scanf("%d",&input); // get another input value
					}
						

					if(input == a){ /* if condition that compare input value and a value if input value equal to a value than program print "Congratulations you have won only one attempt." */
						printf("Congratulations you have won only one attempt.\n");
					}
						else if(a != input){ /* if input value not equal to a value  program runs running_game function */
					
							running_game(&attempt_count, input, &a);

							}
						


						printf("Do you want to restart game [Y = 1/ N = 0]:");
					    scanf("%d",&restart);
						if (restart == 0)
						{	
							printf("Thank you goodbye.\n");						
						} 
						
						}
					

					return 0; // indicates successful termination
	}


	int randomnumber(int *d){ /* function generate random value between [0,max_value] */
		 int j = rand()%(*d + 1); // initialize integer j value to random number between [0,max_value]
			return j;


	}


	void running_game(int *attempt, int input, int *answer){ /* function running game */
		
				do{ /* do - while loop until input equal to *answer */
					if (input - *answer > 10) // condition checks inputs - answer if input - answer greater than 10 print "Your input is far greater than my value." and increase value *attempt
					{
						printf("Your input is far greater than my value.\n");
						scanf("%d",&input);
						(*attempt)++;
					}
					if (input - *answer < 10 && input - *answer > 0) // condition checks inputs - answer if input - answer lesser than 10 and greater than 0 print "Your input is input - *answer greater than my value." and increase value *attempt
					{
						printf("Your input is %d greater than my value.\n",input - *answer);
						scanf("%d",&input);
						(*attempt)++;
					}
					if (*answer - input > 10) // condition checks inputs - answer if answer - input greater than 10 print "Your input is far greater than my value." and increase value *attempt
					{
						printf("Your input is far lesser than my value.\n");
						scanf("%d",&input);
						(*attempt)++;
					}
					if (*answer - input <10 && *answer - input > 0) // condition checks inputs - answer if answer - input lesser than 10 and greater than 0 print "Your input is *answer - input lesser than my value." and increase value *attempt
					{
						printf("Your input is %d lesser than my value.\n",*answer - input );
						scanf("%d",&input);
						(*attempt)++;
					}
					if (*answer == input) /* if condition checks *answer equal to input if it is print "Congratulations you have won in *attempt attempt." */
					{
						printf("Congratulations you have won in %d attempt.\n",*attempt);
					}
				}while(input != *answer);
	}
			

