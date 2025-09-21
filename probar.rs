fn f(n: i32) -> i32 {
    if n <= 1 {
        return 1;
    } else {
        return n * f(n - 1);
    }
}
