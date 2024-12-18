import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int lottery = (int)(Math.random() * 900) + 100;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your lottery pick (three digits): ");
        int userInput = scanner.nextInt();

        int lotteryDigit1 = lottery / 100;
        int lotteryDigit2 = (lottery / 10) % 10;
        int lotteryDigit3 = lottery % 10;

        int userDigit1 = userInput / 100;
        int userDigit2 = (userInput / 10) % 10;
        int userDigit3 = userInput % 10;

        System.out.println("Lottery is " + lottery);

        if (userInput == lottery) {
            System.out.println("Exact match: you win $10,000");
        } else if ((userDigit1 == lotteryDigit1 || userDigit1 == lotteryDigit2 || userDigit1 == lotteryDigit3) &&
                (userDigit2 == lotteryDigit1 || userDigit2 == lotteryDigit2 || userDigit2 == lotteryDigit3) &&
                (userDigit3 == lotteryDigit1 || userDigit3 == lotteryDigit2 || userDigit3 == lotteryDigit3)) {
            System.out.println("Match all digits: you win $3,000");
        } else if (userDigit1 == lotteryDigit1 || userDigit1 == lotteryDigit2 || userDigit1 == lotteryDigit3 ||
                userDigit2 == lotteryDigit1 || userDigit2 == lotteryDigit2 || userDigit2 == lotteryDigit3 ||
                userDigit3 == lotteryDigit1 || userDigit3 == lotteryDigit2 || userDigit3 == lotteryDigit3) {
            System.out.println("Match one digit: you win $1,000");
        } else {
            System.out.println("Sorry, no match");
        }

        scanner.close();
    }
}
