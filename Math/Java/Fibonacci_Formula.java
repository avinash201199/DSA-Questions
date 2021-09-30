package com.aniket;

public class Fibonacci {
    public static void main(String[] args) {

        System.out.println(fiboFormula(50));
    }

    // Also run for bigger numbers
    static int fiboFormula(int n) {
        // just for demo, use long instead
        return (int) (Math.pow(((1 + Math.sqrt(5)) / 2), n) / Math.sqrt(5));
    }

    // not run for bigger numbers

    // static int fibo(int n) {
    // // base condition
    // if (n < 2) {
    // return n;
    // }
    // return fibo(n-1) + fibo(n-2);
    // }
}