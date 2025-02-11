use std::io;

fn solve(n: i64) {
    if n > 14 && (n % 14 >= 1 && n % 14 <= 6) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    let mut numbers = String::new();
    io::stdin().read_line(&mut numbers).unwrap();
    let nums: Vec<i64> = numbers
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    for &n in &nums {
        solve(n);
    }
    // let t: usize = input.trim().parse().unwrap();
    // for _ in 0..t {
    //     let n: usize = input.trim().parse().unwrap();
    //     solve();
    // }
}
