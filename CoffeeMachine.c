package machine;

import java.util.Scanner;

public class CoffeeMachine {
     static int dollar = 550;
    static int water = 400;
    static int milk = 540;
    static int beans  = 120;
    static int cups = 9;

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Write action (buy, fill, take, remaining, exit):");
            String input = scanner.nextLine();
            if (input.equals("buy")) {
                Buy();
            } else if (input.equals("fill")) {
                Fill();
            } else if (input.equals("take")) {
                Take();
            } else if (input.equals("remaining")) {
                Left();
            } else if (input.equals("exit"))
                break ;
        }
    }

    private static void Left() {
        System.out.println();
        System.out.println("The coffee machine has:");
        System.out.println(water + " ml of water");
        System.out.println(milk + " ml of milk");
        System.out.println(beans + " g of coffee beans");
        System.out.println(cups + " disposable cups");
        System.out.println("$" + dollar + " of money");
    }

    private static void Take() {
        System.out.println("I gave you $" + dollar);
        dollar -= dollar;
    }

    private static void Fill() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Write how many ml of water you want to add: ");
        int add = scanner.nextInt();
        water += add;
        System.out.println("Write how many ml of milk you want to add: ");
        add = scanner.nextInt();
        milk += add;
        System.out.println("Write how many grams of coffee beans you want to add:");
        add = scanner.nextInt();
        beans += add;
        System.out.println("Write how many disposable cups of coffee you want to add:");
        add = scanner.nextInt();
        cups += add;
    }

    private static String check(int num, int water_n, int milk_n, int beans_n, int cups_n) {
            if (water - water_n >= 0 && beans - beans_n >= 0 && cups - cups_n >= 0) {
                return (null);
            }
            else {
                if (water - water_n < 0) {
                    return ("water");
                }
                else if (beans - beans_n < 0) {
                    return ("coffee beans");
                }
                else if (cups - cups_n < 0) {
                    return ("disposable cups");
                }
                else if (milk_n - milk < 0) {
                    return ("milk");
                }
            }
            return (null);
    }

    private static void Buy() {
        System.out.println("What do you want to buy? 1 - espresso, 2 - latte, 3 - cappuccino: ");
        Scanner scanner = new Scanner(System.in);
        String s;
        var num = scanner.nextLine();
        if (num.equals("back")) {
            return ;
        }
        if (Integer.parseInt(num) == 1) {
            s = check(1, 250, 0, 16, 1);
            if (s == null) {
                water -= 250;
                beans -= 16;
                dollar += 4;
                cups -= 1;
                System.out.println("I have enough resources, making you a coffee!");
            }
            else {
                System.out.println("Sorry, not enough " + s + "!");
            }
        }
        else if (Integer.parseInt(num) == 2) {
            s = check(2, 350, 75, 7, 1);
            if (s == null) {
                water -= 350;
                milk -= 75;
                beans -= 20;
                dollar += 7;
                cups -= 1;
                System.out.println("I have enough resources, making you a coffee!");
            }
            else {
                System.out.println("Sorry, not enough " + s + "!");
            }
        }
        else if (Integer.parseInt(num) == 3) {
            s = check(3, 200, 100, 12, 1);
            if (s == null) {
                water -= 200;
                milk -= 100;
                beans -= 12;
                dollar += 6;
                cups -= 1;
                System.out.println("I have enough resources, making you a coffee!");
            }
            else {
                System.out.println("Sorry, not enough " + s + "!");
            }
        }
} }
