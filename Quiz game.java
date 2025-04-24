import java.util.Scanner;

public class quiz {

    public static void main(String [] args){


        //Quiz
        String [] questions = {" What is the main function of a piston?",
                "What year was the b58 created?",
                "what is the main fualt with a n54?" ,
                "what is the mosty bought bmw today?"};
        String [][] options = {{"1. asthetics" , "2. giving fuel to the motor", "3. combusting the fule", "4. for fun " },
                                 {"1.2000","2.2004","3.2016", "4.2025"},
                                    {"1.injectors","2.piston rings","3.valve cover gaskets", "4.everything"},
                                        {"1.bmw 328i","2.nmw 335i","3.bmw 330i", "4.bmw m340i"}};
        //array prompt
        //2d array choices
        // variables
        int [] rightAnswer= {3,3,4,4};
        int score = 0;
        int guess;
        Scanner scanner = new Scanner(System.in);
        System.out.println("**************************");
        System.out.println("Welcome to the guessing game");
        System.out.println("***************************");

        // welcome message
        //user imput
        //for loops
        for(int i =0;i<questions.length;i++){
            System.out.println(questions[i]);
            for( String option:options[i]){
                System.out.println(option);
            }
            System.out.println("enter your guess");
            guess= scanner.nextInt();

            if(guess == rightAnswer[i]){
                System.out.println("**************");
                System.out.println("Correct");
                System.out.println("************");;
                score++;
            }
            else{
                System.out.println("Wrong");
            }
        }
        System.out.println(score);
        scanner.close();
    }
}




              