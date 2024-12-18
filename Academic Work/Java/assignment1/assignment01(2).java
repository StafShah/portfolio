
public class Main {
    public static void main(String[] args) {
        int population = 312032486;
        int secondsInYear = 31536000;
        for (int i = 1; i < 6; i++) {
            population += (secondsInYear / 7) + (secondsInYear / 45) - (secondsInYear / 13);
            System.out.println("Year " + i + ": " + population);
        }
    }
}