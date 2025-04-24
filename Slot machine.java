import java.util.Random;
import java.util.Scanner;
public class slot {

    public static void main(String[] args) {

        //welcome to slot machine
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        System.out.println("*********************");
        System.out.println("Welcome to slot game");
        System.out.println("*********************");

        String options [] =  { " 🍭", "🥩","🥚","🧈","🥟"};
        String num [] = new String [3];
        int amount = 100;
        int bet;


        //declare a string of array with special characters
        //prompts



        // for loops/ while loops



               while(amount > 0 ) {
                   System.out.print("Enter how much you want to bet:");
                   bet = scanner.nextInt();
                   if (bet > amount) {
                       System.out.println("Insufficent funds");
                       continue;
                   } else if (bet <= 0) {
                       System.out.println("Cant be less than 0");
                       continue;
                   } else {
                       amount -= bet;
                       System.out.println("balacnce is $" + amount);
                   }
                   for(int i =0;i < 3; i++){
                       num[i] = options[random.nextInt(options.length)];
                       System.out.print(num[i]);}
                       if ( num[0].equals(num[1] ) || num[1].equals(num[2])){
                           switch(num[0]){
                               case "🍭" -> bet=  bet * 10;
                               case "🥩" -> bet = bet *2;
                               case "🥚" -> bet = bet *3;
                               case "🧈"-> bet = bet *5;
                               case "🥟" -> bet= bet*20;
                               default -> bet+= 0;

                           }
                           amount +=bet;
                       }
                   }